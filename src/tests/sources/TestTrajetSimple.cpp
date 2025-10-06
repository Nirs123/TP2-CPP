#include "../include/TestTrajetSimple.h"
#include "../../modeles/include/TrajetSimple.h"
#include <iostream>

using namespace std;

void testTrajetSimpleInstanciation(){
    cout << "[TEST] Instanciation de TrajetSimple." << endl;

    char dep[] = "Lyon";
    char arr[] = "Paris";

    TrajetSimple* ts = new TrajetSimple(dep, arr, Train);

    if (ts->GetVilleDepart() != NULL && ts->GetVilleArrivee() != NULL) {
        cout << "\tSuccès de l'instanciation de TrajetSimple avec villes valides." << endl;
    } else {
        cerr << "\tÉchec de l'instanciation de TrajetSimple avec villes valides." << endl;
    }

    delete ts;

    cout << "\tSuccès de la destruction de TrajetSimple." << endl;
}

void lancementTestsTrajetSimple(){
    testTrajetSimpleInstanciation();
}
