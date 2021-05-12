#include "Ringliste.h"
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////

/**
*Funktion: Erstellt ein Ringlistenobjekt mit der Standardgröße 10
*/
Ringliste::Ringliste(){
		capacity = 10;
}

/**
*Funktion: Erstellt ein Ringlistenobjekt mit der gegebenen größe
*/
Ringliste::Ringliste(int size){
		capacity = size;
}

Ringliste::~Ringliste(){
	cout << "Deconstruct" << endl;	
}

/////////////////////////////////////////////////////////////////

/**
*Funktion: Überläd den Stromoperator (<<) und fügt eine übergebene Ringliste an eine andere
*/
Ringliste& Ringliste::operator<<(Ringliste& r){
    if(list.size() >= capacity){
        writePos = 0;
    }
	for(int i = 0; i < r.getList().size(); i++){
			list.at(i) = r.getList().at(i);
			writePos++;
			readPos++;
	}  
	return *this;
}

/**
*Funktion: Überläd den Stromoperator (<<) und fügt eine übergebene Zahl hinzu
*/
Ringliste& Ringliste::operator<<(int num){
	if(list.size() >= capacity){
        writePos = 0;
    }

    if(list.size() < capacity){
			list.push_back(num);
			writePos++;
	}
	else{
		readPos++;
		list.at(writePos) = num;
	}
	return *this;
}

/**
*Funktion: Überläd den Operator zum addieren und hinzufügen (+=) und fügt eine übergebene Zahl an eine List hinzu
*/
Ringliste& Ringliste::operator+=(int insertNum){
    for(int i = 0; i < list.size(); i++){
			list.at(i) += insertNum;
	}
	return *this;
}

/**
*Funktion: Überprüft zwei Ringlisten auf gleiche Werte
*/
bool Ringliste::operator==(Ringliste r){
		return is_permutation(list.begin(), list.end(), r.getList().begin());
}


/////////////////////////////////////////////////////////////////

/**
*Funtkion: gibt eine Ringlistenreferenz zurück
*/
std::vector<int>& Ringliste::getList(){
		return this->list;
}

/**
*Funktion: toString-Methode zum ausgeben des Inhalts
*/
std::string Ringliste::toString(){
		std::string out = std::to_string(list.size()) + "/" +  std::to_string(capacity) + " | ";
		for(int i = 0; i < list.size(); i++){
				
				out += std::to_string(list.at(readPos)) + " ";
				readPos++;
				//cout << "readPos: " << readPos << endl;
				if(readPos >=  list.size())
						readPos = 0;
		}

        std::string unorderd;
        for(int j = 0; j < list.size(); j++){
            unorderd += to_string(list.at(j)) + " ";
        }
		return out;
}

/////////////////////////////////////////////////////////////////

bool istTeilerVon_n::operator()(int zahl) const{
		return !(teiler%zahl);
}

bool istTeilerVon_n::operator()(int n, int zahl) const{
		return !(n % zahl);
}

/////////////////////////////////////////////////////////////////

bool istNahe::operator()(double in1) const{
		double tmp = std::abs(hinterlegt - in1);
		//cout << "tolerance: " << tolerance << " | tmp: " <<  tmp << endl;
		return !(tolerance < tmp);
}

bool istNahe::operator()(double in1, double in2) const{
		double tmp = std::abs(in1 - in2);
		return !(tolerance < tmp);
}

/////////////////////////////////////////////////////////////////

bool istKuerzerAls::operator()(std::string obj1, std::string obj2)const{
		return !(obj1.length() == obj2.length());
}

/////////////////////////////////////////////////////////////////

bool besitztMehrWorteAls::operator()(std::string obj2)const{
    return (countWords(obj1) > countWords(obj2));
}

int besitztMehrWorteAls::countWords(std::string sent)const{
    int count = 0;
    int tmp = 0;
    for(int i = 0; i < sent.length(); i++){
        if(sent.at(i) == ' '){
            tmp = 0;
        }
        tmp++;
        if(tmp > 2){
            count++;
        }
    }
    return count;
}

/////////////////////////////////////////////////////////////////


