#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

class Listenbearbeitung{
    private:
        static int getAmountOfEqualElement(std::list<int> obj, int num);
        static std::list<int> getUniqueCopy(std::list<int> obj);
    public:
        static std::list<int> listEqualElements(std::list<int> obj1, std::list<int> obj2);
        static std::string toString(std::list<int>& obj);

        static bool gotNoEqualElements(std::list<int> obj1, std::list<int> obj2);
        static bool equalElementAmount(std::list<int> obj1, std::list<int> obj2);
};
