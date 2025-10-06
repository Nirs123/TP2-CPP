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

void testCollectionAjoutTrajetSimple() {
    cout << "[TEST] Ajout d'un trajet simple à une Collection." << endl;

    Collection* c = new Collection(5);
    TrajetSimple* ts = new TrajetSimple("Paris", "Lyon", Bateau);
    c->Ajouter(ts);
    delete c; // La collection doit gérer la destruction des trajets qu'elle contient
}

void lancementTestsCollection() {
    testCollectionInstanciation();
    testCollectionAjoutTrajetSimple();
}
