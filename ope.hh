#ifndef _OPE_H
#define _OPE_H

#include "expr.hh"

enum OperatorSymbol {
  PLUS,
  MOINS,
  MULT,
  DIV,
  INF,
  INFEG,
  SUP,
  SUPEG,
  EGALITE,
  DIFF,
};

class Operator : public Expression {
  Expression *left;
  OperatorSymbol symbol;
  Expression *right;

public:
  Operator(OperatorSymbol symbol, Expression *left, Expression *right);
  ~Operator();

  inline const Expression* getLeft() const { return left; }
  inline const Expression* getRight() const { return right; }
  inline const OperatorSymbol getSymbol() const {
    return symbol;
  }
  
  void visit(Visitor& visitor) const;
  
};

#endif
