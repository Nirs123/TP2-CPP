/*************************************************************************
                        TrajetSimple  -  description
                          -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe TrajetSimple (fichier TrajetSimple.h) --------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "MoyenTransport.h"

//------------------------------------------------------------------------
// Rôle de la classe TrajetSimple :
// Représenter un trajet simple entre deux villes avec un moyen de transport.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(char* villeDepart, char* villeArrivee, MoyenTransport moyenTransport);
    // Constructeur avec les villes de départ et d'arrivée et le moyen de transport

    ~TrajetSimple();
    // Destructeur

    //----------------------------------------------------- Méthodes publiques

    char* GetVilleDepart() const override;
    // Retourne la ville de départ

    char* GetVilleArrivee() const override;
    // Retourne la ville d'arrivée

    void Afficher() const override;
    // Affiche les détails du trajet simple

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés

    char* villeDepart;        // Ville de départ
    char* villeArrivee;      // Ville d'arrivée
    MoyenTransport moyenTransport;  // Moyen de transport
};

#endif // TRAJETSIMPLE_H
