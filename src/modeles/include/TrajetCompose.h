/*************************************************************************
                        TrajetCompose  -  description
                          -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe TrajetCompose (fichier TrajetCompose.h) --------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "Collection.h"

//------------------------------------------------------------------------
// Rôle de la classe TrajetCompose :
// Représenter un trajet composé de plusieurs trajets.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur

    TrajetCompose(Trajet** lesTrajets, unsigned int nbTrajets);
    // Constructeur avec un tableau de trajets et leur nombre

    ~TrajetCompose();
    // Destructeur

    //----------------------------------------------------- Méthodes publiques

    char* GetVilleDepart() const override;
    // Retourne la ville de départ du trajet composé

    char* GetVilleArrivee() const override;
    // Retourne la ville d'arrivée du trajet composé

    void Afficher() const override;
    // Affiche les détails du trajet composé

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés

    Collection* itineraire;  // Collection des trajets composant le trajet
};

#endif // TRAJETCOMPOSE_H
