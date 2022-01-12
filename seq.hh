#ifndef _SEQ_H
#define _SEQ_H


#include "inst.hh"


class SeqItem {
  Instruction *i;
  SeqItem *next;
public:
  SeqItem(Instruction *i, SeqItem *next = NULL);
  ~SeqItem();

  inline const Instruction* getInst() const { return i; }
  inline bool hasNext() const { return (next != NULL); }
  inline SeqItem* getNext() const { return next; }

  void add(Instruction *i);
};


class Sequence : public Instruction {
  SeqItem *first;
public:
  Sequence(Instruction *first = NULL);
  ~Sequence();
  
  inline SeqItem* getFirst() const { return first; }

  void visit(Visitor& visitor) const;

  void add(Instruction *i); // attention risque d'inversion! (a vous de voir...)
  
};


#endif
