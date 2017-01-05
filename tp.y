/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE RETURNS RETURN AS IF THEN ELSE AFF DOT COM ENDCOM ADD SUB MUL QUO NEWW TYP
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
|classHeader IS blockClass
;

classHeader: CLASS Id listParam blockClass
;

listParam: '(' listParamOpt ')'
;

listParamOpt:
|param
;

param: arg
| arg ',' param
;

arg: Id ':' TYP
;

blockClass: '{' listInst '}'
;

listInst: 
| Inst listInst
