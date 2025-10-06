#include "../include/TestCollection.h"
#include "../../modeles/include/Collection.h"
#include <iostream>
using namespace std;

void test_instanciation_valide() {
    cout << " -> Test d'instanciation de Collection avec taille 5." << endl;
    Collection* c = new Collection(5);
    if (c == NULL) {
        cerr << "Échec de l'instanciation de Collection avec taille valide." << endl;
    } else {
        cout << "Succès de l'instanciation de Collection avec taille valide." << endl;
    }
    delete c;
    cout << " -> Collection détruite avec succès." << endl;
}

void lancementTests_Collection() {
    cout << "--- Tests :  Collection ---" << endl;
    test_instanciation_valide();
    // Ajouter d'autres appels de fonctions de test ici
    cout << "--- Fin des tests pour la classe Collection ---" << endl;
}