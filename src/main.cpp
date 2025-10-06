#include "modeles/include/Collection.h"
#include <iostream>
int main()
{
    std::cout << "Début du projet ! " << std::endl;
    Collection * c = new Collection(3);
    delete(c);

    
    return 0;
}