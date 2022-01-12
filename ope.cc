#include "ope.hh"

Operator::Operator(OperatorSymbol symbol, Expression *left, Expression *right)
  : symbol(symbol), left(left), right(right)
{
}

Operator::~Operator() {
  delete left;
  delete right;
}

void Operator::visit(Visitor& visitor) const {
  return visitor.visitOperator(this);
}
