#include <iostream>
#include "Punkt.hpp"
#include "Metrik.hpp"

using namespace std;

#ifndef GEOOBJEKT_HPP
#define GEOOBJEKT_HPP

class GeoObjekt{
    protected:
        MetrikVerhalten* m;

    public:
        virtual double inhalt() = 0;
        virtual string toString() = 0;
        virtual GeoObjekt* clone() = 0;
};

class OperandenPassenNicht : public exception{};

#endif
