/*************************************************************************
                        TrajetCompose  -  réalisation
                          -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

//--------------------------------------------------- Interfaces utilisées
#include "../include/TrajetCompose.h"
#include <iostream>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe TrajetCompose :
// Représenter un trajet composé de plusieurs trajets.
//------------------------------------------------------------------------

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(Trajet** lesTrajets, unsigned int nbTrajets)
{
    #ifdef MAP
        cout << "[MAP] -> Constructeur de : TrajetCompose" << endl;
    #endif

    this->itineraire = new Collection(nbTrajets);
    for (unsigned int i = 0; i < nbTrajets; i++) {
        this->itineraire->Ajouter(lesTrajets[i]);
    }
}

TrajetCompose::~TrajetCompose()
{
    #ifdef MAP
        cout << "[MAP] -> Destructeur de : TrajetCompose" << endl;
    #endif

    delete this->itineraire;
}

//----------------------------------------------------- Méthodes publiques

char* TrajetCompose::GetVilleDepart() const
{
    return this->itineraire->Recuperer(0)->GetVilleDepart();
}

char* TrajetCompose::GetVilleArrivee() const
{
    unsigned int nbTrajets = this->itineraire->GetTailleCourante();
    return this->itineraire->Recuperer(nbTrajets - 1)->GetVilleArrivee();
}

void TrajetCompose::Afficher() const
{
    this->itineraire->Afficher(false);
}
