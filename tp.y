/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE RETURNS RETURN AS IF THEN ELSE AFF DOT COM ENDCOM ADD SUB MUL QUO NEWW TYPE
%token<S> Id
%token<I> Cste
%token<C> RelOp


/* Indications de precedence */
%left ELSE
%left ADD SUB
%left MUL QUO
%left EXTENDS 
%left IS CLASS 
%left UNARY


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
classHeader IS blockClass
;

ClassHeader: CLASS Id ListParam BlockClass
;

listParam: '(' ListParamOpt ')'
;

ListParamOpt:
|Param
;

Param: Arg
| Arg ',' ListParam
;

Arg: Id ':' TYPE
;

BlockClass: '{' ListInst '}'
;

ListInst: 
| Inst ListInst
