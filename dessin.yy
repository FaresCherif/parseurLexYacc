%{
#include <stdio.h>
#include "Position.h"
#include "Variable.h"
#ifdef  __cplusplus
extern "C" {
#endif
	
#ifdef  __cplusplus
}
#endif

int yylex();

int yyerror(const char *s);
extern FILE *yyin;

struct Position p;
struct Liste *maListe;

char* couleur="noir";
char** lvar;
int lancerParseur(char* s);
bool chercherVar(Liste*,char*);

void afficherListe(Liste *);

bool isVarBoucle(Liste *, char* );
void setVarBoucle(Liste *, char* );
int getVal(Liste *,char*);
void setVal(Liste *,int ,char*);
void insertion(Liste *, char* );

Liste *initialisation();

%}


%union {
        int num;
	char *variable;
}

%token fin plu moins fois diviser baisserCrayon leverCrayon debut
%token bleu rouge noir colSymb virgule chevronOuvrant assigne parOuvrant parFermant ligne carree decla
%token<num> nombreD
%token<variable> var

%start S

%type<num> DESSIN NOMBRE CALCUL DESSINER COULEUR BOUCLE FINBOUCLE DEPLACERCRAYON DESSING X OPERATION
%type<num> DESSINERLIGNE DESSINERCARREE LIGNE CARREE BOUCLEVALFINAL
%type<variable> VARIABLE BOUCLEVAR
%type<variable> DECLARERVALEUR DEC

%%

S : DEBUTPROGRAMME DESSIN {printf("fin programme\n\n");afficherListe(maListe);return 0;}

DEBUTPROGRAMME : debut {maListe = initialisation();}

DESSIN : DESSING DESSIN {}
| fin {}
;

DESSING :
DEBUTDESSIN DESSINER leverCrayon fin {printf("dessin fini ");}
| BOUCLE fin {printf("boucle fini\n");}
| INITVALEUR fin {printf("valeur initialiser\n");}
| DECLARERVALEUR fin {printf("declarer valeur %s\n",$1);}
| COULEUR fin {printf("changer couleur\n");}

DESSINERLIGNE :  LIGNE parOuvrant NOMBRE virgule NOMBRE parFermant parOuvrant NOMBRE virgule NOMBRE parFermant {
	printf("trait de %d,%d a %d,%d en %s\n",$3,$5,$8,$10,couleur);
}
;

LIGNE : ligne {printf("ligne\n");}

INITVALEUR : DEC var {printf("valeur initialiser");insertion(maListe,$2);}
;

DEC : decla {printf("declar");}

DESSINERCARREE : CARREE parOuvrant NOMBRE virgule NOMBRE parFermant parOuvrant NOMBRE virgule NOMBRE parFermant {
	//visitCarree();
	printf("trait de %d,%d a %d,%d en %s\n",$3,$5,$8,$5,couleur);
	printf("trait de %d,%d a %d,%d en %s\n",$8,$5,$8,$10,couleur);
	printf("trait de %d,%d a %d,%d en %s\n",$8,$10,$3,$10,couleur);
	printf("trait de %d,%d a %d,%d en %s\n",$3,$10,$3,$5,couleur);
}

CARREE : carree{
	printf("carree\n");
}

DEPLACERCRAYON : parOuvrant NOMBRE virgule NOMBRE parFermant {
	printf("trait de %d,%d a %d,%d en %s\n",p.posX,p.posY,$2,$4,couleur);
	p.posX=$2;
	p.posY=$4;
}

DECLARERVALEUR : VARIABLE assigne NOMBRE {
	if(!chercherVar(maListe,$1)){
		yyerror("variable non declare");
		return 2;
	}

        if(isVarBoucle(maListe,$1)){
		printf("variable boucle \n\n");
		yyerror("affectation a var boucle");
		return 2;
	}
	else{
		printf("%s n'est pas boucle :\n\n",$1); 
	}
	setVal(maListe,$3,$1);
	printf("variable declare est : %s\n",$1);$$=$1;
}
;

