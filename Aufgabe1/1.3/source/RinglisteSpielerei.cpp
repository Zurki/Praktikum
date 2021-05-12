/**
* -----------------------------------------------------------------------------
*
* Beispielprogramm: RinglisteSpielerei.cpp
*
* Verwendungsbeispiel der Klasse Ringliste
*
* Praktikum Programmierung 2, O. Henkel, HS Osnabrueck
* -----------------------------------------------------------------------------
*/

#include "Ringliste.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <sys/types.h>

using namespace std;

int main() {
		Ringliste rListe(5);               // Kapazitaet=5
		cout << rListe.toString() << endl; // toString-Methode
		
		rListe << 1 << 2 << 3; // operator<< geeignet ueberladen 
		cout << rListe.toString() << endl;
		rListe << 4 << 5 << 6;
		cout << rListe.toString() << endl;
		Ringliste vergleich(5);
		vergleich << 2 << 3 << 4 << 5 << 6;
		
		// erwartet: true
		cout << boolalpha << (rListe==vergleich) << endl;
		
		Ringliste drei; // Kapazitaet=10 (Default)
		drei << 3 << 3 << 3;
		drei+=6;        // operator+= geeignet ueberladen
		cout << drei.toString() << endl;
		
		rListe << drei; // operator<< geeignet ueberladen
		cout << rListe.toString() << endl;
		cout << drei.toString() << endl;
		
		istTeilerVon_n teiler{2};
		cout << "ist 2 teiler von 2: " << teiler(2) << endl;
		cout << "ist 2 teiler von 2: " << teiler(2, 2) << endl;
		
		istNahe nahe{1.3, 0.1};
		cout << "ist 1.3, mit prezision 0.1, 1.1 nahe: " << nahe(1.1) << endl;
		
		istKuerzerAls kuerzer;
		cout << "ist 'hallo' kuerzer als 'hallo': " <<  kuerzer("hallo", "hallo") << endl;

        besitztMehrWorteAls mehrWorte{"Das ist satz nummer 1"};
        cout << "besitzt 'Das ist Satz nummer 1' mehr Worte als 'Das ist Satz nummer 2': "<<mehrWorte("das ist satz nummer zwei");


        int stop;
        cin >> stop;
        return 0;
}
