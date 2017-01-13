#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char bool;

#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

/* Etiquettes additionnelles pour les arbres de syntaxe abstraite.
 * Certains tokens servent directement d'etiquette. Attention ici a ne pas
 * donner des valeurs identiques a celles des tokens.
 */
#define NE	1 // !=
#define EQ	2 // ==
#define LT	3 // <
#define LE	4 // <=
#define GT	5 // >
#define GE	6 // >=
#define IDVAR 7 //Id en tant que variable d'une methode et non d'un champ
#define ITE 8//if then else
#define EADD 9
#define EMINUS 10
#define EMULT 11
#define EDIV 12

/* Codes d'erreurs */
#define NO_ERROR	0
#define USAGE_ERROR	1
#define LEXICAL_ERROR	2
#define SYNTAX_ERROR    3
#define CONTEXT_ERROR	40	/* default value for this stage */
#define DECL_ERROR	41	/* more precise information */
#define TYPE_ERROR	42
#define EVAL_ERROR	50
#define UNEXPECTED	100

typedef struct _varDecl {
  char *name;
  s_class varType;
  struct _varDecl *next;
  int val;
} VarDecl, *VarDeclP;


/* la structure d'un arbre (noeud ou feuille) */
typedef struct _Tree {
  short op;         /* etiquette de l'operateur courant */
  short nbChildren; /* nombre de sous-arbres */
  union {
    char *str;      /* valeur de la feuille si op = Id ou STR */
    int val;        /* valeur de la feuille si op = Cste */
    VarDeclP lvar;
	s_class classe;
	s_method method;
    struct _Tree **children; /* tableau des sous-arbres */
  } u;
} Tree, *TreeP;


typedef union
      { char *S;
        char C;
	int I;
	TreeP pT;
	VarDeclP pV;
	s_class pC;
	s_method pM;
} YYSTYPE;

#define YYSTYPE YYSTYPE

//Structures C du code
typedef struct s_class
{
	string className;
	s_class fromClass;
	
	s_var *p_classParameter;

	s_method classConstructor; /* Pourrait être la premiere methode de p_classMethod */
	s_method *p_classMethod;
	
	s_class *suivant;
	
} s_class;


typedef struct s_method
{
	string methodName;
	s_var *p_methodVar;
	s_class methodHome;
	s_class methodType;
	s_instruction *p_methodInstructions;
	s_method suivant;
} s_method;

typedef struct s_var
{
	string varName;
	s_class varType;
} s_var;

typedef struct s_instruction
{
	TreeP instructionTree;
} s_instruction;

//Fonctions pour l'AST
	//Construction
TreeP makeNode(int nbChildren, short op); // Noeud
TreeP makeLeafStr(short op, char *str); 	    /* feuille (string) */
TreeP makeLeafInt(short op, int val);	            /* feuille (int) */
TreeP makeTree(short op, int nbChildren, ...);	    /* noeud interne */
//TreeP makeLeafClass(short op, s_class classe);
//TreeP makeLeafMethod(short op, s_method met);

	//Gestion
VarDeclP addToScope(VarDeclP list, VarDeclP nouv);
VarDeclP declVar(char *name, TreeP tree, VarDeclP decls);
VarDeclP evalDecls (TreeP tree);
int eval(TreeP tree, VarDeclP decls);
int evalMain(TreeP tree, VarDeclP decls);
int evalIf(TreeP tree,VarDeclP decls);
bool isMethodInClass(s_class cl, s_method met);