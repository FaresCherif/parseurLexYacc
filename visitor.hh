#ifndef VISITOR_H
#define VISITOR_H


class Float;
class Operator;
class Affect;
class Block;
class Cond;
class Decl;
class While;
class Sequence;
class Var;
class Ligne;
class Carree;
class Couleur;

class Visitor {
public:
  virtual void visitFloat(const Float *f) = 0;
  virtual void visitVar(const Var *v) = 0;
  virtual void visitOperator(const Operator *o) = 0;
  virtual void visitAffect(const Affect *a) = 0;
  virtual void visitBlock(const Block *b) = 0;
  virtual void visitCond(const Cond *c) = 0;
  virtual void visitDecl(const Decl *d) = 0;
  virtual void visitWhile(const While *w) = 0;
  virtual void visitSeq(const Sequence *s) = 0;
  virtual void visitLigne(const Ligne *l) = 0;
  virtual void visitCarree(const Carree *c) = 0;
  virtual void visitCouleur(const Couleur *c)=0;
};



#endif
