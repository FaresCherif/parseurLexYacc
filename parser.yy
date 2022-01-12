%{
 /* Fais un copier coller dans le fichier parser.tab.hh */
#include <iostream>
#include "printer.hh"	
#include <stdio.h>
#include "Position.h"
#include "Variable.h"

using namespace std;
int lancerParseur(char* s);
void yyerror(const char *s) { std::cerr<<"ERREUR: "<<s<<std::endl; }
extern int yylex();
int lancerParse(char *s);

extern FILE *yyin;

struct Position p;
struct Liste *maListe;

char* couleur=(char*)"noir";
char** lvar;

bool chercherVar(Liste*,char*);

void afficherListe(Liste *);

bool isVarBoucle(Liste *, char* );
void setVarBoucle(Liste *, char* );
int getVal(Liste *,char*);
void setVal(Liste *,int ,char*);
void insertion(Liste *, char* );

Liste *initialisation();

%}



%code requires {
  /* Fais un copier coller dans le fichier parser.tab.cc */
  #include "printer.hh"

}


%union {
        int num;
	char *variable;
	Instruction* instr;
	Expression* expr;
	Carree*  care;
	Ligne* lign;
	Affect* af;
}

%token fin plu moins fois diviser baisserCrayon leverCrayon debut
%token bleu rouge noir colSymb virgule chevronOuvrant assigne parOuvrant parFermant ligne carree decla
%token<num> nombreD
%token<variable> var

%start S

%type<num> DESSIN NOMBRE CALCUL DESSINER COULEUR BOUCLE FINBOUCLE DESSING X OPERATION
%type<num> LIGNE CARREE BOUCLEVALFINAL
%type<variable> VARIABLE BOUCLEVAR
%type<variable> DEC
%type<instr> INITVALEUR 
%type<care> DESSINERCARREE 
%type<lign> DEPLACERCRAYON DESSINERLIGNE 
%type<af> DECLARERVALEUR 

%%

S : DEBUTPROGRAMME DESSIN {printf("fin programme\n\n");afficherListe(maListe);YYACCEPT;;}

DEBUTPROGRAMME : debut {maListe = initialisation();}

DESSIN : DESSING DESSIN {}
| fin {}
;

DESSING :
DEBUTDESSIN DESSINER leverCrayon fin {printf("dessin fini ");}
| BOUCLE fin {printf("boucle fini\n");}
| INITVALEUR fin {printf("valeur initialiser\n");}
| DECLARERVALEUR fin {printf("declarer valeur \n");}
| COULEUR fin {printf("changer couleur\n");}

DESSINERLIGNE :  LIGNE parOuvrant NOMBRE virgule NOMBRE parFermant parOuvrant NOMBRE virgule NOMBRE parFermant {
	printf("trait de %d,%d a %d,%d en %s\n",$3,$5,$8,$10,couleur);
	Float* x1= new Float($3);
	Float* x2=new Float($8);
	Float* y1 = new Float($5);
	Float* y2 = new Float($10);
	Ligne* l1 = new Ligne(x1,y1,x2,y1);
	
	$$=l1;	
}
;

LIGNE : ligne {printf("ligne\n");}

INITVALEUR : DEC var {printf("valeur initialiser");insertion(maListe,$2); $$ = new Decl($2); free($2);}
;

DEC : decla {printf("declar");}

DESSINERCARREE : CARREE parOuvrant NOMBRE virgule NOMBRE parFermant parOuvrant NOMBRE virgule NOMBRE parFermant {
	//visitCarree();
	printf("trait de %d,%d a %d,%d en %s\n",$3,$5,$8,$5,couleur);
	printf("trait de %d,%d a %d,%d en %s\n",$8,$5,$8,$10,couleur);
	printf("trait de %d,%d a %d,%d en %s\n",$8,$10,$3,$10,couleur);
	printf("trait de %d,%d a %d,%d en %s\n",$3,$10,$3,$5,couleur);
	Float* x1= new Float($3);
	Float* x2=new Float($8);
	Float* y1 = new Float($5);
	Float* y2 = new Float($10);
	Ligne* l1 = new Ligne(x1,y1,x2,y1);
	Ligne* l2 = new Ligne(x2,y1,x2,y2);
	Ligne* l3 = new Ligne(x2,y1,x1,y2);
	Ligne* l4 = new Ligne(x1,y2,x1,y1);
	Carree *c = new Carree(l1,l2,l3,l4);

	$$=c;
	Sequence *seq = new Sequence();
	seq->add(c);
	Printer printer;
  	seq->visit(printer);
}

CARREE : carree{
	printf("carree\n");
}

DEPLACERCRAYON : parOuvrant NOMBRE virgule NOMBRE parFermant {
	printf("trait de %d,%d a %d,%d en %s\n",p.posX,p.posY,$2,$4,couleur);

	Float* x1= new Float(p.posX);
	Float* x2=new Float($2);
	Float* y1 = new Float(p.posY);
	Float* y2 = new Float($4);

	Ligne* l1 = new Ligne(x1,y1,x2,y1);
	

	p.posX=$2;
	p.posY=$4;

	$$=l1;
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
	Float* f = new Float($3);
	Affect* a = new Affect($1,f);

	setVal(maListe,$3,$1);
	
	printf("variable declare est : %s\n",$1);
	
	$$=a;
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

int lancerParse(char* fichier){
	maListe = initialisation();
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