VARIABLE : var {char* v =$1;$$=v;printf("variable est %s\n",$1);}

BOUCLEVAR : chevronOuvrant var virgule NOMBRE virgule {
printf("boucle sur %s",$2);
if(!chercherVar(maListe,$2)){
        yyerror("variable non initialise");
	return 2;
        }
        else{
                setVarBoucle(maListe,$2);
		setVal(maListe,$4,$2);
        }
	
	$$=$2;
}
;



BOUCLEVALFINAL : NOMBRE parFermant {$$=$1;}

BOUCLE : BOUCLEVAR BOUCLEVALFINAL DESSIN FINBOUCLE {

printf("%d <= %d",getVal(maListe,$1),$2);

if(getVal(maListe,$1)>=$2){
	yyerror("boucle negative ou null");
       	return 2;
}
setVarBoucle(maListe,$1);
setVal(maListe,$2,$1);
}
;

FINBOUCLE : {
	printf("fin boucle\n");
}
;

DEBUTDESSIN : baisserCrayon NOMBRE virgule NOMBRE {
	p.posX=$2;p.posY=$4;
	printf("Dessin commence a : %d , %d\n",$2,$4);
}
;

DESSINER : DESSINERG DESSINER {}
| fin {};

DESSINERG :COULEUR fin
| DEPLACERCRAYON fin {printf("deplacer crayon\n");}
| INITVALEUR fin {printf("valeur initialiser\n");}
| DECLARERVALEUR fin {printf("declarer valeur\n");}
| DESSINERLIGNE fin {printf("ligne dessiner\n");}
| DESSINERCARREE fin {printf("carree dessiner\n");}
| fin {}
;

COULEUR : colSymb COL {
	printf("couleur\n"); 
}

COL : bleu {printf("bleu\n");couleur=(char*)"bleu";}
| rouge {printf("rouge\n");couleur=(char*)"rouge";}
| noir {printf("noir\n");couleur=(char*)"noir";}
;

OPERATION : parOuvrant CALCUL parFermant {$$=$2;}

CALCUL : NOMBRE plu NOMBRE { printf("%d + %d\n",$1,$3);$$=$1+$3;}
| NOMBRE moins NOMBRE { printf("%d - %d\n",$1,$3);$$=$1-$3;}
| NOMBRE fois NOMBRE { printf("%d * %d\n",$1,$3);$$=$1*$3;}
| NOMBRE diviser NOMBRE { printf("%d / %d\n",$1,$3);$$=$1/$3;}
;

NOMBRE: X {$$=$1;}
| var {$$=getVal(maListe,$1);}
| OPERATION {$$=$1;}
;

X :
nombreD {$$=$1;printf("%d",$1);}
;

%%

int main(int argc, char *argv[])
{
	lancerParseur(argv[1]);
}

int lancerParseur(char* fichier){
	
        printf("Application dessin \n");
        yyin=fopen(fichier,"r+");
        if(yyin==NULL)
        {
                printf("\n Error ! \n");
                return 1;
        }
        else
        {
                yyparse();
		return 0;
	}
}


int yyerror(s)
const char *s;
{
	fprintf(stderr, "%s\n",s);
	return(2);
}

int yywrap()
{
	return(1);
}






Liste *initialisation()
{
    Liste *liste = (Liste *)malloc(sizeof(*liste));
    Element *element = (Element *)malloc(sizeof(*element));

    bool varBoucle=false;
    element->nombre = 0;
    element->nom=(char*)"debut de liste";
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, char* n)
{
    
    Element *nouveau = (Element *)malloc(sizeof(*nouveau));

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


int getVal(Liste *liste,char*n){
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
                        return actuel->nombre;
                        actuel=actuel->suivant;
                }
        }
	return 0;
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
        printf("%s = %d , %d\n",actuel->nom,actuel->nombre,actuel->varBoucle);
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

