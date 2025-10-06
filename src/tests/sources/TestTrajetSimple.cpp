#include "../../modeles/include/TrajetSimple.h"
#include <iostream>

using namespace std;

void testConstructeur(){
    TrajetSimple* ts = new TrajetSimple("Lyon", "Paris", Train);
    ts->Afficher();
}

void testDestructeur(){
    TrajetSimple* ts = new TrajetSimple("Lyon", "Paris", Train);
    ts->Afficher();
    delete ts;
}

void testTrajetSimple(){
    testConstructeur();
    testDestructeur();
}
