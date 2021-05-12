#include "Listenbearbeitung.h"

///////////////////////////////////////////////////////////////////////////////////////


/**
 * Funktion: Erstellt eine Liste mit allen gemeinsamen Werten zweier listen.
 * @param: bekommt zwei Listen.
 *
 */
std::list<int> Listenbearbeitung::listEqualElements(std::list<int> obj1, std::list<int> obj2){
    std::list<int> equal = {};
    
    for(int i : obj1){
        for(int j : obj2){
            if(i == j){
                equal.push_back(i);
            }
        }
    }
    equal.unique();
    return equal;
}

///////////////////////////////////////////////////////////////////////////////////////

/**
 *Funktion: einen boolischen Wert zurück, ob eine Liste gleiche Elemente hat oder nicht
 *@param: bekommt zwei Integer-Listen:
 */
bool Listenbearbeitung::gotNoEqualElements(std::list<int> obj1, std::list<int> obj2){
    for(int i : obj1){
        for(int j : obj2){
            if(i == j){
                return true;
            }
        }
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////////////

/**
 *Funtktion: gibt einen boolischen Wert aus, welcher besagt, ob es gleich viele Gleiche Elemente in der Liste gibt.
 *@param: bekommt zwei Integer-Listen.
 *
 */

bool Listenbearbeitung::equalElementAmount(std::list<int> obj1, std::list<int> obj2){
    int counter = 0;
    std::list<int> obj1Unique = getUniqueCopy(obj1);
    std::list<int> obj2Unique = getUniqueCopy(obj2);

    for(int i : obj1Unique){
        for(int j : obj2Unique){
            if(i == j){
                if(getAmountOfEqualElement(obj1, i) == getAmountOfEqualElement(obj2, i)){
                    counter++;
                }
            }
        }
    }

    return counter == obj1Unique.size();
}


/**
 * Funktion: gibt eine Integer-Liste zurück, welche nur einzigartige Werte hat
 * @param: bekommt eine Integer-Liste
 */
std::list<int> Listenbearbeitung::getUniqueCopy(std::list<int> obj){
    std::list<int> objCopy = obj;
    objCopy.sort();
    objCopy.unique();
    return objCopy;
}

/**
 * Funktion: gibt eine eine Zahl an vorkommenden Wiederholungen einer Zahl in einer Integer-Liste aus. 
 * @param: bekommt eine Integer-Liste und eine Zahl nach der Gesucht wird.
 */
int Listenbearbeitung::getAmountOfEqualElement(std::list<int> obj, int num){
    int counter = 0;
    for(int i : obj){
        if(i == num){
            counter++;
        }
    }
    return counter;
}

///////////////////////////////////////////////////////////////////////////////////////

/**
 * Funtkion: gibt einen Strint zurück, welcher eine Liste auf dem Bildschirm ausgeben kann
 * @param: bekommt eine Integer-Liste.
 */
std::string Listenbearbeitung::toString(std::list<int>& obj){
    std::string out = "Listsize: " + std::to_string(obj.size()) + " | ";
    
    for(int item : obj){
        out += " " + std::to_string(item);
    }

    return out + "\n";
}


///////////////////////////////////////////////////////////////////////////////////////
