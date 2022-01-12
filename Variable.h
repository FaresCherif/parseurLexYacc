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



