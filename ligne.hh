#ifndef _LIGNE_H
#define _LIGNE_H


#include "inst.hh"
#include "expr.hh"

class Ligne : public Instruction {
  Float* x1;
  Float* y1;
  Float* x2;
  Float* y2;
  char* couleur;

public:
  Ligne(Float* x1,Float* y1,Float* x2,Float* y2,char* couleur);
  ~Ligne();

  inline const Float* getX1() const { return x1; }
  inline const Float* getY1() const { return y1; }
inline const Float* getX2() const { return x2; }
inline const Float* getY2() const { return y2; }
inline const char* getCouleur() const { return couleur; }

  void visit(Visitor& visitor) const;
};


#endif
