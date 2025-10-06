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

  if (index >= tailleMax) {
    doublerTailleTrajets();
  }

  trajets[index++] = trajet;
  return;
}

void Collection::Supprimer(int index) {
  // Implémentation à venir
  return;
}

Trajet **Collection::Rechercher(char *villeDepart, char *villeArrivee,
                                int *nbTrajetsTrouves) const {
  // Implémentation à venir
  return NULL;
}

//-------------------------------------------- Constructeurs - destructeur

Collection::Collection(int tailleMax) : tailleMax(tailleMax), index(0) {

#ifdef MAP
  cout << "[MAP] -> Constructeur de : Collection" << endl;
#endif

  trajets = new Trajet *[tailleMax];
}

Collection::~Collection() {
#ifdef MAP
  cout << "[MAP] -> Destructeur de : Collection" << endl;
#endif

  for (int i = 0; i < index; i++) {
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
