#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>

#include "tp.h"
#include "tp_y.h"

extern int yyparse();
extern int yylineno;

/* Niveau de 'verbosite'.
 * Par defaut, n'imprime que le resultat et les messages d'erreur
 */
bool verbose = FALSE;

/* Generation de code ou pas. Par defaut, on produit le code */
bool noCode = FALSE;

/* Pose de points d'arret ou pas dans le code produit */
bool debug = FALSE;

/* code d'erreur a retourner */
int errorCode = NO_ERROR;

/* Evaluation ou pas. Par defaut, on evalue les expressions */
bool noEval = FALSE;

FILE *out; /* fichier de sortie pour le code engendre */


int main(int argc, char **argv)
{
	
	
  int fi;
  int i, res;

  out = stdout;
  for(i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
      case 'd': case 'D':
	debug = TRUE; continue;
      case 'v': case 'V':
	verbose = TRUE; continue;
      case 'e': case 'E':
	noCode = TRUE; continue;
      case '?': case 'h': case 'H':
	fprintf(stderr, "Appel: tp -v -e -d -o file.out programme.txt\n");
	exit(USAGE_ERROR);
      case'o':
	  if ((out= fopen(argv[++i], "w")) == NULL) {
	    fprintf(stderr, "erreur: Cannot open %s\n", argv[i]);
	    exit(USAGE_ERROR);
	  }
	break;
      default:
	fprintf(stderr, "Option inconnue: %c\n", argv[i][1]);
	exit(USAGE_ERROR);
      }
    } else break;
  }

  if (i == argc) {
    fprintf(stderr, "Fichier programme manquant\n");
    exit(USAGE_ERROR);
  }

  if ((fi = open(argv[i++], O_RDONLY)) == -1) {
    fprintf(stderr, "erreur: Cannot open %s\n", argv[i-1]);
    exit(USAGE_ERROR);
  }

  /* redirige l'entree standard sur le fichier... */
  close(0); dup(fi); close(fi);

  res = yyparse();
  if (out != NIL(FILE) && out != stdout) fclose(out);
  return res ? SYNTAX_ERROR : errorCode;
}


void setError(int code)
{
  errorCode = code;
  if (code != NO_ERROR) { noCode = TRUE; /*  abort(); */}
}


/* yyerror:  fonction importee par Bison et a fournir explicitement. Elle
 * est appelee quand Bison detecte une erreur syntaxique.
 * Ici on se contente d'un message minimal.
 */
void yyerror(char *ignore) {
  printf("erreur de syntaxe: Ligne %d\n", yylineno);
  setError(SYNTAX_ERROR);
}


/* Tronc commun pour la construction d'arbre */
TreeP makeNode(int nbChildren, short op) {
  TreeP tree = NEW(1, Tree);
  tree->op = op;
  tree->nbChildren = nbChildren;
  tree->u.children = nbChildren > 0 ? NEW(nbChildren, TreeP) : NIL(TreeP);
  return(tree);
}


/* Construction d'un arbre a nbChildren branches, passees en parametres */
TreeP makeTree(short op, int nbChildren, ...)
{
	va_list args;
	int i;
	TreeP tree = makeNode(nbChildren, op);
	va_start(args, nbChildren);
	for (i = 0; i < nbChildren; i++) {
	tree->u.children[i] = va_arg(args, TreeP);
	}
	va_end(args);
	return(tree);
}




/* Retourne le rankieme fils d'un arbre (de 0 a n-1) */
TreeP getChild(TreeP tree, int rank) {
  if (tree->nbChildren < rank -1) {
    fprintf(stderr, "Incorrect rank in getChild: %d\n", rank);
    abort();
  }
  return tree->u.children[rank];
}


void setChild(TreeP tree, int rank, TreeP arg) {
  if (tree->nbChildren < rank -1) {
    fprintf(stderr, "Incorrect rank in getChild: %d\n", rank);
    abort();
  }
  tree->u.children[rank] = arg;
}


/* Constructeur de feuille dont la valeur est une chaine de caracteres */
TreeP makeLeafStr(short op, char *str) {
  TreeP tree = makeNode(0,op);
  tree->u.str = str;
  return tree;
}

/* Constructeur de feuille dont la valeur est un entier */
TreeP makeLeafInt(short op, int val) {
  TreeP tree = makeNode(0, op) ;
  tree->u.val = val;
  return(tree);
}
/* Constructeur feuille dont la valeur est une variable */
TreeP makeLeafLVar(short op, VarDeclP lvar) {
  TreeP tree = makeNode(0, op) ;
  tree->u.lvar = lvar;
  return(tree);
}

