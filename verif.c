#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

extern char *strdup(const char*);

extern void setError(int code);

ClassP getClass(ClassP listC, char *name)
{
    ClassP temp=listC;
    while(temp!=NULL)
    {
        if(strcmp(name, temp->name)==0)
            { return temp; }
        temp=temp->next;
    }
    printf("\nClasse %s non existante...\n", name);
    return NIL(Class);
}

bool checkOverride(ClassP list, ClassP listTemp){
	if(list != NULL) {
		bool retour = checkOverride(list->next, listTemp);
		
		if(list->super == NULL) {
			MethodP temp = list->method;
			
			while(temp != NULL) {
				if(temp->over) {printf("\nPresence d'un override dans la classe %s qui n'a pas de super\n", list->name); return FALSE;}
				temp = temp->next;
			}
		}
		
		else {
			MethodP temp = list->method;
			
			while(temp != NULL) {
				if(temp->over && !checkSuper(list, temp, listTemp)) {printf("\nAucune methode correspondant a %s dans le(s) super(s)\n", list->method->name); return FALSE;}
				temp = temp->next;
			}
			
			return retour;
		}	
	}
	
	return TRUE;	
}

bool checkSuper(ClassP class, MethodP method, ClassP list) {
	if(class != NULL) {
		bool retour;
		if(class->super != NULL) {
			ClassP super = getClass(list, class->super);
			printf("%s\n", method->name);
			retour = checkSuper(super, method, list);
		}
		else retour = FALSE;
		
		while(class->method != NULL) {
			if(strcmp(method->name, class->method->name)==0) {
				if(strcmp(method->type, class->method->type)==0) {
					VarDeclP argTemp = method->args;
					VarDeclP argTempClass = class->method->args;
					while(argTemp != NULL && argTempClass != NULL) {
						if(strcmp(argTemp->varType, argTempClass->varType)==0) return TRUE;
						argTemp = argTemp->next;
						argTempClass = argTempClass->next;
					}
					else return FALSE;
				}
				else return FALSE;
			}
			return retour;
		}
	}
	return ;
}

bool circuitHeritage(ClassP list, ClassP listTemp) {
	if(list != NULL) {
		bool retour = circuitHeritage(list->next, listTemp);
		
		ClassP temp = list;
		char* nomTemp = list->name;

		while(temp->super != NULL) {
			if(strcmp(nomTemp, temp->super)==0) {printf("\nCircuit d'heritage repere...\n"); return FALSE;}
			temp=getClass(listTemp, temp->super);
		}
		
		return retour;
	}
	
	return TRUE;
}

void printClass(ClassP list) {
	ClassP temp = list;

	while(temp != NULL) {
		printf(temp->name);
		temp=temp->next;
	}
}
