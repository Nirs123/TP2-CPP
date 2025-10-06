/*************************************************************************
                            Catalogue  -  description
                              -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Catalogue (fichier Catalogue.h) --------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"

//------------------------------------------------------------------------
// Rôle de la classe Catalogue :
// Gérer une collection de trajets avec des opérations d'ajout, suppression
// et recherche de parcours.
//------------------------------------------------------------------------

class Catalogue
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques

    void Ajouter(Trajet* trajet);
    // Ajoute un trajet au catalogue

    void SupprimerTrajet(unsigned int indexSuppression);
    // Supprime un trajet du catalogue à l'tailleCourante spécifié

    void RechercherParcours(char* villeDepart, char* villeArrivee) const;
    // Recherche un parcours entre deux villes

    void Afficher() const;
    // Affiche tous les trajets du catalogue

    //-------------------------------------------- Constructeurs - destructeur

    Catalogue(unsigned int tailleMax);
    // Constructeur avec taille maximale du catalogue

    ~Catalogue();
    // Destructeur

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés

    Collection* trajets;  // Collection de trajets
};

#endif // CATALOGUE_H
