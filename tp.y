/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE RETURNS RETURN AS IF THEN ELSE AFF DOT COM ENDCOM ADD SUB MUL QUO NEWW
%token<S> Id
%token<I> Cste
%token<C> RelOp


/* Indications de precedence */


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
;

block:
;
