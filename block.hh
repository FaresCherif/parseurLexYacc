#ifndef _BLOCK_H
#define _BLOCK_H

#include "inst.hh"

class Block : public Instruction {
  Instruction *body;
public:
  Block(Instruction *body);
  ~Block();

  inline const Instruction* getBody() const { return body; }
  
  void visit(Visitor& visitor) const;
  
};

#endif
