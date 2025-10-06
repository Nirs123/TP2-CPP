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

void testRechercheValideDansCollectionDeTrajetsSimples()
{
    cout << "\n\n[TEST] Recherche valide dans une Collection." << endl;
    Collection* c = new Collection(5);
    TrajetSimple* ts1 = new TrajetSimple("Milhau", "Clermont d'Auvernha", Bateau);
    TrajetSimple* ts2 = new TrajetSimple("Marselha", "Paris", Train);
    TrajetSimple* ts3 = new TrajetSimple("Rodès", "Villafranca de rouergue", Voiture);
    c->Ajouter(ts1);
    c->Ajouter(ts2);
    c->Ajouter(ts3);

    const char * villeArrivee = "Paris";
    const char * villeDepart = "Marselha";

    cout << "\n\tCollection actuelle :" << endl;
    c->Afficher(true);
    cout << endl;
    cout << "\tRecherche de trajets de " << villeDepart << " à " << villeArrivee << " :" << endl;

    unsigned int nbTrajetsTrouves = 0;
    Trajet** resultats = c->Rechercher(villeDepart, villeArrivee, &nbTrajetsTrouves);

    if (resultats != NULL && nbTrajetsTrouves > 0) {
        cout << "\tSuccès de la recherche. Nombre de trajets trouvés : " << nbTrajetsTrouves << endl;
        for (unsigned int i = 0; i < nbTrajetsTrouves; i++) {
            resultats[i]->Afficher();
            cout << endl;
        }
    } else {
        cerr << "\tÉchec de la recherche." << endl;
    }

    delete[] resultats; 
    delete c; 
}

void testRecherchesInvalidesDansCollectionDeTrajetsSimples()
{
    cout << "\n\n[TEST] Recherches invalides dans une Collection." << endl;
    Collection* c = new Collection(5);
    TrajetSimple* ts1 = new TrajetSimple("Milhau", "Clermont d'Auvernha", Bateau);
    TrajetSimple* ts2 = new TrajetSimple("Marselha", "Paris", Train);
    TrajetSimple* ts3 = new TrajetSimple("Rodès", "Villafranca de rouergue", Voiture);
    c->Ajouter(ts1);
    c->Ajouter(ts2);
    c->Ajouter(ts3);

    const char * villeArrivee = "Paris";
    const char * villeDepart = "Marselha";

    cout << "\n\tCollection actuelle :" << endl;
    c->Afficher(true);
    cout << endl;

    unsigned int nbTrajetsTrouves = 0;

    cout << "\tRecherche avec villeDepart NULL :" << endl;
    Trajet** resultats1 = c->Rechercher(NULL, villeArrivee, &nbTrajetsTrouves);
    if (resultats1 == NULL) {
        cout << "\tSuccès : Gestion correcte de la recherche avec villeDepart NULL." << endl;
    } else {
        cerr << "\tÉchec : La recherche avec villeDepart NULL n'a pas été gérée correctement." << endl;
        delete[] resultats1; 
    }

    cout << "\tRecherche avec villeArrivee NULL :" << endl;
    Trajet** resultats2 = c->Rechercher(villeDepart, NULL, &nbTrajetsTrouves);
    if (resultats2 == NULL) {
        cout << "\tSuccès : Gestion correcte de la recherche avec villeArrivee NULL." << endl;
    } else {
        cerr << "\tÉchec : La recherche avec villeArrivee NULL n'a pas été gérée correctement." << endl;
        delete[] resultats2; 
    }

    cout << "\tRecherche avec nbTrajetsTrouves NULL :" << endl;
    Trajet** resultats3 = c->Rechercher(villeDepart, villeArrivee, NULL);
    if (resultats3 == NULL) {
        cout << "\tSuccès : Gestion correcte de la recherche avec nbTrajetsTrouves NULL." << endl;
    }
}

void testRecupererDansCollectionValide()
{
    cout << "\n\n[TEST] Récupération valide dans une Collection." << endl;
    Collection* c = new Collection(5);
    TrajetSimple* ts1 = new TrajetSimple("Milhau", "Clermont d'Auvernha", Bateau);
    TrajetSimple* ts2 = new TrajetSimple("Marselha", "Paris", Train);
    TrajetSimple* ts3 = new TrajetSimple("Rodès", "Villafranca de rouergue", Voiture);
    c->Ajouter(ts1);
    c->Ajouter(ts2);
    c->Ajouter(ts3);

    cout << "\n\tCollection actuelle :" << endl;
    c->Afficher(true);
    cout << endl;

    unsigned int indexValide = 1;
    cout << "\tRécupération du trajet à l'index " << indexValide << " :" << endl;
    Trajet* trajetRecupere = c->Recuperer(indexValide);
    if (trajetRecupere != NULL) {
        cout << "\tSuccès de la récupération. Détails du trajet récupéré :" << endl;
        trajetRecupere->Afficher();
        cout << endl;
    } else {
        cerr << "\tÉchec de la récupération." << endl;
    }

    delete c; 
}

void testRecupererDansCollectionAIndexInvalides()
{
    cout << "\n\n[TEST] Récupération dans une Collection à des index invalides." << endl;
    Collection* c = new Collection(5);
    TrajetSimple* ts1 = new TrajetSimple("Milhau", "Clermont d'Auvernha", Bateau);
    TrajetSimple* ts2 = new TrajetSimple("Marselha", "Paris", Train);
    TrajetSimple* ts3 = new TrajetSimple("Rodès", "Villafranca de rouergue", Voiture);
    c->Ajouter(ts1);
    c->Ajouter(ts2);
    c->Ajouter(ts3);

    cout << "\n\tCollection actuelle :" << endl;
    c->Afficher(true);
    cout << endl;

    int indexNegatif = -1;
    cout << "\tRécupération du trajet à l'index " << indexNegatif << " :" << endl;
    Trajet* trajetRecupereNegatif = c->Recuperer(indexNegatif);
    if (trajetRecupereNegatif == NULL) {
        cout << "\tSuccès : Gestion correcte de la récupération à un index négatif." << endl;
    } else {
        cerr << "\tÉchec : La récupération à un index négatif n'a pas été gérée correctement." << endl;
    }

    unsigned int indexTropGrand = 5;
    cout << "\tRécupération du trajet à l'index " << indexTropGrand << " :" << endl;
    Trajet* trajetRecupereTropGrand = c->Recuperer(indexTropGrand);
    if (trajetRecupereTropGrand == NULL) {
        cout << "\tSuccès : Gestion correcte de la récupération à un index trop grand." << endl;
    } else {
        cerr << "\tÉchec : La récupération à un index trop grand n'a pas été gérée correctement." << endl;
    }

    delete c; 
}

void lancementTestsCollection() {
    testCollectionInstanciation();
    testCollectionAjoutDeTrajetsSimples();
    testCollectionSuppressionTrajetsSimples();
    testCollectionSuppressionAIndexInvalides();
    testRechercheValideDansCollectionDeTrajetsSimples();
    testRecherchesInvalidesDansCollectionDeTrajetsSimples();
    testRecupererDansCollectionValide();
    testRecupererDansCollectionAIndexInvalides();
}
