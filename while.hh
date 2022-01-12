#ifndef _WHILE_H
#define _WHILE_H

#include "inst.hh"
#include "expr.hh"

class While : public Instruction {
  Expression* min;
  Expression* max;
  string var;
  Instruction *body;
public:
  While(string var, Instruction *body,Expression* min,Expression* max);
  ~While();

  inline const string getVar() const { return var;}
  inline const Expression* getMin() const { return min;}
  inline const Expression* getMax() const { return max;}
  inline const Instruction* getBody() const { return body; }
  
  void visit(Visitor& visitor) const;
  
};

#endif