/* Remplissage */
VarDeclP makeVarDecl(char *name, char *type, TreeP expr) {
	VarDeclP nouveau = NEW(1, VarDecl);
	nouveau->name = name;
	nouveau->varType = type;
	nouveau->expr = expr;
	nouveau->next = NIL(VarDecl);
	return(nouveau);
}

TreeP makeBlock(VarDeclP var, TreeP inst)
{
	TreeP tree = makeNode(2, BLOCK);
	tree->u.children[0] = makeLeafLVar(DECL, var);
	tree->u.children[1] = inst;
	return(tree);
}

MethodP makeMeth(char* name, VarDeclP args) {
	MethodP nouv = NEW(1, Method);
	nouv->name = name;
	nouv->args = args;
	return nouv; 
}

MethodP fillMeth(MethodP meth, TreeP bloc, bool over){
	meth->type=bloc->u.children[0]->u.str;
	meth->body=bloc->u.children[1];
	meth->over=over;
	return meth;
}

ClassP fillClass(ClassP class, char* super, TreeP bloc){
	class->super = super;
	MethodP tampon = makeMeth(class->name, class->var);
	class->constructor = fillMeth(tampon, bloc, FALSE);
	return class;
}

TeteP makeTete(char* nom, VarDeclP var)
{
    TeteP tete = NEW(1, Tete);
    tete->type = nom;
    tete->var = var;
    return(tete);
}

ClassP makeClass(TeteP tete, char* super, TreeP bloc){
	ClassP classe = NEW(1, Class);
	classe->name=tete->type;
	classe->constructor = NEW(1, Method);
	classe->constructor->name=tete->type;
	classe->constructor->body=bloc;
	classe->constructor->args=tete->var;
	classe->super=super; // nom de la classe et pas la structure
	classe->next=NIL(Class);
	return(classe);
}

void makeProg(ClassP listC, TreeP bloc) {
	//CREATION DES CLASSES PREDEFINIES
	ClassP integer = NEW(1, Class);
	integer->name = "Integer";
	integer->next = listC;
	ClassP string = NEW(1, Class);
	string->name = "String";
	string->next = integer;
	listC = string;
	
	//VERIFICATIONS CONTEXTUELLES
	if(checkDoublonClass(listC)) setError(CONTEXT_ERROR); // verif doublons
	attribSuper(listC);
	attribType(listC);
	attribTypeBlock(bloc, listC);
	if(circuitHeritage(listC)) setError(CONTEXT_ERROR); // verif circuit d'heritage
	if(pbOverride(listC)) setError(CONTEXT_ERROR); // verif des overrides
	verifEnv(listC, bloc);
	
	if(errorCode != NO_ERROR) printf("\nVerifications contextuelles echouees !\n");
	else printf("\nVerifications contextuelles reussies !\n");
	// CODE GENERATION
}

/* eval: parcours recursif de l'AST d'une expression en cherchant dans
 * l'environnement la valeur des variables referencee
 * tree: l'AST d'une expression
 * decls: la liste des variables deja declarées avec leur valeur.
 */
int eval(TreeP tree, VarDeclP decls) {
	if (tree == NIL(Tree)) { exit(UNEXPECTED); }
	switch (tree->op)
	{
		case IDVAR: case Id:
			return getValue(tree, decls);
		case Cste:
			return(tree->u.val);
		case EQ:
			return (eval(getChild(tree, 0), decls) == eval(getChild(tree, 1), decls));
		case NE:
			return (eval(getChild(tree, 0), decls) != eval(getChild(tree, 1), decls));
		case GT:
			return (eval(getChild(tree, 0), decls) > eval(getChild(tree, 1), decls));
		case GE:
			return (eval(getChild(tree, 0), decls) >= eval(getChild(tree, 1), decls));
		case LT:
			return (eval(getChild(tree, 0), decls) < eval(getChild(tree, 1), decls));
		case LE:
			return (eval(getChild(tree, 0), decls) <= eval(getChild(tree, 1), decls));
		case EADD:
			return (eval(getChild(tree, 0), decls) + eval(getChild(tree, 1), decls));
		case EMINUS:
			return (eval(getChild(tree, 0), decls) - eval(getChild(tree, 1), decls));
		case EMULT:
			return (eval(getChild(tree, 0), decls) * eval(getChild(tree, 1), decls));
		case EDIV:
		{
			if (eval(getChild(tree,1), decls) == 0) {
				fprintf(stderr, "Error: Division by zero\n"); exit(EVAL_ERROR);
			}
			else { return ( eval(getChild(tree,0), decls)/ eval(getChild(tree,1), decls) ); }
		}
		case ITE:
			return evalIf(tree, decls);
		default:
			fprintf(stderr, "Erreur! etiquette indefinie: %d\n", tree->op);
			exit(UNEXPECTED);
	}
}


