#ifndef _FLOAT_H
#define _FLOAT_H

#include "expr.hh"


class Float : public Expression {
  double value;
public:
  Float(double v);
  ~Float();

  inline double getValue() const { return value; }
  
  void visit(Visitor& visitor) const;
};

#endif
