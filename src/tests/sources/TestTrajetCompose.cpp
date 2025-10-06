#include "../include/TestTrajetCompose.h"
#include "../../modeles/include/TrajetCompose.h"
#include "../../modeles/include/TrajetSimple.h"

#include <iostream>
#include <cstring>

using namespace std;

void testTrajetComposeInstanciation(){
    cout << "[TEST] Instanciation de TrajetCompose." << endl;

    char v1[] = "Lyon";
    char v2[] = "Paris";
    char v3[] = "Marseille";
    Trajet* t1 = new TrajetSimple(v1, v2, Train);
    Trajet* t2 = new TrajetSimple(v2, v3, Avion);
    
    Trajet* lesTrajets[] = {t1, t2};
    TrajetCompose* tc = new TrajetCompose(lesTrajets, 2);

    if (tc == NULL) {
        cerr << "\tÉchec de l'instanciation du Trajet Compose." << endl;
    } else {
        cout << "\tSuccès de l'instanciation du Trajet Compose." << endl;
    }

    delete tc;

    cout << "\tSuccès de la destruction du Trajet Compose." << endl << endl;
}

void testTrajetComposeAffichage(){
    cout << "[TEST] Affichage de TrajetCompose." << endl;

    char v1[] = "Lyon";
    char v2[] = "Paris";
    char v3[] = "Marseille";
    Trajet* t1 = new TrajetSimple(v1, v2, Train);
    Trajet* t2 = new TrajetSimple(v2, v3, Avion);
    
    Trajet* lesTrajets[] = {t1, t2};
    TrajetCompose* tc = new TrajetCompose(lesTrajets, 2);

    cout << "\tAffichage attendu : de Lyon à Paris en Train - de Paris à Marseille en Avion" << endl;
    cout << "\tAffichage obtenu  : ";
    tc->Afficher();
    cout << endl;

    delete tc;

    cout << "\tSuccès de la destruction du Trajet Compose." << endl << endl;
}

void testTrajetComposeGetVillesComplexeSimple(){
    cout << "[TEST] GetVilleDepart et GetVilleArrivee de TrajetCompose [[TS1, TS2], TS3]." << endl;

    char v1[] = "Lyon";
    char v2[] = "Paris";
    char v3[] = "Marseille";
    Trajet* ts1 = new TrajetSimple(v1, v2, Train);
    Trajet* ts2 = new TrajetSimple(v2, v3, Avion);
    Trajet* lesTrajets[] = {ts1, ts2};
    TrajetCompose* tc1 = new TrajetCompose(lesTrajets, 2);

    char v4[] = "Bordeaux";
    Trajet* ts3 = new TrajetSimple(v3, v4, Voiture);

    Trajet* lesTrajets2[] = {tc1, ts3};
    TrajetCompose* tc = new TrajetCompose(lesTrajets2, 2);

    if (strcmp(tc->GetVilleDepart(), "Lyon") == 0 && strcmp(tc->GetVilleArrivee(), "Bordeaux") == 0) {
        cout << "\tSuccès des méthodes GetVilleDepart et GetVilleArrivee." << endl;
    } else {
        cerr << "\tÉchec des méthodes GetVilleDepart et GetVilleArrivee." << endl;
    }

    delete tc;

    cout << "\tSuccès de la destruction du Trajet Compose." << endl << endl;
}

void testTrajetComposeGetVillesSimpleComplexe(){
    cout << "[TEST] GetVilleDepart et GetVilleArrivee de TrajetCompose [TS1, [TS2, TS3]]." << endl;

    char v1[] = "Lyon";
    char v2[] = "Paris";
    Trajet* ts1 = new TrajetSimple(v1, v2, Train);

    char v3[] = "Marseille";
    char v4[] = "Bordeaux";
    Trajet* ts2 = new TrajetSimple(v2, v3, Avion);
    Trajet* ts3 = new TrajetSimple(v3, v4, Voiture);
    Trajet* lesTrajets[] = {ts2, ts3};
    TrajetCompose* tc1 = new TrajetCompose(lesTrajets, 2);


    Trajet* lesTrajets2[] = {ts1, tc1};
    TrajetCompose* tc = new TrajetCompose(lesTrajets2, 2);

    if (strcmp(tc->GetVilleDepart(), "Lyon") == 0 && strcmp(tc->GetVilleArrivee(), "Bordeaux") == 0) {
        cout << "\tSuccès des méthodes GetVilleDepart et GetVilleArrivee." << endl;
    } else {
        cerr << "\tÉchec des méthodes GetVilleDepart et GetVilleArrivee." << endl;
    }

    delete tc;

    cout << "\tSuccès de la destruction du Trajet Compose." << endl << endl;
}

void lancementTestsTrajetCompose(){
    testTrajetComposeInstanciation();
    testTrajetComposeAffichage();
    testTrajetComposeGetVillesComplexeSimple();
    testTrajetComposeGetVillesSimpleComplexe();
}
