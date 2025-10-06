#include "../include/TestCollection.h"
#include "../../modeles/include/Collection.h"
#include <iostream>
using namespace std;

void testInstanciationValide() {
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

void lancementTestsCollection() {
    testInstanciationValide();
}
