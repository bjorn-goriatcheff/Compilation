#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

extern char* strdup(const char *);

int etifin;


//Création des etiquettes pour la génération de code pour la condition If then Else

char* newLabel(){
	etifin=0;
	char* eti=NULL;
	printf("Etiquette : %d",etifin);
	etifin=etifin+1;
	return eti;
	
}

//Generation code Expression, remplissage champs code
/*void codeExpression(TreeP bloc,VarDeclP exp){
	if(bloc->op==NE){
		asprintf(&exp->code, "\n %s\n%s \t NEQ", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else 	if(bloc->op==LT){
		asprintf(&exp->code, "\n %s\n%s \t INF", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else	if(bloc->op==LE){
		asprintf(&exp->code, "\n %s\n%s \t INFEQ", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else 	if(bloc->op==GT){
		asprintf(&exp->code, "\n %s\n%s \t SUP", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else	if(bloc->op==GE){
		asprintf(&exp->code, "\n %s\n%s \t SUPEQ", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else	if(bloc->op==EQ){
		asprintf(&exp->code, "\n %s\n%s \t EQ", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else	if(bloc->op==EADD){
		asprintf(&exp->code, "\n %s\n%s \t ADD", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else	if(bloc->op==EMINUS){
		asprintf(&exp->code, "\n %s\n%s \t MINUS", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else	if(bloc->op==EMULT){
		asprintf(&exp->code, "\n %s\n%s \t MULT", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}else	if(bloc->op==EDIV){
		asprintf(&exp->code, "\n %s\n%s \t DIV", getChild(exp->expr, 0)->u.lvar->code, getChild(exp->expr, 1)->u.lvar->code);
	}
}*/



