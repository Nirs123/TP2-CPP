#include "../include/TestCollection.h"
#include "../../modeles/include/Collection.h"
#include "../../modeles/include/TrajetSimple.h"
#include "../../modeles/include/MoyenTransport.h"
#include <iostream>
using namespace std;

void testCollectionInstanciation() {
    cout << "\n\n[TEST] Instanciation de Collection avec taille 5." << endl;

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
    cout << "\n\n[TEST] Ajout d'un trajet simple à une Collection." << endl;
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
    c->Afficher(true);
    delete c; 
}

void testCollectionSuppressionTrajetsSimples()
{
    cout << "\n\n[TEST] Suppression d'un trajet simple dans une Collection." << endl;
    Collection* c = new Collection(5);
    TrajetSimple* ts1 = new TrajetSimple("Milhau", "Clermont d'Auvernha", Bateau);
    TrajetSimple* ts2 = new TrajetSimple("Marselha", "Paris", Train);
    TrajetSimple* ts3 = new TrajetSimple("Rodès", "Villafranca de rouergue", Voiture);
    c->Ajouter(ts1);
    c->Ajouter(ts2);
    c->Ajouter(ts3);
    cout << "\tCollection avant suppression :" << endl;
    c->Afficher(true);
    cout << endl;
    c->Supprimer(1);
    cout << "\tCollection après suppression du trajet à l'index 1 :" << endl;
    c->Afficher(true);
    cout << endl;
    delete c; 
}

void testCollectionSuppressionAIndexInvalides()
{
    cout << "\n\n[TEST] Suppression d'un trajet simple dans une Collection à des index invalides." << endl;
    Collection* c = new Collection(5);
    TrajetSimple* ts1 = new TrajetSimple("Milhau", "Clermont d'Auvernha", Bateau);
    TrajetSimple* ts2 = new TrajetSimple("Marselha", "Paris", Train);
    TrajetSimple* ts3 = new TrajetSimple("Rodès", "Villafranca de rouergue", Voiture);
    c->Ajouter(ts1);
    c->Ajouter(ts2);
    c->Ajouter(ts3);
    cout << "\tCollection avant suppression :" << endl;
    c->Afficher(true);
    cout << endl;
    cout << "\tTentative de suppression à l'index -1 :" << endl;
    c->Supprimer(-1);
    cout << "\tTentative de suppression à l'index 5 :" << endl;
    c->Supprimer(5);
    cout << "\tCollection après tentatives de suppression à des index invalides :" << endl;
    c->Afficher(true);
    cout << endl;
    delete c; 
}

void lancementTestsCollection() {
    testCollectionInstanciation();
    testCollectionAjoutDeTrajetsSimples();
    testCollectionSuppressionTrajetsSimples();
    testCollectionSuppressionAIndexInvalides();
}
