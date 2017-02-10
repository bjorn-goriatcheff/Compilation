#include "tp.h"
#include <string.h>

void afficheEnv(EnvP glob, bool aff){
	if(aff==TRUE){
		printf("affichage de l'environnement \n");
	}
	if(glob!=NULL){
		afficheVarDecl(glob->var);
		afficheEnv(glob->next, FALSE);
	}
	else{
		printf("fin affichage \n");
	}
}

void afficheVarDecl(VarDeclP varL){
	if(varL!=NULL){
		char* var=varL->name;
		printf("variable %s \n", var);
		afficheVarDecl(varL->next);		
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
	/* Pointeurs vers le debut de la liste des classes */
	ClassP debut = classL;
	/* pointeur vers le premier env */
	EnvP debutE = glob;
	/* remplissage recurssif */
	glob=rempliEnv(classL, debut, debutE, glob);
	/* verif compatibilité glob/loc recurrsif */
	afficheEnv(glob, TRUE);
	//ATTENTION TRUE TEMPORAIRE
	return TRUE;

}

EnvP rempliEnv(ClassP classL, ClassP deb, EnvP debE, EnvP glob){
	if(classL->next!=NULL){
		/* sans heritage */
		if(classL->next->super==NULL){
			glob->next=creerEnv(classL->next);
		}
		else {
			//Remplissage temporaire
			glob->next=creerEnv(classL->next);
			
			//char* mere=classL->next->super;
			//EnvP filleE = creerEnv(classL->next);
			//EnvP mereE = checkEnv(mere,deb);
			//glob->next=envCat(mereE, filleE);
		}

		rempliEnv(classL->next, deb, debE, glob->next);		
	}
	return glob;
}


EnvP creerEnv(ClassP classL){
	EnvP glob = NEW(1, Env);
	/* Construction env initial */
	
	glob->var=classL->var;
	glob->method=classL->method;
	classL->env=glob;
	return glob;
}

EnvP checkEnv(char* mere, ClassP classL){
	if(classL!=NULL){
		if(strcmp(mere, classL->name)==0){
			return classL->env;
		}
		else{
			checkEnv(mere, classL->next);

		}	
	}
	return NULL;
}



/* EnvCat masque les champs ddeja existant dans la mère et copie le reste dans l'env de la fille 
	Mise à jour de l'environnement de la fille (Enrichissement)

*/
EnvP envCat(EnvP envM, EnvP envF){
	VarDeclP tempV = NEW(1, VarDecl);
	//copie des champs
	if(envM->var!=NULL){
		envVarCat(envM->var, envF->var, tempV);
	}
	//envF->var->next=tempV;
	return envF;
}
/* On deverse les variables non présentes dans la fille dans temp */
void envVarCat(VarDeclP mere, VarDeclP fille, VarDeclP temp){
	if(mere!=NULL){
		/*if(!isVarInEnv(mere, fille)){
			temp=mere;
			temp->next=NULL;
			envVarCat(mere->next, fille, temp->next);
		}*/
	}
	else{
		temp=NULL;
	}
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




 
	

			
