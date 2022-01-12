#ifndef _DECL_H
#define _DECL_H

#include "inst.hh"

class Decl : public Instruction {
  string var;
public:
  Decl(string var);
  ~Decl();

  inline const string getVar() const { return var; }
  
  void visit(Visitor& visitor) const;
  
};


#endif
