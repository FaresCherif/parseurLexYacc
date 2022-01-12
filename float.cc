#include "float.hh"


Float::Float(double v) : value(v) {
  
}

Float::~Float() {
  
}

void Float::visit(Visitor& visitor) const {
  return visitor.visitFloat(this);
}
