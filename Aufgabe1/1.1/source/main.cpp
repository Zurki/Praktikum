/*
*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*Aufgabe :  Ein - und Ausgabe
*Autor : Henk Hornschuh
*
*Beschreibung: Das Programm soll eine Textdatei in das richtige Format formatieren, Zahlen in Hexadezimal um rechnen und runden.
*
*∗Praktikum Programmierung 2 , HS Osnabrueck
 *−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
/*
*Funktion: split
*Beschreibung: diese Funktion splaltet einen übergebenen string in einen vector, nach dem übergegeben delimiter
*
*IN: string = "Hallo das ist ein test"
*OUT: vector = {"Hallo", "das", "ist", "ein", "test"}
*
*return: vector von strings
*
*/
vector<string> split(string toSplit, char delimiter){
		stringstream ss(toSplit);
		string item;
		vector<string> splittedStrings;
		while(getline(ss, item, delimiter)){
				splittedStrings.push_back(item);
		}
		return splittedStrings;
}

/*
*Funktion: formatStringVec
*Beschreibung: bekommen einen Stringvector übrgeben und gibt eine überarbeitete version als string aus
*
*IN: vector = {"123 3.456142234 Hey", "543 1235.141251 Moin"}
*OUT: string = "1. | 007b | 3.45614 | -----------Hey\n
*               2. | 021F | 1235.14 | ----------Moin\n"
*
*return: string enstanden aus dem rohen vector
*
*/
string formatStringVec(vector<string> stringVec){
		stringstream backStringStream;
		for(int i = 0; i < stringVec.size(); i++){
				stringstream hexNum;
				
				backStringStream<< i+1 << ". | ";
				string tmp = stringVec.at(i);
				
				vector<string> tmpVec = split(tmp, ' ');
				
				hexNum << hex << stoi(tmpVec.at(0));
				for(int j = hexNum.str().length(); j <= 3; j++){
						backStringStream << "0";
				}
				backStringStream << hexNum.str() << " | " << setprecision(6) << stof(tmpVec.at(1)) << " | " << setw(15) << setfill('-')  << tmpVec.at(2) << "\n";
		}
		return backStringStream.str();
}

/*
*Funktion: readFileGetOutput
*Beschreibung: bekommt einen Dateinamen und öffnet die Datei. Liest die Datei und schreibt den Inhalt zeilenweise in einen Vector
*
*IN: Dateiname
*OUT: siehe Funktion "formatStringVec"
*
*return: string, siehe Funktion "formatStringVec"
*
*/
string readFileGetOutput(string pathInput){
		string outputString = "";
		vector<string> stringVec;
		
		ifstream inputFile;
		
		
		inputFile.open(pathInput, ios::in);
		if(!inputFile){ //checken, ob die datei Existiert
				cout << "cannot open file" << "\n";
				return "error\n";
		}
		
		string str; //string wird für die einzelnen einträge gebraucht
		
		while(getline(inputFile, str)){
				if(str.size() > 0){
						stringVec.push_back(str); //hinzufügen eines strings in den vector
				}
		}
		
		return formatStringVec(stringVec);
}


/*
*Funktion: createOutputFile
*Beschreibung: bekommt einen string und einen Dateinamen. Erstellt eine Datei mit dem Dateinamen und schreibt den Inhalt des strings in sie
*
*IN: string und Dateiname
*OUT: True, wenn erfolgreiche Dateierstellung / False, wenn Dateierstellung fehlgeschlagen
*
*return: bool
*/
bool createOutputFile(string toWrite, string pathOutput){
		fstream output;
		output.open(pathOutput, ios::out);
		if(output.is_open()){
				output << toWrite;
				output.close();
		}
		else{
				return false;
		}
		return true;
}

/*
*Funktion: main
*Beschreibung: steuerndes Element des Programms
*
*IN: /
*OUT: 0
* 
*/

int main(){
		string eing = readFileGetOutput("eingabe.txt");
		if(createOutputFile(eing, "ausgabe.txt")){
				cout << "done" << endl;
		}
		else {
				cout << "error" << endl;
		}
		
		system("pause");
		
		return 0;
}
