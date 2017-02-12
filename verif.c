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

void attribSuper(ClassP list) { //complete le champ superC avec la classe correspondante au champ super
	ClassP temp = list;
	
	while(temp != NULL) {
		temp->superC = getClass(list, temp->super);
		temp = temp->next;
	}
}

void attribType(ClassP list) {
	ClassP temp = list;
	
	while(temp != NULL) {
		attribTypeChamp(temp->var, list);
		attribTypeMeth(temp->method, list);
		temp = temp->next;
	}
}

void attribTypeChamp(VarDeclP listChamps, ClassP list) {
	VarDeclP temp = listChamps;
	
	while(temp != NULL) {
		temp->varTypeC = getClass(list, temp->varType);
		temp = temp->next;
	}
}

void attribTypeMeth(MethodP listMeth, ClassP list) {
	MethodP temp = listMeth;
	
	while(temp != NULL) {
		temp->typeC = getClass(list, temp->type);
		attribTypeBlock(temp->body, list);
		temp = temp->next;
	}
}

void attribTypeBlock(TreeP bloc, ClassP list) {
	for(int i = 0; i < bloc->nbChildren; i++) {
		TreeP child = bloc->u.children[i];
		if(child != NULL) attribTypeBlock(child, list);
	}
	
	if(bloc->op == BLOCK) {
		VarDeclP var = bloc->u.children[0]->u.lvar;
		while(var != NULL) {
			var->varTypeC = getClass(list, var->varType);
			var = var->next;
		}
	}
}

bool checkDoublonClass(ClassP list) { // TRUE si plusieurs classes ont le meme nom
	ClassP temp = list;
	bool retour = FALSE;
	
	while(temp != NULL) {
		ClassP temp2 = list;
		while(temp2 != NULL) {
			if(temp != temp2 && strcmp(temp->name, temp2->name) == 0) {printf("\nLa classe %s existe plusieurs fois.", temp->name); retour = TRUE;}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	
	return retour;
}
