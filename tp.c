#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
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

FILE *out; /* fichier de sortie pour le code engendre */


int main(int argc, char **argv) {
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


void setError(int code) {
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

TreeP makeLeafLVar(short op, VarDeclP lvar) {
  TreeP tree = makeNode(0, op) ;
  tree->u.lvar = lvar;
  return(tree);
}


/* Avant evaluation, verifie si tout identificateur qui apparait dans tree a
 * bien ete declare (dans ce cas il doit etre dans la liste lvar).
 * On impose que ca soit le cas y compris si on n'a pas besoin de cet
 * identificateur pour l'evaluation, comme par exemple x dans
 * begin if 1 = 1 then 1 else x end
 * Le champ 'val' de la structure VarDecl n'est pas significatif
 * puisqu'on n'a encore rien evalue.
 */
 
 //Gérer s'il s'agit d'une variable locale ou d'un champ. Genre créer un truc IdRes
bool checkScope(TreeP tree, VarDeclP lvar) {
	VarDeclP p; 
	char *name;
	if (tree == NIL(Tree)) { return TRUE; }
	switch (tree->op) 
	{
		case IDVAR : case Id:
			/* verifie si la variable existe dans 'lvar' ou pas */
			name = tree->u.str;
			for(p=lvar; p != NIL(VarDecl); p = p->next) 
			{
				if (strcmp(p->name, name)==0) { return TRUE; }
			}
			fprintf(stderr, "\nError: undeclared variable %s\n", name);
			/* setError met noEval a true de facon à bloquer les evaluations
			* ulterieures, sinon on pourrait chercher la valeur d'une variable qui
			* n'existe pas
			*/
			setError(CONTEXT_ERROR);
			return FALSE;
		case CONST:	//OK : pas besoin de vérifier
			return TRUE;
		case ITE:	//OK : on vérifie les 3 champs du ITE
			return checkScope(getChild(tree, 0), lvar) /* la condition */
				&& checkScope(getChild(tree, 1), lvar) /* la partie 'then' */
				&& checkScope(getChild(tree, 2), lvar); /* la partie 'else' */
		case EQ: case NE: case GT: case GE: case LT: case LE: 
		case EADD: case EMINUS: case EMULT: case EDIV:
			return checkScope(getChild(tree, 0), lvar) 
				&& checkScope(getChild(tree, 1), lvar);
		default: 
			fprintf(stderr, "Erreur! etiquette indefinie: %d\n", tree->op);
			exit(UNEXPECTED);
	}
}

/* Associe une variable a l'expression qui definit sa valeur, et procede a 
 * l'evaluation de cette expression, sauf si on est en mode noEval
 */
VarDeclP declVar(char *name, TreeP tree, VarDeclP decls) 
{
	VarDeclP pvar = NEW(1, VarDecl);
	pvar->name = name; 
	pvar->next = NIL(VarDecl);
	/* verifie que l'AST ne mentionne pas de variable non declaree */
	checkScope(tree, decls);
	/* puis evalue l'expression en recherchant la valeur des variables dans la
	* liste representee par 'decls'. Vu la verification precedente, la
	* recherche ne pourra pas echouer.
	*/
	if (! noEval) 	{ pvar->val = eval(tree, decls); }

	/* ajoute le cnouveau couple variable/valeur en tete de la liste coruante et
	* la renvoie en resultat. Verifie en meme temps que cette variable n'a pas
	* deja ete declaree
	*/
	return addToScope(decls, pvar);
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
		case CONST:
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
			else { return (res / res2); }
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
		if (strcmp(decls->name, name)==0) return(decls->val);
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


/* Verifie que nouv n'apparait pas deja dans list. l'ajoute en tete et
 * renvoie la nouvelle liste
 */
VarDeclP addToScope(VarDeclP list, VarDeclP nouv) {
  VarDeclP p;
  for(p=list; p != NIL(VarDecl); p = p->next) {
    if (strcmp(p->name, nouv->name)==0) {
      fprintf(stderr, "Error: Multiple declaration in the same scope of %s\n",
	      p->name);
      setError(CONTEXT_ERROR);
      break;
    }
  }
  /* On continue meme en cas de double declaration, pour pouvoir eventuellement
   * detecter plus d'une erreur
   */
  nouv->next=list;
  return nouv;
}


