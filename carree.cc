#include "carree.hh"


Carree::Carree(Ligne* l1,Ligne* l2,Ligne* l3,Ligne* l4)
  : l1(l1) , l2(l2) , l3(l3) , l4(l4)
{
  
}

Carree::~Carree() {
  delete l1;
  delete l2;
  delete l3;
  delete l4;
}

void Carree::visit(Visitor& visitor) const {
  return visitor.visitCarree(this);
}
