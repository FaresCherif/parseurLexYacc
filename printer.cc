//Fares Cherif
#include "printer.hh"
#include <iostream>

using namespace std;
using namespace cimg_library;

int sizeX = 800, sizeY = 800;


const unsigned char red[] = { 255, 0 , 0 };
const unsigned char green[] = { 0, 255 , 0 };
const unsigned char blue[] = { 0, 0 , 255 };




void Printer::visitFloat(const Float *f) {
  cout<<f->getValue();
}

void Printer::visitVar(const Var *v) {
  cout<<v->getIdent();
}


void Printer::visitOperator(const Operator *o) {
  cout<<"(";
  o->getLeft()->visit(*this);
  switch(o->getSymbol()) {
  case PLUS: cout<<"+"; break;
  case MOINS: cout<<"-"; break;
  case MULT: cout<<"*"; break;
  case DIV: cout<<"/"; break;
  case INF: cout<<"<"; break;
  case INFEG: cout<<"<="; break;
  case SUP: cout<<">"; break;
  case SUPEG: cout<<">="; break;
  case EGALITE: cout<<"=="; break;
  case DIFF: cout<<"!="; break;
  default: cout<<" ??? "; break;
  }
  o->getRight()->visit(*this);
  cout<<")";
}

void Printer::visitAffect(const Affect *a) {
  cout<<a->getVar()<<" = ";
  a->getExpr()->visit(*this);
  cout<<";"<<endl;
}

void Printer::visitCouleur(const Couleur *c){
  cout<<"visite couleur";
}

void Printer::visitBlock(const Block *b) {
  cout<<"{"<<endl;
  b->getBody()->visit(*this);
  cout<<"}"<<endl;
}

void Printer::visitCond(const Cond *c) {
  cout<<"if(";
  c->getCond()->visit(*this);
  cout<<")"<<endl;
  c->getCons()->visit(*this);
  cout<<endl<<"else"<<endl;
  c->getAlt()->visit(*this);
}

void Printer::visitDecl(const Decl *d) {
  cout<<"var "<<d->getVar()<<";"<<endl;
}

void Printer::visitWhile(const While *w) {
  cout<<"de ";
  w->getMin()->visit(*this);
  cout<<" a ",
  w->getMax()->visit(*this);
  cout<<" : "<<endl;
  w->getBody()->visit(*this);
  cout<<"fin boucle";
}

void Printer::visitLigne(const Ligne *l) {
  cout<<"trace ligne de : "<<l->getX1()->getValue()<<","<<l->getY1()->getValue()<<" a "<<l->getX2()->getValue()<<" "<<l->getY2()->getValue()<<" en "<<l->getCouleur()<<"\n";
  image.draw_line(l->getX1()->getValue(), l->getY1()->getValue(), l->getX2()->getValue(), l->getY2()->getValue(), blue);
//image.save_bmp("toto2.bmp");
 // cout<<"fin ligne";
//image.draw_line(150,150,700,700, blue);
}

void Printer::visitCarree(const Carree *c){
c->getL1()->visit(*this);
c->getL2()->visit(*this);
c->getL3()->visit(*this);
c->getL4()->visit(*this);
}

void Printer::visitSeq(const Sequence *s) {

image= CImg<unsigned char>(sizeX, sizeY, 1, 3);

//image.fill(255); // on remplit en blanc
//image.draw_line(100,200,300,400, green);

  //cout<<"ATTENTION Inversion possible (en fct de votre algo)!"<<endl;
  SeqItem *t = s->getFirst();
//image.draw_line(0, 200, 500, 500, green);
  while(t != NULL) {
    t->getInst()->visit(*this);
    //printf("sequence");
    t = t->getNext();
  }




	image.save_bmp("toto.bmp");

  //cout<<"ATTENTION Inversion possible (en fct de votre algo)!"<<endl;
}
