/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS VAR TYPE CLASS AFF DEF ADD SUB MUL DV STRING
%token<S> Id
%token<I> Cste
%token<C> RelOp


/* Indications de precedence */
%nonassoc RelOp
%left ADD SUB
%left MUL DV

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
| classHeader IS classBlock
;

block: '{' instListOpt '}'
| '{' declList IS instList '}'
;

instListOpt:
| instList
;

instList: expression ';' instListOpt
;

declList: decl declListOpt
;

classBlock: '{' declListOpt methListOpt'}'
;

methListOpt:
| meth methListOpt
;

meth: methHeader isBlock
| methHeader isNotBlock
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
| expression ADD expression
| expression SUB expression
| expression DV expression
| expression MUL expression
| '(' expression ')'
| bexpr
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