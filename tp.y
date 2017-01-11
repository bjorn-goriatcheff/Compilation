/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS VAR TYPE CLASS AFF DEF ADD SUB MUL DV STRING UNARY AS RETURN IF THEN ELSE NEWW DOT EXTENDS OVERRIDE
%token<S> Id
%token<I> Cste
%token<C> RelOp


/* Indications de precedence */
%nonassoc RelOp
%left ADD SUB
%left MUL DV
%right UNARY
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
| classHeader extOpt IS classBlock
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

overOpt: OVERRIDE
;

isNotBlock: ':' TYPE AFF expression ';'
;

isBlock: typeOpt IS block
;

typeOpt: 
| ':' TYPE AFF
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

classHeader: CLASS param initBlockOpt
;

initBlockOpt: 
| '{' affList '}'
; 

affList: affInst 
| affInst affList
;

affInst: Id AFF expression ';'
;

expression: Id
| Cste
| STRING
| opexpr
| '(' expression ')'
| bexpr
| ADD expression %prec UNARY 
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

opexpr: expression ADD expression
| expression SUB expression
| expression MUL expression
| expression DV expression
;

bexpr: expression RelOp expression
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