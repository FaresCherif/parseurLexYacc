#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void insertion(Liste *liste, int nvNombre,char* n)
{
    
    Element *nouveau = malloc(sizeof(*nouveau));

    nouveau->nombre = nvNombre;
    nouveau->nom = n;

    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}



void afficherListe(Liste *liste)
{
    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%s = %d\n",actuel->nom,actuel->nombre);
        actuel = actuel->suivant;
    }
}

bool chercherVar(Liste *liste, char* n)
{
    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
	if(actuel->nom != n){
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



