#include <iostream>
#include <vector>
#include <list>
#include "Listenbearbeitung.h"

int main(){
    std::list<int> l1 = {1, 2, 3, 4, 5, 6, 6, 6};
    std::list<int> ltest = {1, 2, 3, 4, 5, 6, 6, 6};
    std::list<int> l2 = {3, 4, 5, 6, 7, 8, 3, 3};
    std::list<int> l3 = {999, 666};

    std::list<int> equal = Listenbearbeitung::listEqualElements(l1, l2);
    
    std::cout << Listenbearbeitung::toString(l1);
    std::cout << Listenbearbeitung::toString(l2);
    std::cout << Listenbearbeitung::toString(equal);
    
    std::cout << "hat l1 und l2 keine gleichen Werte? " << (std::boolalpha) << Listenbearbeitung::gotNoEqualElements(l1, l2) << std::endl;
    std::cout << "hat l1 und l3 keine gleichen Werte? " << (std::boolalpha) << Listenbearbeitung::gotNoEqualElements(l1, l3) << std::endl;
    
    std::cout << "haben l1 und ltest die gleiche Anzahl an den gleiche Elementen? " << Listenbearbeitung::equalElementAmount(l1, ltest) << std::endl;

    int i = 0;
    system("pause");
    return 1;
}
