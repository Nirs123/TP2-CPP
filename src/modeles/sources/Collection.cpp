/*************************************************************************
                            Collection  -  réalisation
                              -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr,
nicolas.foussard@insa-lyon.fr
*************************************************************************/

//--------------------------------------------------- Interfaces utilisées
#include "../include/Collection.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe Collection :
// Gérer une collection de trajets avec des opérations d'ajout, suppression
// et recherche de trajets.
//------------------------------------------------------------------------

//----------------------------------------------------- Méthodes publiques

void Collection::Ajouter(Trajet *trajet) {

  if (tailleCourante >= tailleMax) {
    doublerTailleTrajets();
  }

  trajets[tailleCourante++] = trajet;
  return;
}

void Collection::Supprimer(int index) {

  if (index < 0 || index >= this->tailleCourante) {
    cerr << "Index invalide pour la suppression." << endl;
    return;
  }
  delete trajets[index];
  for (int i = index; i < this->tailleCourante - 1; i++) {
    trajets[i] = trajets[i + 1];
  }
  this->tailleCourante--;
  return;
}

Trajet **Collection::Rechercher(char *villeDepart, char *villeArrivee,
                                int *nbTrajetsTrouves) const {
  // Implémentation à venir
  return NULL;
}

//-------------------------------------------- Constructeurs - destructeur

Collection::Collection(int tailleMax) : tailleMax(tailleMax), tailleCourante(0) {

#ifdef MAP
  cout << "[MAP] -> Constructeur de : Collection" << endl;
#endif

  trajets = new Trajet *[tailleMax];
}

Collection::~Collection() {
#ifdef MAP
  cout << "[MAP] -> Destructeur de : Collection" << endl;
#endif

  for (int i = 0; i < tailleCourante; i++) {
    delete trajets[i];
  }

  delete[] trajets;
  return;
}

//----------------------------------------------------- Méthodes protégées
void Collection::doublerTailleTrajets() {

  int nouvelleTaille = tailleMax * 2;
  Trajet **nouveauxTrajets = new Trajet *[nouvelleTaille];

  for (int i = 0; i < tailleMax; i++) {
    nouveauxTrajets[i] = trajets[i];
  }

  delete[] trajets;
  trajets = nouveauxTrajets;
  tailleMax = nouvelleTaille;

  return;
}
