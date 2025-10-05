/*************************************************************************
                              Trajet  -  description
                                -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr, nicolas.foussard@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe Trajet (fichier Trajet.h) --------
#if !defined(TRAJET_H)
#define TRAJET_H

//------------------------------------------------------------------------
// Rôle de la classe Trajet :
// Classe de base abstraite pour représenter un trajet.
//------------------------------------------------------------------------

class Trajet
{
    //----------------------------------------------------------------- PUBLIC
public:
    //-------------------------------------------- Constructeurs - destructeur

    virtual ~Trajet() {}
    // Destructeur virtuel

    //----------------------------------------------------- Méthodes publiques

    virtual char* GetVilleDepart() const = 0;
    // Retourne la ville de départ

    virtual char* GetVilleArrivee() const = 0;
    // Retourne la ville d'arrivée

    virtual void Afficher() const = 0;
    // Affiche les détails du trajet
};

#endif // TRAJET_H
