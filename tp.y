/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS VAR CLASS AFF DEF ADD SUB MUL DV UNARY AS IF THEN ELSE NEWW DOT EXTENDS OVERRIDE AND INST PROG ARGLIST CLASSB METH DECL
%token<S> Id STRING TYPE RETURN CLASSDEF
%token<I> Cste
%token<C> RelOp



/* Indications de precedence */
%nonassoc RelOp
%left ADD SUB
%left MUL DV
%right UNARY
%left AND
%left DOT

%type <pT> Prog classDecl classLOpt block meth methListOpt typeOpt expression opexpr bexpr instanc message select cast paramList paramListOpt inst affInst  extOpt instListOpt instList classHeader classBlock initInstOpt param initBlockOpt paramOpt argList arg
%type <B> overOpt
%type <pV> declList declListOpt decl

%{
#include "tp.h"
#include "tp_y.h"

VarDeclP lvar;
MethodP lmeth;
ClassP lclass;

extern int yylex();
extern void yyerror(char *);
%}

%%
Prog : classLOpt block { $$ = makeTree(PROG, 2, $1, $2); lvar=NEW (0, VarDecl); };

classLOpt: { $$ = NIL(Tree); }
| classDecl classLOpt { $$ = makeTree(CLASSDEF, 2, $1, $2); }
;

classDecl: classHeader IS classBlock { $$ = makeTree(IS, 2, $1, $3);  }
;

classHeader: CLASS param extOpt initBlockOpt {  }
;

extOpt: { $$ = NIL(Tree); }
| EXTENDS TYPE '(' paramListOpt ')' {$$ = makeTree(EXTENDS, 2, $2, $4); }
;
/* makeBlock */
block: '{' instListOpt '}' { $$ = makeBlock(NIL(VarDecl) ,$2); }
| '{' declList IS instList '}' { $$ = makeBlock($2, $4); }
;

instList: inst instListOpt { $$ = makeTree(INST, 2, $1, $2 ); }
;

instListOpt: { $$ = NIL(Tree); }
| instList 
;



inst: expression ';'		
| block
| RETURN ';'	{ $$ = makeLeafStr(RETURN, $1); }	
| affInst	
| IF expression THEN inst ELSE inst { $$ = makeTree(ITE, 3, $2, $4, $6); }
;

declList: decl declListOpt { $1->next=$2; $$=$1; }
;

declListOpt: { $$ = NIL(VarDecl); }
| decl declListOpt {  $1->next=$2; $$=$1; }
;

decl: VAR Id ':' TYPE initInstOpt ';' { $$ = makeVarDecl($2 , $4, $5); }
;


classBlock: '{' declListOpt methListOpt'}' { $$ = makeTree(CLASSB, 2, $2, $3); }
;

methListOpt: { $$ = NIL(Tree); }
| meth methListOpt { $$ = makeTree(METH, 2, $1, $2); }
;

meth: overOpt methHeader isBlock
| overOpt methHeader isNotBlock
;

overOpt: { $$ = FALSE; }
| OVERRIDE {  $$ = TRUE; }
;

isNotBlock: ':' TYPE AFF expression
;

isBlock: typeOpt IS block
;

typeOpt: { $$ = NIL(Tree); }
| ':' TYPE
;

methHeader: DEF Id '(' paramOpt ')'
;

initInstOpt: { $$ = NIL(Tree); }
| AFF expression
;



initBlockOpt: { $$ = NIL(Tree); }
| block

affInst: expression AFF expression ';'
;

expression: Id						{ $$ = makeLeafStr(IDVAR, $1); }
| Cste							{ $$ = makeLeafInt(CONST, $1); }
| STRING						{ $$ = makeLeafStr(STRING, $1); }
| opexpr						
| expression AND expression				{ $$ = makeTree(AND, 2, $1, $3); }
| '(' expression ')'					{ $$ = $2;}
| bexpr							
| ADD expression %prec UNARY 				{ $$ = $2; }
| SUB expression %prec UNARY 				{ $$ =  makeTree(EMINUS, 2, makeLeafInt(CONST,0), $2); }
| select
| cast
| instanc
| message
;

message: expression DOT Id '(' paramListOpt ')'      { $$ = makeTree(DOT,3, $1, makeLeafStr(IDVAR, $3), $5); }
;

instanc: NEWW TYPE '(' paramListOpt ')'      { $$ = makeTree(NEWW, 2, $2, $4) ;}        
; 

paramListOpt: 		{}		
| paramList				
;

paramList: expression
| expression ',' paramList	{ $$ = makeTree(CONCA, 2, $1, $3); }
;

cast: '(' AS TYPE ':' expression ')'	{ $$ = makeTree(AS, 2, makeLeafStr(TYPE, $3), $5); }
;

select: expression DOT Id		{ $$ = makeTree(DOT, 2, $1, makeLeafStr(IDVAR, $3));}
;

opexpr: expression ADD expression		{ $$ = makeTree(EADD, 2, $1, $3); }
| expression SUB expression 			{ $$ = makeTree(EMINUS, 2, $1, $3); }
| expression MUL expression 			{ $$ = makeTree(EMULT, 2, $1, $3); }
| expression DV expression 			{ $$ = makeTree(EDIV, 2, $1, $3); }

bexpr: expression RelOp expression 		{ $$ = makeTree($2, 2, $1, $3); }
;

param: TYPE '(' paramOpt ')' { $$ = makeTree(TYPE, 1, $3); }
;

paramOpt: { $$ = NIL(Tree); }
| argList
;

argList: arg
| arg ',' argList { $$ = makeTree(ARGLIST, 2, $1, $3); }
;

arg: Id ':' TYPE { $$ = makeTree(Id, 1, $3); }
;
