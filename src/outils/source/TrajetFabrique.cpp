/*************************************************************************
                        TrajetFabrique  -  implementation
                          -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

#include "../include/TrajetFabrique.h"
#include <cstddef>

// Constructeur
TrajetFabrique::TrajetFabrique() {
    // Implémentation du constructeur
}

// Destructeur
TrajetFabrique::~TrajetFabrique() {
    // Implémentation du destructeur
}

// Méthode pour créer un trajet simple
TrajetSimple* TrajetFabrique::CreerTrajetSimple(const char* villeDepart, const char* villeArrivee) {
    // Implémentation de la méthode
    return NULL; // Valeur de retour factice
}

// Méthode pour créer un trajet composé
TrajetCompose* TrajetFabrique::CreerTrajetCompose() {
    // Implémentation de la méthode
    return NULL; // Valeur de retour factice
}
