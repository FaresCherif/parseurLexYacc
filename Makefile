

SRC=affect.cc  var.cc block.cc  cond.cc  decl.cc  couleur.cc float.cc  ope.cc  while.cc ligne.cc carree.cc seq.cc printer.cc lex.yy.c parser.tab.cc main.cc 
SRCH=affect.hh CImg.h var.hh  block.hh  cond.hh  decl.hh  expr.hh couleur.hh  float.hh  inst.hh  ope.hh  term.hh  while.hh ligne.hh carree.hh
FLAGS =-lX11 -lpthread -ll -DDEMO
OBJ=$(SRC:.cc=.o)

demo: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(FLAGS)
# -DDEMO pour faire la demo

lex.yy.c: lexer.ll parser.tab.cc
	flex $<

parser.tab.cc: parser.yy
	bison -d $<

clean:
	rm -fr $(OBJ) *~ lex.yy.c parser.tab.cc parser.tab.hh


.PHONY: clean
