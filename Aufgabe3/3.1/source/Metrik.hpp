#include <iostream>
#include <cmath>
#include "Punkt.hpp"

using namespace std;

#ifndef METRIK_HPP
#define METRIK_HPP

class MetrikVerhalten{
    public:
        virtual double abstand(const Punkt&, const Punkt&) = 0;
};

class Metrik2D : public MetrikVerhalten{
    using MetrikVerhalten::abstand;

    public:
        double abstand(const Punkt&, const Punkt&);

};

class Metrik3D : public MetrikVerhalten{
    using MetrikVerhalten::abstand;

    public:
        double abstand(const Punkt&, const Punkt&); 
};

#endif
