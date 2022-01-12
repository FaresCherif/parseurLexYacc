#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Variab Variab ;
struct Variab 
{
    int nombre;
    char* nom;
    bool varBoucle;
    Variab *suivant;
};


typedef struct Liste Liste;
struct Liste
{
    Variab *premier;
};


Liste *initialisation()
{
    Liste *liste = (Liste *)malloc(sizeof(*liste));
    Variab *element = (Variab *)malloc(sizeof(*element));

    bool varBoucle=false;
    element->nombre = 0;
    element->nom=(char*)"debut de liste";
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, char* n)
{
    
    Variab *nouveau = (Variab *)malloc(sizeof(*nouveau));

    nouveau->nombre = 0;
    nouveau->nom = n;
    nouveau->varBoucle=false;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void setVal(Liste *liste,int nvNombre,char*n){
	Variab  *actuel = liste->premier;

        while (actuel != NULL)
        {
                //printf("%s\n",actuel->nom);
                if(strcmp(actuel->nom,n)){
                        //printf("settage : %s != %s\n",actuel->nom,n);
                        actuel=actuel->suivant;
                }
                else{
                        //printf("settage : %s = %s\n",actuel->nom,n);
                     	actuel->nombre=nvNombre;
                        actuel=actuel->suivant;
                }
        }
}


int getVal(Liste *liste,char*n){
        Variab  *actuel = liste->premier;

        while (actuel != NULL)
        {
                //printf("%s\n",actuel->nom);
                if(strcmp(actuel->nom,n)){
                        //printf("settage : %s != %s\n",actuel->nom,n);
                        actuel=actuel->suivant;
                }
                else{
                        //printf("settage : %s = %s\n",actuel->nom,n);
                        return actuel->nombre;
                        actuel=actuel->suivant;
                }
        }
	return 0;
}


void setVarBoucle(Liste *liste, char* n){
	Variab  *actuel = liste->premier;

    	while (actuel != NULL)
    	{
        	//printf("%s\n",actuel->nom);
        	if(strcmp(actuel->nom,n)){
			//printf("settage : %s != %s\n",actuel->nom,n);
               		actuel=actuel->suivant;
        	}
        	else{
			//printf("settage : %s = %s\n",actuel->nom,n);
			if(actuel->varBoucle==false){
				actuel->varBoucle=true;
			}
			else{
				actuel->varBoucle=false;
			}
			actuel=actuel->suivant;
        	}
    	}
}


bool isVarBoucle(Liste *liste, char* n){
	Variab  *actuel = liste->premier;

        while (actuel != NULL)
        {
                //printf("%s\n",actuel->nom);
                if(strcmp(actuel->nom,n)){
                        //printf("varBoucle : %s != %s\n",actuel->nom,n);
                        actuel=actuel->suivant;
                }
                else{
                        //printf("varboucle : %s = %s %d\n",actuel->nom,n,actuel->varBoucle);
                        if(actuel->varBoucle==true){
                                return true;
                        }
			actuel=actuel->suivant;
                }
        }
	return false;
}

void afficherListe(Liste *liste)
{
    Variab  *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%s = %d , %d\n",actuel->nom,actuel->nombre,actuel->varBoucle);
        actuel = actuel->suivant;
    }
}

bool chercherVar(Liste *liste, char* n)
{
	//printf("var checher est %s\n",n);
    Variab  *actuel = liste->premier;

    while (actuel != NULL)
    {
	//printf("%s\n",actuel->nom);
	if(strcmp(actuel->nom,n)){
		//printf("%s != %s\n",actuel->nom,n);
		actuel=actuel->suivant;
	}
	else{
		
		return true;
	}
    }
	
	return false;

}