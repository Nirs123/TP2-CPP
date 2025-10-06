/*************************************************************************
                            Collection  -  réalisation
                              -------------------
    début                : 05/10/2025
    copyright            : (C) 2025 par Jean Marcillac et Nicolas Foussard
    e-mail               : jean.marcillac@insa-lyon.fr,
nicolas.foussard@insa-lyon.fr
*************************************************************************/

//--------------------------------------------------- Interfaces utilisées
#include "../include/MoyenTransport.h"

//----------------------------------------------------- Méthodes utilisées
const char* TransportToString(MoyenTransport transport) {
    switch (transport) {
        case Avion: return "Avion";
        case Bateau: return "Bateau";
        case Train: return "Train";
        case Voiture: return "Voiture";
        default: return "Inconnu";
    }
}