/* Evaluation d'un if then else
 * le premier fils represente la condition,
 * les deux autres fils correspondent respectivement aux parties then et else.
 * Attention a n'evaluer qu'un seul de ces deux sous-arbres !
 */
int evalIf(TreeP tree, VarDeclP decls)
{
	if (eval(getChild(tree, 0), decls)) {
		return eval(getChild(tree, 1), decls);
	}
	else { return eval(getChild(tree, 2), decls); }
}


/* retourne la valeur d'une variable: 'tree' correspond a une feuille qui
 * represente un identificateur. decls est la liste courante des couples
 * (variable, valeur). On est suppose avoir deja verifie que l'identificateur
 * etait bien declare, donc on doit trouver sa valeur.
 */
int getValue(TreeP tree, VarDeclP decls) {
	char *name = tree->u.str;
	while (decls != NIL(VarDecl)) {
		if (strcmp(decls->name, name)==0) return(tree->u.val);
		decls = decls->next;
	}
	/* Cannot happen if variables have been checked before evaluation.
	* In the presence of undeclared variables, errorCode was set to
	* CONTEXT_ERROR by function checkScope.
	*/
	if (errorCode == NO_ERROR) {
		fprintf(stderr, "Unexpected error: Undeclared variable %s\n", name);
		exit(UNEXPECTED);
	}
	else {
	/* Value does not matter, evaluation is blocked anyhow and getValue
	 * will never be called in that case.
	 * Hence this is dead code, needed only to prevent gcc from complaining
	 * about having a non-void function not returning a value !
	 */
	return -1;
	}
}	

void printClass(ClassP list) {
	ClassP temp = list;

	while(temp != NULL) {
		printf("%s", temp->name);
		temp=temp->next;
	}

}

/* tree : l'ast d'une expression 
 * d : liste des variables déjà déclarées avec une valeur
*/
/*void printTree(TreeP tree, int compteur)
{
	if (tree == NIL(Tree)) { exit(UNEXPECTED); }
	printf("\nprofondeur: %d\n ", compteur);
	compteur++;
	switch (tree->op)
	{
		
		case IDVAR: 
			printf("IDVAR: %s ", tree->u.str);

			break;
		case Id:
			printf("Id: %s ", tree->u.str);

			break;
		case Cste : 
			printf("Cste: %d ", tree->u.val);

			break;
		case EQ: 
			printf("\nEQ: ");
			printTree(getChild(tree,0),compteur);
			printf("  ,  ");	
			printTree(getChild(tree,1),compteur);
		
			break;
		case NE: 
			printf("\nNE: ");
			printTree(getChild(tree,0),compteur);
			printf("\t");	
			printTree(getChild(tree,1),compteur);
		
			break;
		case LT : 
			printf("\nLT: ");
			printTree(getChild(tree,0),compteur);
			printf("\t");	
			printTree(getChild(tree,1),compteur);
	
			break;
		case LE: 
			printf("\nLE: ");
			printTree(getChild(tree,0),compteur);
			printf("\t");	
			printTree(getChild(tree,1),compteur);
	
			break;
		case GT:
			printf("\nGT: ");
			printTree(getChild(tree,0),compteur);
			printf("\t");	
			printTree(getChild(tree,1),compteur);
	
			break;
		case GE :
			printf("\nGE: ");
			printTree(getChild(tree,0),compteur);
			printf("\t");	
			printTree(getChild(tree,1),compteur);
	
			break;
		case ITE : 
			printf("\nITE: ");

			printTree(getChild(tree,0),compteur);
			printf("\t");	
			printTree(getChild(tree,1),compteur);
			printf("\t");

			printTree(getChild(tree,2),compteur);
		
			break;
		case EADD: case EMINUS:  case EMULT : case EDIV : 
			printf("\nADD/MIN/MULT/DIV: ");
			printTree(getChild(tree,0),compteur);
			printf("\t");	
			printTree(getChild(tree,1),compteur);
		
			break;
		default:
			fprintf(stderr, "Erreur! etiquette indefinie: %d\n", tree->op);
			exit(UNEXPECTED);
	}
}*/


