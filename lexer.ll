%{
#include "parser.tab.hh"

#include <stdio.h>

%}

%%
"DEBUTPROGRAMME" return(debut);
"DEC "	return(decla);
"carree"	return(carree);
"ligne"	return(ligne);
"("	return(parOuvrant);
")"	return(parFermant);
"<-"	return(assigne);
"Boucle("	return(chevronOuvrant);
","	return(virgule);
"Couleur : "	return(colSymb);
";"	return(fin);
"DebutDessin{"	return(baisserCrayon);
"}"	return(leverCrayon);
"+"	return(plu);
"-"	return(moins);
"*"	return(fois);
"/"	return(diviser);
BLEU	return(bleu);
ROUGE	return(rouge);
NOIR	return(noir);
[0-9]*	{ yylval.num = (float)atof(strdup(yytext));return(nombreD);};
[A-Za-z][A-Za-z0-9]*	{yylval.variable =strdup(yytext);return(var);};
. {return 1;}

%%

