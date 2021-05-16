#include "Fifo.h"

using namespace std;

//////////////////////////////////////////////////////

Fifo::~Fifo(){
    while(head != NULL){
        deleteHead();
        delete temp;
    }
}

Fifo::Fifo(){
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void Fifo::deleteHead(){
    if(head->next != NULL){
        temp = head->next;
        delete head;
        head = temp;
    }
    else{
        delete head;
        head = NULL;
    }
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
    if(head != NULL){
        out = head->data;
        deleteHead();
    }
    else
        throw new bad_alloc;

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

void Fifo::operator>>(string& str){
    str = head->data;
    this->pop();
}

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

Fifo::operator int () const{
    return this->size();
}

