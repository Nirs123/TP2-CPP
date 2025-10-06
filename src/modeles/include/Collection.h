/*************************************************************************
                            Collection  -  description
                              -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Collection (fichier Collection.h) --------
#if !defined(COLLECTION_H)
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

#define MAP_COLLECTION false

//------------------------------------------------------------------------
// Rôle de la classe Collection :
// Gérer une collection de trajets avec des opérations d'ajout, suppression
// et recherche de trajets.
//------------------------------------------------------------------------

class Collection
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques

    void Afficher(bool afficherIndex = false) const;

    void Ajouter(Trajet* trajet);
    // Ajoute un trajet à la collection

    void Supprimer(int index);
    // Supprime un trajet de la collection à l'index spécifié

    Trajet** Rechercher(const char* villeDepart, const char* villeArrivee, unsigned int * nbTrajetsTrouves) const;
    // Recherche un trajet entre deux villes

    Trajet * Recuperer(const unsigned int index) const;
    // Récupère un trajet de la collection à l'index spécifié

    unsigned int GetTailleCourante() const;
    // Retourne la taille courante de la collection

    //-------------------------------------------- Constructeurs - destructeur

    Collection(unsigned int tailleMax);
    // Constructeur avec taille maximale de la collection

    ~Collection();
    // Destructeur

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    Trajet** trajets;  // Tableau de pointeurs vers les trajets
    int tailleMax;     // Taille maximale de la collection
    int tailleCourante;         // taille courante
    
    void doublerTailleTrajets();
};

#endif // COLLECTION_H
