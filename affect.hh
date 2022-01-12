#ifndef _AFFECT_H
#define _AFFECT_H


#include "inst.hh"
#include "expr.hh"

class Affect : public Instruction {
  string var;
  Expression* expr;
public:
  Affect(string var, Expression* expr);
  ~Affect();

  inline string getVar() const { return var; }
  inline const Expression* getExpr() const { return expr; }
  
  void visit(Visitor& visitor) const;
};


#endif
