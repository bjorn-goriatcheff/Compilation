#include "tp.h"
#include <string.h>

void afficheEnv(EnvP glob, bool aff){
	if(aff==TRUE){
		printf("\n\nAffichage de l'environnement \n");
	}
	if(glob!=NULL){

		printf("classe %s\n", glob->name);

		afficheVarDecl(glob->var);
		afficheMeth(glob->method);
		afficheEnv(glob->next, FALSE);
	}
	else{
		printf("Fin de l'affichage \n");
	}
}

void afficheVarDecl(VarDeclP varL){
	if(varL!=NULL){
		char* var=varL->name;
		printf("variable %s \n", var);
		afficheVarDecl(varL->next);		
	}
}


void afficheMeth(MethodP methL){
	if(methL!=NULL){
		char* meth=methL->name;
		printf("methode %s \n", meth);
		afficheVarDecl(methL->args);
		//afficheBloc(methL->body);
		afficheMeth(methL->next);
	}
}

void afficheBloc(TreeP bloc){
	if(bloc->nbChildren==0){
		if(bloc->op==7){
			printf("variable %s \n", bloc->u.lvar->name);
		}
		if(bloc->op==13) printf("const %d \n", bloc->u.val);
		if(bloc->op==14) printf("string %s \n", bloc->u.str);
	}
	else{
		afficheBloc(bloc->u.children[0]);
	}
}

bool areArgNotTheSame(VarDeclP arg1, VarDeclP arg2) { // retourn TRUE si tous les arguments sont différents
	bool retour = FALSE;

	if(arg1 != NULL || arg2 != NULL) retour = TRUE;

	while(arg1 != NULL && arg2 != NULL) {
		if(arg1->name != NULL && arg2->name != NULL && strcmp(arg1->name, arg2->name) != 0) retour = TRUE;
		arg1 = arg1->next;
		arg2 = arg2->next;
	}
	
	return retour;
}



bool verifEnv(ClassP classL, TreeP bloc){
	EnvP glob = creerEnv(classL);
	/* remplissage recurssif */
	glob=rempliEnv(classL, glob);

	/* verif compatibilité glob/loc recurrsif */
	afficheEnv(glob, TRUE);
	
	return TRUE;

}

EnvP rempliEnv(ClassP classL, EnvP glob){
	if(classL->next!=NULL){
		
		glob->next=creerEnv(classL->next);
		rempliEnv(classL->next, glob->next);
	}
	return glob;
}

void creerEnvMet(MethodP metL, EnvP glob){
	glob->name=metL->name;
	glob->var=metL->args;
	//traitement du bloc de la methode
	
}


EnvP creerEnv(ClassP classL){
	EnvP glob = NEW(1, Env);
	/* Construction env initial */
	glob->name=classL->name;
	glob->var=classL->var;
	glob->method=classL->method;

	return glob;
}



bool checkEnv(char* mere, ClassP classL){
	if(classL!=NULL){
		if(strcmp(mere, classL->name)==0){
			return TRUE;
		}
		else{
			checkEnv(mere, classL->next);

		}	
	}
	return FALSE;
}



bool isVarInEnv(VarDeclP var1, VarDeclP var2){
	if(var2!=NULL){
		if(strcmp(var1->name, var2->name)==0){
			return TRUE;
		}
		else{
			return isVarInEnv(var1, var2->next);
		}
	}
	return FALSE;
}




 
	

			
