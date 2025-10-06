/*************************************************************************
                        TrajetFabrique  -  description
                          -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr,
nicolas.foussard@insa-lyon.fr
*************************************************************************/

#ifndef TRAJETFABRIQUE_H
#define TRAJETFABRIQUE_H

#include "../../modeles/include/TrajetSimple.h"
#include "../../modeles/include/TrajetCompose.h"

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
