#include "var.hh"


Var::Var(const std::string& name)
  : name(name)
{
}

Var::~Var() {
}

void Var::visit(Visitor& visitor) const {
  return visitor.visitVar(this);
}
