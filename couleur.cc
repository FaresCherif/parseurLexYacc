#include "couleur.hh"


Couleur::Couleur(string couleur)
  : couleur(couleur)
{
  
}

Couleur::~Couleur() {
}

void Couleur::visit(Visitor& visitor) const {
  return visitor.visitCouleur(this);
}
