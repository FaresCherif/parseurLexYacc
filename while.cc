#include "while.hh"

While::While(Expression *cond, Instruction *body)
  : cond(cond),body(body)
{
}

While::~While() {
  delete cond;
  delete body;
}


void While::visit(Visitor& visitor) const {
  return visitor.visitWhile(this);
}
