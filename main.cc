#include "printer.hh"
extern FILE *yyin;


#include "parser.tab.hh"


Instruction *fullinstruction = NULL; // variable retenant le resultat final du parser...


int main(int argc, char **argv) {

	
	yyin=fopen(argv[1],"r+");
        if(yyin==NULL)
        {
                printf("\n Error ! \n");
                return 1;
        }
        else
        {
                yyparse();
		Printer printer;
  		if(fullinstruction)
    		fullinstruction->visit(printer);
		return 0;
	}

  

  return 0;
}
