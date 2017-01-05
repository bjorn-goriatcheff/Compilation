/* attention: NEW est defini dans tp.h Utilisez un autre token */
%token IS VAR TYPE CLASS 
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
| classHeader IS classBlock
;

block: '{''}'

classBlock: '{' declListOpt '}'
;

declListOpt: 
| decl declListOpt
;

decl: VAR Id ':' TYPE ';'

classHeader: CLASS param initBlockOpt
;

initBlockOpt: 
| '{' affList '}' 

affList: aff 
| aff ';' affList

param: Id '(' paramOpt ')'
;

paramOpt: 
| argList
;

argList: arg
| arg ',' argList
;

arg: Id ':' TYPE
;
