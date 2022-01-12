#ifndef _VAR_H
#define _VAR_H

#include <string>

#include "expr.hh"

class Var : public Expression {
  std::string name;
public:
  Var(const std::string& name);
  ~Var();

  inline std::string getIdent() const { return name; }

  void visit(Visitor& visitor) const;
};

#endif
