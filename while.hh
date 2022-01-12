#ifndef _WHILE_H
#define _WHILE_H

#include "inst.hh"
#include "expr.hh"

class While : public Instruction {
  Expression* cond;
  Instruction *body;
public:
  While(Expression *cond, Instruction *body);
  ~While();

  inline const Expression* getCond() const { return cond; }
  inline const Instruction* getBody() const { return body; }
  
  void visit(Visitor& visitor) const;
  
};

#endif
