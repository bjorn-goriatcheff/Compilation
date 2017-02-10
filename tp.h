#ifndef _TP_H_
#define _TP_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TRUE 1
#define FALSE 0

typedef unsigned char bool;

#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

/* Etiquettes additionnelles pour les arbres de syntaxe abstraite.
 * Certains tokens servent directement d'etiquette. Attention ici a ne pas
 * donner des valeurs identiques a celles des tokens.
 */
#define NE	1 /* !=*/
#define EQ	2 /* ==*/
#define LT	3 /* <*/
#define LE	4 // <=
#define GT	5 // >
#define GE	6 // >=
#define IDVAR 7 //Id en tant que variable d'une methode et non d'un champ
#define ITE 8//if then else
#define EADD 9
#define EMINUS 10
#define EMULT 11
#define EDIV 12
#define CONST 13
#define ESTR 14
#define OP 15
#define CONCA 16
#define BLOCK 17
#define ISBLOCK 18
#define DECL 19
#define ARGLIST 20
#define INST 21
#define PROG 22
#define ISNOTBLOCK 23
#define AFFEC 24



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

struct _Tree;
typedef struct _Tree Tree, *TreeP;

struct _VarDecl;
typedef struct _VarDecl VarDecl, *VarDeclP;

struct _Arg;
typedef struct _Arg Arg, *ArgP;

struct _Block;
typedef struct _Block Block, *BlockP;

struct _Method;
typedef struct _Method Method, *MethodP;

struct _Class;
typedef struct _Class Class, *ClassP;

struct _TeteClass;
typedef struct _TeteClass Tete, *TeteP;

struct _Env;
typedef struct _Env Env, *EnvP;

/* la structure d'un arbre (noeud ou feuille) */
struct _Tree {
  short op;         /* etiquette de l'operateur courant */
  short nbChildren; /* nombre de sous-arbres */
  union {
    char *str;      /* valeur de la feuille si op = Id ou STR */
    int val;        /* valeur de la feuille si op = Cste */
    VarDeclP lvar;
    struct _Tree **children; /* tableau des sous-arbres */
  } u;
};

struct _VarDecl {
  char *name;
  char *varType;
  TreeP expr;
  struct _VarDecl *next;
};

struct _Method {
	char* name;
	VarDeclP args;
	TreeP body;
	char* type;
	bool over;
	struct _Method *next;
};

struct _Class {
	char *name;
	VarDeclP var;
	MethodP method;
	MethodP constructor;
	char* super;
	ClassP superC;
	struct _Class *next;
};

struct _TeteClass {
	char* type;
	VarDeclP var;
};

typedef union
  { char *S;
	char C;
	bool B;
	int I;
	TreeP pT;
	VarDeclP pV;
	ClassP pC;
	MethodP pM;
	TeteP pTe;
} YYSTYPE;

#define YYSTYPE YYSTYPE

//Structure environnement
struct _Env {
	VarDeclP var;
	MethodP method;	
	EnvP next;
	EnvP herit;
	
};

//Fonctions pour l'AST
	//Construction
TreeP makeNode(int nbChildren, short op); // Noeud
TreeP makeLeafStr(short op, char *str); 	    /* feuille (string) */
TreeP makeLeafInt(short op, int val);	            /* feuille (int) */
TreeP makeTree(short op, int nbChildren, ...);	    /* noeud interne */
TreeP makeLeafLVar(short op, VarDeclP lvar);
	//Gestion
VarDeclP addToScope(VarDeclP list, VarDeclP nouv);
VarDeclP declVar(char *name, TreeP tree, VarDeclP decls);
VarDeclP evalDecls (TreeP tree);
int eval(TreeP tree, VarDeclP decls);
int evalMain(TreeP tree, VarDeclP decls);
int evalIf(TreeP tree,VarDeclP decls);
int getValue(TreeP tree, VarDeclP var);


//Remplissage de structures
VarDeclP makeVarDecl(char *name, char *type, TreeP expr);
MethodP makeMeth(char* name, VarDeclP args);
TreeP makeBlock(VarDeclP decl, TreeP instr);
MethodP fillMeth(MethodP meth, TreeP bloc, bool over);
ClassP makeClass(TeteP tete, char* super, TreeP bloc);
TeteP makeTete(char* nom, VarDeclP var);
void attribSuper(ClassP list);

void printClass(ClassP list);

void makeProg(ClassP listC, TreeP bloc);
ClassP getClass(ClassP listC, char *name);

//verifs
bool circuitHeritage(ClassP list);
bool pbOverride(ClassP list);
bool checkSuper(ClassP class, MethodP method);
bool isMethodInClass(MethodP method, ClassP class);
bool areArgTypeTheSame(VarDeclP arg1, VarDeclP arg2);

//ENV
bool verifEnv(ClassP classL, TreeP bloc);
EnvP creerEnv(ClassP classL);
EnvP recupEnv(char* mere, ClassP deb, EnvP env);
EnvP envCat(EnvP envM, EnvP envF);
bool isVarInEnv(VarDeclP var1, VarDeclP var2);
bool checkProgram (TreeP program, ClassP ClassInProg);
bool checkBloc(TreeP bloc, VarDeclP listDec);
bool checkDecl(TreeP bloc, VarDeclP listDec);
char* getType(TreeP t);
bool checkType(char* va, char* vb);
bool checkAttribut(VarDeclP var);
bool checkInstructions(TreeP bloc , VarDeclP var);
bool checkListMethod(ClassP c);







#endif
