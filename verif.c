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
/** 
 * program : programme à vérifier
 * ClassInProg : liste de toutes les classes déclarées dans le programme
**/
bool checkProgram (TreeP program, ClassP ClassInProg)
{
	if(program==NULL)
		return FALSE;
	bool blocChecked = FALSE; /*les blocs sont OK ou pas */
	
	/* Accès au bloc principal */
	TreeP actualBloc=getChild(program,1);
	//On check les blocs
	if(getChild(actualBloc,0)!=NULL) /* On a des declarations de var*/
	{	printf("\n\tDeclaration de var");
		blocChecked = checkBloc(actualBloc, getChild(actualBloc,0)->u.lvar);
	}
	else /* On n'a pas de déclaration de variables */
		blocChecked = checkBloc(actualBloc, NULL);
	
	//si les deux sont OK, le prog est OK
	return blocChecked;
}
	
bool checkBloc(TreeP bloc, VarDeclP listDec)
{
	if (bloc == NULL) /* Rien à checker*/
	{	printf("\n\t\tincheckBloc, bloc=NULL");
		return TRUE;
	}
	
	if(bloc->op==INST || bloc->op==RETURN || bloc->op==AS)
	{
		return checkBloc(getChild(bloc,0),listDec);
	}
	if (bloc->op==AFF) /* si affectation : on verifie le type */
	{		printf("\n\t\tincheckBloc, AFFEC");
		char* typeVar = getType(getChild(bloc,0) );
		char* typeVal = getType(getChild(bloc,1) );
		return checkType(typeVar,typeVal);
	}
	if(bloc->op==ITE)
	{					/*expression | instruction | instruction */
		return checkBloc(getChild(bloc,0),listDec) 
				&& checkBloc(getChild(bloc,1),listDec)
				&& checkBloc(getChild(bloc,2),listDec);
	}
	if(bloc->op==AND || bloc->op==EADD || bloc->op==EMINUS || bloc->op==EMULT || bloc->op==EDIV || bloc->op==NE
		|| bloc->op==EQ || bloc->op==LT || bloc->op==LE	||bloc->op==GT || bloc->op==GE)
	{
		return checkBloc(getChild(bloc,0),listDec) 
			&& checkBloc(getChild(bloc,1),listDec);
	}
	
	if	(bloc->op==ISBLOCK) /* Si c'est un block */
	{
		printf("\n\t\tincheckBloc, ISBLOC");
		if(listDec != NULL && getChild(bloc,1)==NULL ) /* On a la liste des déclarations mais pas d'instructions */
			return FALSE;
		/* On va verifier la liste de declaration*/
		if( checkDecl(getChild(bloc,0), listDec)==FALSE )
			return FALSE;
		/* On verifie les instructions */
		return checkInstructions(getChild(bloc,1) , listDec); // A FAIRE 
	}
	printf("\n\t\tfincheckBloc : op = %d, children = %d ",bloc->op, bloc->nbChildren);
	return FALSE;		
}

bool checkDecl(TreeP bloc, VarDeclP listDec)
{
	VarDeclP temp= listDec;
	
	while (temp != NULL)
		if(temp->varType==NULL) /*Pas de type*/
			return FALSE;
		if(temp->expr==NULL) /* Pas d'expr */
			return FALSE;
		char* exprType = getType( getChild(temp->expr,0));
		if(checkType(temp->varType, exprType)==FALSE) /*Problème de typage*/
			return FALSE;
		temp=temp->next;
	return TRUE;
}


char* getType(TreeP t)
{
	if(t->op==Cste)
		return "Interger";
	if(t->op==IDVAR || t->op==Id)
		return "String";
	return t->u.lvar->varType;
}

bool checkType(char* va, char* vb)
{
	if(strcmp(va,vb)==0)
		return TRUE;
	printf("Erreur : types différents (%s VS %s)",va,vb);
	return FALSE;
}

bool checkAttribut(VarDeclP var)
{ //Vérifier qu'un attribut existe et n'est pas présent 2 fois dans la liste
	return TRUE;
}

bool checkInstructions(TreeP bloc , VarDeclP var)
{
	
	return TRUE;
}

bool checkListMethod(ClassP c)
{
	return TRUE;
}
