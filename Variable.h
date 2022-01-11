#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    char* nom;
    bool varBoucle;
    Element *suivant;
};


typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};




Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    bool varBoucle=false;
    element->nombre = 0;
    element->nom="debut de liste";
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, char* n)
{
    
    Element *nouveau = malloc(sizeof(*nouveau));

    nouveau->nombre = 0;
    nouveau->nom = n;
    nouveau->varBoucle=false;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void setVal(Liste *liste,int nvNombre,char*n){
	Element *actuel = liste->premier;

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




void setVarBoucle(Liste *liste, char* n){
	Element *actuel = liste->premier;

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
	Element *actuel = liste->premier;

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
    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        //printf("%s = %d , %d\n",actuel->nom,actuel->nombre,actuel->varBoucle);
        actuel = actuel->suivant;
    }
}

bool chercherVar(Liste *liste, char* n)
{
	//printf("var checher est %s\n",n);
    Element *actuel = liste->premier;

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


/*
int main()
{
    Liste *maListe = initialisation();

    insertion(maListe, 4,"x");
    insertion(maListe, 8,"y");
    insertion(maListe, 15,"test");
	chercherVar(maListe,"test");
	chercherVar(maListe,"x");
	chercherVar(maListe,"y");
	chercherVar(maListe,"a");
    afficherListe(maListe);

    return 0;
}
*/



