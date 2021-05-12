#include "Fifo.h"

using namespace std;

//////////////////////////////////////////////////////

Fifo::~Fifo(){
    //todo: alle Elemente zerstören
}

Fifo::Fifo(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void Fifo::deleteHead(){
    if(head->next != NULL)
        temp = head->next;
    delete head;
    head = temp;
}


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

string Fifo::pop(){
    string out = "";
    if(head->next != NULL)
        out = head->next->data;
    
    deleteHead();

    return out;
}

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

Fifo& Fifo::operator<<(const string& str){
    this->push(str);
    return *this;
}

Fifo& Fifo::operator>>(const string& str){
    fifoPtr t = this->head;



    while(t->data != str){
        this->deleteHead();
        if(t->next != NULL)
            t = t->next;
        else
            throw invalid_argument("no such string");
    }
    return *this;
}

int Fifo::size() const{
    fifoPtr t = head;
    int counter = 0;
    while(t != NULL){
        counter++;
        if(t->next !=NULL)
            t = t->next;
        else
            t = NULL;
    }
    return counter;
}

Fifo::operator int () const{
    return size();
}

