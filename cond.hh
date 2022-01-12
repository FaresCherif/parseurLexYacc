#ifndef _COND_H
#define _COND_H

#include "inst.hh"
#include "expr.hh"

class Cond : public Instruction {
  Expression *cond;
  Instruction *cons;
  Instruction *alt;

public:
  Cond(Expression *cond, Instruction *cons, Instruction *alt);
  ~Cond();

  inline const Expression* getCond() const { return cond; }
  inline const Instruction* getCons() const { return cons; }
  inline const Instruction* getAlt() const { return alt; }
  
  void visit(Visitor& visitor) const;
  
};

#endif
