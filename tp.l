/*flex generateur d'analyse lexicale*/
/*Expressions régulières et actions associées, abréviations*/

Chiffre [0-9]
Entier {Chiffre}+
Lower	[a-z]
Upper	[A-Z]
Lettre	[a-zA-Z]
LC 	({Lettre}|{Chiffre})
Delim   [ \t\n\r]
Symbole [&+\-*/();:,.{}]
BS      \\.
PasBSG [^\\"]
Guill		"\""
Star  		"*"
NotStar		[^*]
NotStarPar      [^*/]

%{
#include <string.h>
#include <strings.h>
#include "tp.h"
#include "tp_y.h"

#ifndef __APPLE__
extern char *strdup(char *);
#endif

extern YYSTYPE yylval;
extern int yylineno; 
extern int yylex(); 




/*Precessing - precedence*/
extern YYSTYPE yylval; 
extern int errorCode;

int keywordOrId() { 
  /* a completer */
  if (! strcmp(yytext, "class")) return CLASS;
  if (! strcmp(yytext, "is")) return IS;
  if (! strcmp(yytext, "var")) return VAR;
  if (! strcmp(yytext, "def")) return DEF;
  yylval.S = strdup(yytext);
  return (Id);

}


void lexError(char c) {
  fprintf(stderr, "Error: Skipping invalid character '%c' on line %d\n",
          c, yylineno);
  setError(LEXICAL_ERROR);
}

/* les codes symboliques pour les unites lexicales (CST, IF, ADD, ...) sont
 * definis dans tp_y.h
 * Des etiquettes symboliques qui ne correspondent pas a des tokens sont aussi
 * definies dans tp.h
 * 
 * Les "return" qui apparaissent dans les actions associees aux expressions
 * reguleres peuvent renvoyer:
 * - soit le code symbolique d'une U.L.
 * - soit un simple caractere
 * L'eventuelle partie "valeur" de l'U.L. doit etre stockee dans une des
 * variantes de la variable yylval (definie comme etant de type YYSTYPE)
 * afin que les outils compagnons de l'analyseur lexical puisse l'y recuperer.
 * Attention: le contenu de yylval va etre ecrase a chaque appel a l'analyseur
 * lexical et doit donc etre sauvegarde si besoin.
 */
%}

%%
{Entier} 	{ yylval.I = atoi(yytext); return(Cste); }
{Symbole}	{ return(yytext[0]); }
{Upper}{LC}*    { return TYPE;}
{Lower}{LC}*   { return keywordOrId(); }
{Delim}      {}
"+"			{return ADD;}
"-"			{return SUB;}
"*"			{return MUL;}
"/"			{return DV;}
":="		{ return(AFF); }
"="			{ yylval.C = EQ; return(RelOp); }
"<>"		{ yylval.C = NE; return(RelOp); }
"<="		{ yylval.C = LE; return(RelOp); }
">="		{ yylval.C = GE; return(RelOp); }
">"			{ yylval.C = GT; return(RelOp); }
"<"			{ yylval.C = LT; return(RelOp); }
%%
