#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

extern char *strdup(const char*);

extern void setError(int code);

ClassP getClass(ClassP listC, char *name)
{
    if(name != NULL) {
		ClassP temp=listC;
	    while(temp!=NULL)
	    {
	        if(strcmp(name, temp->name)==0) return temp;
	        temp=temp->next;
	    }
	    printf("\nClasse %s non existante...", name);
	    setError(CONTEXT_ERROR);
	}
    return NIL(Class);
}

bool pbOverride(ClassP list){ //retourne TRUE s'il y a un probleme
	if(list != NULL) {
		bool retour = pbOverride(list->next);
		
		if(list->super == NULL) {
			MethodP temp = list->method;
			
			while(temp != NULL) {
				if(temp->over) {printf("\nPresence d'un override dans la classe %s qui n'a pas de super\n", list->name); retour = TRUE;}
				temp = temp->next;
			}
		}
		
		else {
			MethodP temp = list->method;
			
			while(temp != NULL) {
				if(temp->over && !checkSuper(list->superC, temp)) {printf("\nAucune methode correspondant a %s dans le(s) super(s) de %s\n", temp->name, list->name); retour = TRUE;}
				temp = temp->next;
			}
		}
		
		return retour;	
	}
	
	return FALSE;	
}

bool checkSuper(ClassP class, MethodP method) { //retourne TRUE si une methode correspondante a ete trouvee dans les supers
	if(class != NULL) {
		bool retour = checkSuper(class->superC, method);
		
		if(isMethodInClass(method, class)) return TRUE;
		
		else return retour;
	}
	return FALSE;
}

bool isMethodInClass(MethodP method, ClassP class) { //retourne TRUE si method dans class->method
	bool retour = FALSE;
	MethodP metTemp = class->method;
	
	while(metTemp != NULL) {
		if(strcmp(method->name, metTemp->name) == 0) {
			if(method->type != NULL && metTemp->type != NULL && strcmp(method->type, metTemp->type) == 0) {
				if(areArgTypeTheSame(method->args, metTemp->args)) retour = TRUE;
			}
			
			else if(method->type == NULL && metTemp->type == NULL) {
				if(areArgTypeTheSame(method->args, metTemp->args)) retour = TRUE;
			}
		}
		metTemp = metTemp->next;
	}
	return retour;
}

bool areArgTypeTheSame(VarDeclP arg1, VarDeclP arg2) { // retourn TRUE si tous les arguments on le meme type un a un
	bool retour = TRUE;
	while(arg1 != NULL && arg2 != NULL) {
		if(arg1->varType != NULL && arg2->varType != NULL && strcmp(arg1->varType, arg2->varType) != 0) retour = FALSE;
		arg1 = arg1->next;
		arg2 = arg2->next;
	}
	
	if(arg1 != NULL || arg2 != NULL) retour = FALSE;
	
	return retour;
}

bool circuitHeritage(ClassP list) { //retourne TRUE si le programme contient un circuit
	if(list != NULL) {
		bool retour = circuitHeritage(list->next);
		
		ClassP temp = list->superC;
		char* nomTemp = list->name;

		while(temp != NULL) {
			if(temp->super != NULL && strcmp(nomTemp, temp->super)==0) {printf("\nCircuit d'heritage repere..."); return TRUE;}
			temp=temp->superC;
		}
		
		return retour;
	}
	
	return FALSE;
}

void printClass(ClassP list) {
	ClassP temp = list;

	while(temp != NULL) {
		printf("%s", temp->name);
		temp=temp->next;
	}

}

