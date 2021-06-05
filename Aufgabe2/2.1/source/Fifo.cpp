#include "Fifo.h"

using namespace std;

//////////////////////////////////////////////////////

/**
 *
 * Funktion: Dekonstruktor eines FIFOs
 *
 */
Fifo::~Fifo(){
    while(head != NULL){
        deleteHead();
        delete temp;
    }
}

/**
 *
 * Funktion: Konstruktor eines leeren FIFOs
 *
 */
Fifo::Fifo(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

/**
 *
 * Funktion: Konstruktor eines FIFOs anhand eienes bestehendens FIFOs
 *
 */
Fifo::Fifo(const Fifo& f){
    head = NULL;
    curr = NULL;
    temp = NULL;

    temp = f.head;
    while(temp != NULL){
        this->push(this->temp->data);
        temp = temp->next;
    }
}

/**
 *
 * Funktion: löscht den head eines FIFOs
 *
 */
void Fifo::deleteHead(){
    if(head->next != NULL){
        temp = head->next;
        delete head;
        head = temp;
        temp = NULL;
    }
    else{
        delete head;
        head = NULL;
    }
}

/**
 *
 * Funktion: Fügt ein Element an ein FIFO an
 *
 */
void Fifo::push(string val){
    fifoPtr n = new FifoElement;
    
    n->next = NULL;
    n->data = val;

    if(head != NULL){
        curr = head;
        while(curr->next != NULL){ //sichergehen das curr am ende steht
            curr = curr->next;
        }
        curr->next = n;
    }
    else
        head = n;
}

/**
 *
 * Funktion: popped ein FIFO, gibt einen String mit dem obersten Element aus
 *
 */
string Fifo::pop(){
    string out = "";
    if(head != NULL){
        out = head->data;
        deleteHead();
    }
    else
        throw "unterlauf";

    return out;
}

/**
 *
 * Funktion: Gibt den ganzen Inhalt eines FIFOs aus
 *
 */
void Fifo::info(){
    string out;
    fifoPtr t = head;
    while(t != NULL){
        out += t->data + " ";
        if(t->next != NULL)
            t = t->next;
        else
            t = NULL;
    }
    cout << out << endl;
}

/**
 *
 * Funktion: stream Operator der ein Element pushed
 *
 */
Fifo& Fifo::operator<<(const string& str){
    this->push(str);
    return *this;
}

/**
 *
 * Funktion: stream Operator der das oberste Element popped und in einem String speichert
 *
 */
void Fifo::operator>>(string& str){
    str = this->pop();
}

/**
 *
 * Funktion: gibt die groeße eines FIFos zurück
 *
 */
int Fifo::size() const{
    int counter = 0;
    if(head != NULL){
    fifoPtr t = head;
        while(t != NULL){
            counter++;
            if(t->next !=NULL)
                t = t->next;
            else
                t = NULL;
        }
    }
    return counter;
}

/**
 *
 * Funktion: überprüft ob die Anzahl an Elementen in dem FIFO groeßer ist als eine Zahl i
 *
 */
bool Fifo::operator>(int i){
    return this->size() > i;
}

/**
 *
 * Funktion: setzt ein FIFO mit einem anderen gleich
 *
 */
Fifo Fifo::operator=(const Fifo& fl){
    Fifo f(fl);
    while(this->size() > 0){
        this->deleteHead();
    }

    fifoPtr tempF = f.head;
    while(tempF != NULL){
        push(tempF->data);
        tempF = tempF->next;
    }
    return *this;    
}

/**
 *
 * Funktion: laesst den FIFO direkt aufrufen um direkt die groeße zu bekommen
 *
 */
Fifo::operator int () const{
    return this->size();
}
