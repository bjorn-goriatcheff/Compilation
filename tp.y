/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS VAR CLASS AFF DEF ADD SUB MUL DV UNARY AS IF THEN ELSE NEWW DOT EXTENDS OVERRIDE AND
%token<S> Id STRING TYPE RETURN
%token<I> Cste
%token<C> RelOp



/* Indications de precedence */
%nonassoc RelOp
%left ADD SUB
%left MUL DV
%right UNARY
%left AND
%left DOT

%type <pT> expression opexpr bexpr instanc message select cast paramList paramListOpt inst block affInst


%{
#include "tp.h"
#include "tp_y.h"

extern int yylex();
extern void yyerror(char *);
%}

%%
Prog : classLOpt block 
;

classLOpt: 
| classDecl classLOpt
;

classDecl: classHeader IS classBlock
;

extOpt:
| EXTENDS TYPE '(' paramListOpt ')'
;

block: '{' instListOpt '}'
| '{' declList IS instList '}'
;

instListOpt:
| instList
;

instList: inst instListOpt
;

inst: expression ';'		
| block
| RETURN ';'	{ $$ = makeLeafStr(RETURN, $1); }	
| affInst	
| IF expression THEN inst ELSE inst { $$ = makeTree(ITE, 3, $2, $4, $6); }
;

declList: decl declListOpt
;

classBlock: '{' declListOpt methListOpt'}'
;

methListOpt:
| meth methListOpt
;

meth: overOpt methHeader isBlock
| overOpt methHeader isNotBlock
;

overOpt:
| OVERRIDE
;

isNotBlock: ':' TYPE AFF expression
;

isBlock: typeOpt IS block
;

typeOpt: 
| ':' TYPE
;

methHeader: DEF Id '(' paramOpt ')'
;

declListOpt: 
| decl declListOpt
;

decl: VAR Id ':' TYPE initInstOpt ';'
;

initInstOpt:
| AFF expression
;

classHeader: CLASS param extOpt initBlockOpt
;

initBlockOpt: 
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

param: TYPE '(' paramOpt ')'
;

paramOpt: 
| argList
;

argList: arg
| arg ',' argList
;

arg: Id ':' TYPE
;
