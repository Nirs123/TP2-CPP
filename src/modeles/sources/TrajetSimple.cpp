/*************************************************************************
                        TrajetSimple  -  réalisation
                          -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

//--------------------------------------------------- Interfaces utilisées
#include "../include/TrajetSimple.h"
#include <iostream>
#include <cstring>

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe TrajetSimple :
// Représenter un trajet simple entre deux villes avec un moyen de transport.
//------------------------------------------------------------------------

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(char* villeDepart, char* villeArrivee, MoyenTransport moyenTransport)
{
    #ifdef MAP
        cout << "[MAP] -> Constructeur de : TrajetSimple" << endl;
    #endif

    this->villeDepart = new char[strlen(villeDepart) + 1];
    strcpy(this->villeDepart, villeDepart);

    this->villeArrivee = new char[strlen(villeArrivee) + 1];
    strcpy(this->villeArrivee, villeArrivee);

    this->moyenTransport = moyenTransport;
}

TrajetSimple::~TrajetSimple()
{
    #ifdef MAP
        cout << "[MAP] -> Destructeur de : TrajetSimple" << endl;
    #endif

    delete[] villeDepart;
    delete[] villeArrivee;
}

//----------------------------------------------------- Méthodes publiques

char* TrajetSimple::GetVilleDepart() const
{
    return villeDepart;
}

char* TrajetSimple::GetVilleArrivee() const
{
    return villeArrivee;
}

void TrajetSimple::Afficher() const
{
    cout << "de " << villeDepart << " à " << villeArrivee << " en " << moyenTransport << endl;
}
