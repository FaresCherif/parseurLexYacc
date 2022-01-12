#include "while.hh"

While::While(string var, Instruction *body,Expression* min,Expression* max)
  : var(var),body(body),min(min),max(max)
{
}

While::~While() {
  delete body;
  delete min;
  delete max;
}


void While::visit(Visitor& visitor) const {
  return visitor.visitWhile(this);
}
