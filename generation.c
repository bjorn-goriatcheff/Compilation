#include "tp.h"


int etifin;


//Création des etiquettes pour la génération de code

char* newLabel(){
	
	etifin=0;
	char* eti;
	printf("Etiquette : %d",etifin);
	etifin=etifin+1;
	return eti;
	
}
