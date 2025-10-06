#include "../include/TestCollection.h"
#include "../../modeles/include/Collection.h"
#include "../../modeles/include/TrajetSimple.h"
#include "../../modeles/include/MoyenTransport.h"
#include <iostream>
using namespace std;

void testCollectionInstanciation() {
    cout << "[TEST] Instanciation de Collection avec taille 5." << endl;

    Collection* c = new Collection(5);

    if (c == NULL) {
        cerr << "\tÉchec de l'instanciation de Collection avec taille valide." << endl;
    } else {
        cout << "\tSuccès de l'instanciation de Collection avec taille valide." << endl;
    }

    delete c;

    cout << "\tSuccès de la destruction de la Collection." << endl;
}

void testCollectionAjoutDeTrajetsSimples() {
    cout << "[TEST] Ajout d'un trajet simple à une Collection." << endl;
    Collection* c = new Collection(5);
    TrajetSimple* ts1 = new TrajetSimple("Milhau", "Clermont d'Auvernha", Bateau);
    TrajetSimple* ts2 = new TrajetSimple("Marselha", "Paris", Train);
    TrajetSimple* ts3 = new TrajetSimple("Rodès", "Villafranca de rouergue", Voiture);
    TrajetSimple* ts4 = new TrajetSimple("Toulouse", "Bordeaux", Avion);
    TrajetSimple* ts5 = new TrajetSimple("Lyon", "Nice", Bateau);
    TrajetSimple* ts6 = new TrajetSimple("Nimes", "Montpellier", Train);
    c->Ajouter(ts1);
    c->Ajouter(ts2);
    c->Ajouter(ts3);
    c->Ajouter(ts4);
    c->Ajouter(ts5);
    c->Ajouter(ts6);
    c->Afficher();
    delete c; 
}

void lancementTestsCollection() {
    testCollectionInstanciation();
    testCollectionAjoutDeTrajetsSimples();
}
