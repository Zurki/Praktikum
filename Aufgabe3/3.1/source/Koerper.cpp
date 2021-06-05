#include <cmath>
#include "Punkt.hpp"
#include "GeoObjekt.hpp"
#include "Koerper.hpp"
#include "Metrik.hpp"
#include "Metrik.hpp"

Rechteck::Rechteck(Punkt2D p1, Punkt2D p2){
    MetrikVerhalten* n = new Metrik2D;
    m = n;

    *lu = p1;
    *ro = p2;
}

void Rechteck::setzePunktLu(const Punkt2D& p){
    *lu = p;
}

void Rechteck::setzePunktRo(const Punkt2D& p){
    *ro = p;
}

Rechteck* Rechteck::clone(){
    Rechteck* copyRechteck = new Rechteck(*lu, *ro); 
    return copyRechteck;
}

string Rechteck::toString(){
    return "test123";
}

double Rechteck::inhalt(){
    return lu->x * lu->y;
}

//////////////////////////////////////////////////////

Kreis::Kreis(Punkt2D p1, double radius){
    MetrikVerhalten* n = new Metrik2D;
    m = n;

    *zentrum = p1;
    this->radius = radius;
}

void Kreis::setzeZentrum(const Punkt2D& p){
    *zentrum = p;
}

void Kreis::setzeRadius(const double r){
    this->radius = r;
}

Kreis* Kreis::clone(){
    Kreis* copyKreis = new Kreis(*zentrum, radius);
    return copyKreis;
}

string Kreis::toString(){
    return "testKreis";
}

double Kreis::inhalt(){
    return M_PI * pow(radius, 2.0);
}

//////////////////////////////////////////////////////

Quader::Quader(Punkt3D p1, Punkt3D p2){
    MetrikVerhalten* n = new Metrik3D;
    m = n;

    *luv = p1;
    *roh = p2;
}

void Quader::setzePunktLuv(const Punkt3D& p){
    *luv = p;
}

void Quader::setzePunktRoh(const Punkt3D& p){
    *roh = p;
}

Quader* Quader::clone(){
    Quader* copyQuader = new Quader(*luv, *roh);
    return copyQuader;
}

string Quader::toString(){
    return "testQuader";
}

double Quader::inhalt(){
    return luv->x * luv->y * luv->z;
}

//////////////////////////////////////////////////////

Ball::Ball(Punkt3D p, double r){
    MetrikVerhalten* n = new Metrik3D;
    m = n;

    *zentrum = p;
    this->radius = r;
}

void Ball::setzeZentrum(const Punkt3D& p){
    *zentrum = p;
}

void Ball::setzeRadius(const double r){
    this->radius = r;
}

Ball* Ball::clone(){
    Ball* copyBall = new Ball(*zentrum, radius);
    return copyBall;
}

string Ball::toString(){
    return "testBall";
}

double Ball::inhalt(){
    return (3.0/4.0) * M_PI * pow(radius, 3.0);
}
