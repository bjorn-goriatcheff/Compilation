#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

extern char* strdup(const char *);

int etifin=0;


//Création des etiquettes pour la génération de code

char* newLabel(){
	

	char* eti=NULL;
	printf("Etiquette : %d",etifin);
	etifin=etifin+1;
	return eti;
	
}
