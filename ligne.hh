#ifndef _LIGNE_H
#define _LIGNE_H


#include "inst.hh"
#include "expr.hh"

class Ligne : public Instruction {
  Expression* x1;
  Expression* y1;
  Expression* x2;
  Expression* y2;

public:
  Ligne(Expression* x1,Expression* y1,Expression* x2,Expression* y2);
  ~Ligne();

  inline const Expression* getX1() const { return x1; }
  
  void visit(Visitor& visitor) const;
};


#endif
