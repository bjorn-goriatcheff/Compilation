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

%type <pT> Prog block isBlock isNotBlock expression opexpr bexpr instanc message select cast inst affInst instListOpt instList initInstOpt initBlockOpt typeOpt paramList paramListOpt 

%type <B> overOpt
%type <pV> declList declListOpt decl argListOpt argList arg
%type <pC> classHeader classDecl classLOpt
%type <S>  extOpt
%type <pM> methHeader  meth methListOpt
%type <pTe> construct 
%{
#include "tp.h"
#include "tp_y.h"

VarDeclP lvar;
ClassP lclass;

extern int yylex();
extern void yyerror(char *);
%}

%%
Prog : classLOpt block {  makeProg($1, $2);};

classLOpt: { $$ = NIL(Class); }
| classDecl classLOpt { $1->next=$2; $$=$1; }
;

classDecl: classHeader IS '{' declListOpt methListOpt'}'   { $1->var=$4; $1->method=$5; $$=$1; }
;
/* initblockOpt a faire */
classHeader: CLASS construct extOpt initBlockOpt  { $$ = makeClass($2, $3, $4); } // FILL class 
;

extOpt: { $$ = NIL(char); }
| EXTENDS TYPE '(' paramListOpt ')' { $$ = $2; } // on ignore paramLopt et on renvoie un char
;

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

methListOpt: { $$ = NIL(Method); }
| meth methListOpt { $1->next=$2; $$=$1;}
;

meth: overOpt methHeader isBlock { $$=fillMeth($2, $3, $1);}
| overOpt methHeader isNotBlock { $$=fillMeth($2, $3, $1);}
;

overOpt: { $$ = FALSE; }
| OVERRIDE {  $$ = TRUE; }
;

isNotBlock: ':' TYPE AFF expression { $$ = makeTree(AFF , 2, makeLeafStr(TYPE, $2), $4);} 
;

isBlock: typeOpt IS block { $$ = makeTree(IS, 2, $1, $3); }
;

typeOpt: { $$ = makeLeafStr(TYPE, NIL(char)); }
| ':' TYPE { $$ = makeLeafStr(TYPE, $2); }
;

methHeader: DEF Id '(' argListOpt ')' { $$ = makeMeth($2, $4); }
;

initInstOpt: { $$ = NIL(Tree); }
| AFF expression { $$ = makeTree(AFFEC,1,$2); }
;

initBlockOpt: { $$ = NIL(Tree); }
| block 

affInst: expression AFF expression ';' { $$ = makeTree(AFF, 2, $1, $3); }
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

paramListOpt: { $$=NIL(Tree);}		
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
;

bexpr: expression RelOp expression 		{ $$ = makeTree($2, 2, $1, $3); }
;

construct: TYPE '(' argListOpt ')' { $$ = makeTete($1, $3); }
;

argListOpt: { $$ = NIL(VarDecl); }
| argList 
;

argList: arg
| arg ',' argList { $1->next=$3; $$=$1;}
;

arg: Id ':' TYPE { $$ = makeVarDecl($1, $3, NIL(Tree)); }
;
