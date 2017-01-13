/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS VAR TYPE CLASS AFF DEF ADD SUB MUL DV STRING UNARY AS RETURN IF THEN ELSE NEWW DOT EXTENDS OVERRIDE AND
%token<S> Id
%token<I> Cste
%token<C> RelOp


/* Indications de precedence */
%nonassoc RelOp
%left ADD SUB
%left MUL DV
%right UNARY
%left AND
%left DOT

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
| RETURN ';'
| affInst
| IF expression THEN inst ELSE inst
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
| STRING
| opexpr
| expression AND expression
| '(' expression ')'
| bexpr
| ADD expression %prec UNARY 				{ $$ = $2; }
| SUB expression %prec UNARY 
| select
| cast
| instanc
| message
;

message: expression DOT Id '(' paramListOpt ')'
;

instanc: NEWW TYPE '(' paramListOpt ')'
;

paramListOpt: 
| paramList
;

paramList: expression
| expression ',' paramList
;

cast: '(' AS TYPE ':' expression ')'
;

select: expression DOT Id
;

opexpr: expression ADD expression		{ $$ = makeTree(EADD, 2, $1, $3); }
| expression SUB expression 			{ $$ = makeTree(EMINUS, 2, $1, $3); }
| expression MUL expression 			{ $$ = makeTree(EMULT, 2, $1, $3); }
| expression DV expression 			{ $$ = makeTree(EDIV, 2, $1, $3); }


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
