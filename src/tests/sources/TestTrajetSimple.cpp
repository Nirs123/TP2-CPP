#include "../include/TestTrajetSimple.h"
#include "../../modeles/include/TrajetSimple.h"
#include <iostream>
#include <cstring>

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

    cout << "\tSuccès de la destruction de TrajetSimple." << endl << endl;
}

void testTrajetSimpleAffichage(){
    cout << "[TEST] Affichage de TrajetSimple." << endl;

    char dep[] = "Lyon";
    char arr[] = "Paris";
    TrajetSimple* ts = new TrajetSimple(dep, arr, Train);

    cout << "\tAffichage attendu : de Lyon à Paris en Train" << endl;
    cout << "\tAffichage obtenu  : ";
    ts->Afficher();
    cout << endl;

    delete ts;

    cout << "\tSuccès de la destruction de TrajetSimple." << endl << endl;
}

void testTrajetSimpleInstanciationNull(){
    cout << "[TEST] Instanciation de TrajetSimple avec deux paramètres NULL." << endl;

    TrajetSimple* ts = new TrajetSimple(NULL, NULL, Avion);
    if (strcmp(ts->GetVilleDepart(), "Non défini") == 0 && strcmp(ts->GetVilleArrivee(), "Non défini") == 0) {
        cout << "\tSuccès de l'instanciation de TrajetSimple avec paramètres NULL." << endl;
    } else {
        cerr << "\tÉchec de l'instanciation de TrajetSimple avec paramètres NULL." << endl;
    }
    
    cout << "\tAffichage attendu : de Non défini à Non défini en Avion" << endl;
    cout << "\tAffichage obtenu  : ";
    ts->Afficher();
    cout << endl;

    delete ts;

    cout << "\tSuccès de la destruction de TrajetSimple." << endl << endl;

    
    cout << "[TEST] Instanciation de TrajetSimple avec un paramètre NULL." << endl;

    char arr[] = "Marseille";
    TrajetSimple* ts2 = new TrajetSimple(NULL, arr, Bateau);

    if (strcmp(ts2->GetVilleDepart(), "Non défini") == 0 && strcmp(ts2->GetVilleArrivee(), arr) == 0) {
        cout << "\tSuccès de l'instanciation de TrajetSimple avec un paramètre NULL." << endl;
    } else {
        cerr << "\tÉchec de l'instanciation de TrajetSimple avec un paramètre NULL." << endl;
    }

    cout << "\tAffichage attendu : de Non défini à Marseille en Bateau" << endl;
    cout << "\tAffichage obtenu  : ";
    ts2->Afficher();
    cout << endl;

    delete ts2;

    cout << "\tSuccès de la destruction de TrajetSimple." << endl << endl;
}

void lancementTestsTrajetSimple(){
    testTrajetSimpleInstanciation();
    testTrajetSimpleAffichage();
    testTrajetSimpleInstanciationNull();
}
