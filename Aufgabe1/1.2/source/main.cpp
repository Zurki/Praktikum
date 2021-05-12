#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

float abschneiden(float toCut, int precision);
bool enthaeltGenauEinmal7(int num);

int main(){
    while(1){
        int vote = 0;
        cout << "1. abschneiden\n" << "2. enthaeltGenauEinmal7\n";
        cin >> vote;
        switch(vote){
            //case 1
            case 1: {
								
								float toCut = 0.0;
								int precision = 0;
								
								cout << "floatnumber: ";
								cin >> toCut;
								cout << "\nprecision: ";
								cin >> precision;
								
								float out = abschneiden(toCut, precision);
								cout << "\nenthaelt: " << out << "\n----------------------\n";
								break;
						}
            //case 2
            case 2: {
								int num = 0;
								cout << "Number: ";
								cin >> num;
								if(enthaeltGenauEinmal7(num)){
										cout << "enthaelt genau einmal 7!" << endl;
								}
								break;
						}
						//default
						default: {
								throw invalid_argument("NOT AN OPTION");
						}
        }
				cout << endl  << "---------------------------" << endl << endl;
    }
    return 0;
}


float abschneiden(float num, int n){
		stringstream ss;
		
    if(num < 0 || num > 1000 || n < 1 || n > 5){
				throw invalid_argument("NO VALID INPUT");
		}
		
		string help = to_string(num);
		int point = help.find('.');
    ss << fixed << setprecision(n + point - 1) << num;
    float x = stof(ss.str());
    return x;
}

bool enthaeltGenauEinmal7(int num){
    vector<int> numVec;
		
    //fügt alle zahlen in einen Vektor hinzu
		while(num > 0){
        int digit = num%10;
        num /= 10;
        numVec.push_back(digit);
    }
		
		reverse(numVec.begin(), numVec.end());
		
		int count = 0; // counter für Ausgabe
		try{
				//durchläuft den Vektor
				for(int i = 0; i < numVec.size(); i++){
						if(numVec.at(i) == 7){ //fügt den etwas zu dem counter hinzu, sobald eine 7 vorkommt
								count++; 
						}
				}
				
				//wenn counter = 0, dann throw invalid_argument
				if(count == 0)
						throw invalid_argument("keine sieben");
				else if(count > 1){
						//cout << "fehler";
						throw invalid_argument("welche sieben");
				}
				return true;
		}
		catch(invalid_argument& ea){
				if(count > 1){
						int which;
						do{
								cout << "welche 7? >";
								cin >> which;
						}
						while(which < 1 || which-1 >=  numVec.size());
						
						if(numVec.at(which -1) == 7){
								return true;
						}
				}
				return false;
		}
}