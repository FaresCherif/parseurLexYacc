#include "ligne.hh"


Ligne::Ligne(Float* x1,Float* y1,Float* x2,Float* y2)
  : x1(x1) , y1(y1) , x2(x2) , y2(y2)
{
  
}

Ligne::~Ligne() {
}

void Ligne::visit(Visitor& visitor) const {
  return visitor.visitLigne(this);
}
