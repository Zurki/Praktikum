#include <cmath>
#include "Punkt.hpp"
#include "GeoObjekt.hpp"
#include "Koerper.hpp"
#include "Metrik.hpp"
#include "Metrik.hpp"
#include <iostream>

double Metrik2D::abstand(const Punkt& p1, const Punkt& p2){
    const Punkt2D *newP1 = dynamic_cast<const Punkt2D*>(&p1);
    const Punkt2D *newP2 = dynamic_cast<const Punkt2D*>(&p2);

    return sqrt(pow(newP2->x - newP1->x, 2.0) + pow(newP1->y - newP2->y, 2.0));
}

double Metrik3D::abstand(const Punkt& p1, const Punkt& p2){
    const Punkt3D *newP1 = dynamic_cast<const Punkt3D*>(&p1);
    const Punkt3D *newP2 = dynamic_cast<const Punkt3D*>(&p2);
    
    return sqrt(pow(newP2->x - newP1->x, 2.0) + pow(newP2->y - newP1->y, 2.0) + pow(newP2->z - newP1->z, 2.0));
}
