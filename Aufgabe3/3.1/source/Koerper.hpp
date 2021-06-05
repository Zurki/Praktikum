#define _USE_MATH_DEFINES

#include <cmath>
#include "Punkt.hpp"
#include "GeoObjekt.hpp"
#include "Metrik.hpp"
#include "Metrik.hpp"
#include <iostream>


using namespace std;

class Rechteck : public GeoObjekt{
    Punkt2D* lu;
    Punkt2D* ro;

    public:
        Rechteck(Punkt2D, Punkt2D);

        void setzePunktLu(const Punkt2D&);
        void setzePunktRo(const Punkt2D&);

        Rechteck* clone();

        string toString();
        double inhalt();
};

class Kreis : public GeoObjekt{
    double radius;
    Punkt2D* zentrum;

    public:
        Kreis(Punkt2D, double);

        void setzeZentrum(const Punkt2D&);
        void setzeRadius(const double);

        Kreis* clone();

        string toString();
        double inhalt();
};

class Quader : public GeoObjekt{
    Punkt3D* luv;
    Punkt3D* roh;

    public:
        Quader(Punkt3D, Punkt3D);

        void setzePunktLuv(const Punkt3D&);
        void setzePunktRoh(const Punkt3D&);

        Quader* clone();

        string toString();
        double inhalt();
};

class Ball : public GeoObjekt{
    double radius;
    Punkt3D* zentrum;

    public:
        Ball(Punkt3D, double); 

        void setzeZentrum(const Punkt3D&);
        void setzeRadius(const double);

        Ball* clone();

        string toString();
        double inhalt();
};
