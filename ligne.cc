#include "ligne.hh"


Ligne::Ligne(Expression* x1,Expression* y1,Expression* x2,Expression* y2)
  : x1(x1) , y1(y1) , x2(x2) , y2(y2)
{
  
}

Ligne::~Ligne() {
  delete x1;
  delete x2;
  delete y1;
  delete y2;
}

void Ligne::visit(Visitor& visitor) const {
  return visitor.visitLigne(this);
}
