/* les tokens ici sont ceux supposes etre renvoyes par l'analyseur lexical
 * Doit donc etre en coherence avec tp.l
 * Ces tokens sont traduites en constantes entieres dans tp_y.h qui est
 * importe par tp.l
 * Bison ecrase le contenu de tp_y.h a partir de la description de la ligne
 * suivante. C'est donc cette ligne qu'il faut adapter si besoin, pas tp_y.h !
 */

/* voir la definition de YYSTYPE dans main.h
 * S et C sont des etiquettes de variantes dans le type union YYSTYPE
 */
%token IF THEN ELSE BEG END ADD SUB
%token <S> ID STR
%token <I> CST
%token <C> RELOP

/* indications de precedence (en ordre croissant) et d'associativite. Les
 * operateurs sur une meme ligne (separes par un espace) ont la meme priorite.
 */
%left ADD SUB

/* Dans un second temps ajouter les clauses %type selon le type de la valeur
 * stocke dans l'zattribut semantiquer pour chaque non-terminal qui en est dote.
 * Format:
%type >Etiquette> liste-des-non-terminaux qui ont un attribut de ce type.
 */

%{
#include "tp.h"     /* les definition des types et les etiquettes des noeuds */

extern int yylex();	/* fournie par Flex */
extern void yyerror();  /* definie dans tp.c */
%}

%% 
/* Pour l'instant on n'accepte qu'une liste vide de declarations !
 * Ici, pour representer les declarations, il y a deux solutions:
 * Solution 1.
 *  A. On garde l'expression en partie droite d'expression sous forme d'un
 * AST et on represente une declaration sous forme d'un noude d'AST qui lie la
 * variable en partie gauche avec l'AST qui represente la partie droite
 * B. on cree des noeuds dans l'AST pour lier toutes les declarations dans
 * le bon ordre. 
 * Quand on est au niveau de l'axiome, on dispose donc de l'AST qui represente
 * l'ensemble des declarations, et l'AST qui represente l'expression finale.
 * C. on parcourt tout cela de facon intelligente pour trovuer la valeur de
 * chaque variable et la valeur de l'expression finale.
 *
 * Dans cette solution, toutes les actions sauf celle pour l'axiome consistent
 * à construire un nouvel AST en fonction des AST des enfants.
 *
 * Solution 2: on va evaluer les expressions dans les declarations des que
 * possible en construiisant au fur et a mesure une liste qui represente
 * l'environnemnt (couples clef/valeur) qui existe a l'entree de la nouvelel
 * declaration.
 * A. On construit un environnement initialement vide
 * B. des qu'on a une expression complete en partie droite, on la verifie
 * et on l'evalue en fonction de l'environnement courant. On ajoute un nouveau
 * couple clef/valeur dans l'environnement
 * Dans la regle de l'axiome, il suffit donc d'evaluer l'expression finale
 * dans l'environnement qui existera a ce moment de l'analyse.
 *
 * Dans cette solution, certaines actions construisent des AST tandis que
 * d'autres actions evaluent un AST et gerent l'environnement.
 */
programme : declLOpt BEG expr END 
;


declLOpt :
;


expr : IF bexpr THEN expr ELSE expr
| expr ADD expr
| expr SUB expr
| CST
| ID
| '(' expr ')'
;

/* Expression booleenne seulement presente dans un IF */ 
bexpr : expr RELOP expr 
| '(' bexpr ')'
;

