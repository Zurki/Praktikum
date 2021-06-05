#include <iostream>

using namespace std;

#ifndef PUNKT_HPP
#define PUNKT_HPP

class Punkt{    
    public:
        virtual string toString();
};

class Punkt2D : public Punkt{
    public:
        double x, y = 0.0;
        Punkt2D(double _x, double _y): x(_x), y(_y){}
        string toString();
};

class Punkt3D : public Punkt{
    public:
        double x, y, z = 0.0;
        Punkt3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z){}
        string toString();
};

#endif
