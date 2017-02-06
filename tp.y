/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS VAR CLASS AFF DEF ADD SUB MUL DV UNARY AS IF THEN ELSE NEWW DOT EXTENDS OVERRIDE AND 
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

%type <pT> Prog classDecl classLOpt block isBlock isNotBlock expression opexpr bexpr instanc message select cast paramList paramListOpt inst affInst instListOpt instList classBlock initInstOpt param initBlockOpt argList arg
%type <B> overOpt
%type <pV> declList declListOpt decl paramOpt
%type <pC> classHeader
%type <S>  typeOpt extOpt
%type <pM> methHeader  meth methListOpt

%{
#include "tp.h"
#include "tp_y.h"

VarDeclP lvar;
ClassP lclass;

extern int yylex();
extern void yyerror(char *);
%}

%%
Prog : classLOpt block { $$ = makeTree(PROG, 2, $1, $2); lvar=NEW (0, VarDecl); };

classLOpt: { $$ = NIL(Tree); }
| classDecl classLOpt 
;

classDecl: classHeader IS classBlock 
;
/* initblockOpt a faire */
classHeader: CLASS construct extOpt initBlockOpt 
;

extOpt: { $$ = NIL(char); }
| EXTENDS TYPE '(' paramListOpt ')' { $$ = $2; } // on ignore paramLopt
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


classBlock: '{' declListOpt methListOpt'}' 
;

methListOpt: { $$ = NIL(Method); }
| meth methListOpt { $1->next=$2; $$=$1;}
;

meth: overOpt methHeader isBlock { $2->type=$3->u.children[0]->u.str; $2->body=$3->u.children[1]; $$=$2; }
| overOpt methHeader isNotBlock { $2->type=$3->u.children[0]->u.str; $2->body=$3->u.children[1]; $$=$2; }
;

overOpt: { $$ = FALSE; }
| OVERRIDE {  $$ = TRUE; }
;
// regler l'affectation
isNotBlock: ':' TYPE AFF expression { $$ = makeTree(ISNOTBLOCK, 2, $2, $4); }
;

isBlock: typeOpt IS block { $$ = makeTree(ISBLOCK, 2, $1, $3); }
;

typeOpt: { $$ = NIL(char); }
| ':' TYPE { $$ = $2; }
;

methHeader: DEF Id '(' paramOpt ')' { $$ = makeMeth($2, $4); }
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

construct: TYPE '(' argListOpt ')' { $$ = makeTree(TYPE, 1, $3); }
;

argListOpt: { $$ = NIL(VarDecl); }
| argList
;

argList: arg
| arg ',' argList { $$ = makeTree(ARGLIST, 2, $1, $3); }
;

arg: Id ':' TYPE { $$ = makeTree(Id, 1, $3); }
;
