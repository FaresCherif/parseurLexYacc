#ifndef _PRINTER_H
#define _PRINTER_H


#include "visitor.hh"
#include "while.hh"
#include "affect.hh"
#include "block.hh"
#include "cond.hh"
#include "decl.hh"
#include "float.hh"
#include "var.hh"
#include "ope.hh"
#include "seq.hh"
#include "ligne.hh"
#include "carree.hh"
#include "couleur.hh"
#include "CImg.h"

using namespace cimg_library;

class Printer : public Visitor {
public:
  CImg<unsigned char> image;

  void visitFloat(const Float *f);
  void visitVar(const Var *v);
  void visitOperator(const Operator *o);
  void visitAffect(const Affect *a);
  void visitBlock(const Block *b);
  void visitCond(const Cond *c);
  void visitDecl(const Decl *d);
  void visitWhile(const While *w);
  void visitSeq(const Sequence *s);
  void visitLigne(const Ligne *l);
  void visitCarree(const Carree *c);
  void visitCouleur(const Couleur *c);
};


#endif
