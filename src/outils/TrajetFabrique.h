/*************************************************************************
                        TrajetFabrique  -  description
                          -------------------
    début                : [Date actuelle]
    copyright            : (C) [Année actuelle] par [Votre nom]
    e-mail               : [Votre email]
*************************************************************************/

#ifndef TRAJETFABRIQUE_H
#define TRAJETFABRIQUE_H

#include "../modeles/include/TrajetSimple.h"
#include "../modeles/include/TrajetCompose.h"

class TrajetFabrique {
public:
    // Constructeur
    TrajetFabrique();

    // Destructeur
    virtual ~TrajetFabrique();

    // Méthode pour créer un trajet simple
    TrajetSimple* CreerTrajetSimple(const char* villeDepart, const char* villeArrivee);

    // Méthode pour créer un trajet composé
    TrajetCompose* CreerTrajetCompose();

private:
    // Attributs privés
    // Ajoutez ici les attributs nécessaires à la fabrique
};

#endif // TRAJETFABRIQUE_H
