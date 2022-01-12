#ifndef _CARREE_H
#define _CARREE_H


#include "inst.hh"
#include "Ligne.hh"

class Carree : public Instruction {
  Ligne* l1;
  Ligne* l2;
  Ligne* l3;
  Ligne* l4;

public:
  Carree(Ligne* l1,Ligne* l2,Ligne* l3,Ligne* l4);
  ~Carree();

  inline const Ligne* getL1() const { return l1; }
  inline const Ligne* getL2() const { return l2; }
  inline const Ligne* getL3() const { return l3; }
  inline const Ligne* getL4() const { return l4; }
  
void visit(Visitor& visitor) const;
};


#endif
