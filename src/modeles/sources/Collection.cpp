/*************************************************************************
                            Collection  -  réalisation
                              -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
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

void Collection::Ajouter(Trajet* trajet)
{
    // Implémentation à venir
    return;
}

void Collection::Supprimer(int index)
{
    // Implémentation à venir
    return;
}

Trajet** Collection::Rechercher(char* villeDepart, char* villeArrivee, int * nbTrajetsTrouves) const
{
    // Implémentation à venir
    return NULL;
}

//-------------------------------------------- Constructeurs - destructeur

Collection::Collection(int tailleMax) : tailleMax(tailleMax), index(0)
{
    trajets = new Trajet*[tailleMax];
}

Collection::~Collection()
{
    if (MAP_COLLECTION)
    {
        cout << "[MAP] -> Destructeur de : Collection" << endl;
    }

    for (int i = 0; i < index; i++)
    {
        delete trajets[i];
    }
    
    delete[] trajets;
    return;
}
