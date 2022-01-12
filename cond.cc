#include "cond.hh"


Cond::Cond(Expression *cond, Instruction *cons, Instruction *alt)
  : cond(cond), cons(cons), alt(alt)
{
}

Cond::~Cond() {
  delete cond;
  delete cons;
  delete alt;
}

void Cond::visit(Visitor& visitor) const {
  return visitor.visitCond(this);
}
