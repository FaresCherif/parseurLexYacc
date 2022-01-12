#ifndef _COULEUR_H
#define _COULEUR_H


#include "inst.hh"

class Couleur : public Instruction {
  string couleur;

public:
  Couleur(string couleur);
  ~Couleur();

  inline const string getCouleur() const { return couleur; }
  
void visit(Visitor& visitor) const;
};


#endif
