#include <iostream>

#include "./include/TestCollection.h"

using namespace std;

int main() {
    cout << "Début des tests..." << endl;

    // Tests pour Catalogue
    cout << "\n=== Tests pour Catalogue ===" << endl;
    
    // Tests pour Collection
    cout << "\n=== Tests pour Collection ===" << endl;
    lancementTestsCollection();

    // Tests pour TrajetCompose
    cout << "\n=== Tests pour TrajetCompose ===" << endl;

    // Tests pour TrajetSimple
    cout << "\n=== Tests pour TrajetSimple ===" << endl;

    cout << "\nFin des tests." << endl;
    return 0;
}

