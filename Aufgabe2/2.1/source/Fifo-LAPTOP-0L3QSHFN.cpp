#include "Fifo.h"

using namespace std;

FifoElement::FifoElement(){
    value = "";
}

FifoElement::FifoElement(string val): value(val){
}

void FifoElement::setNext(int n){
    this->next = n;
}

int FifoElement::getNext(){
    return this->next;
}

//////////////////////////////////////////////////////

Fifo::~Fifo(){}

Fifo::Fifo(){
    
}

void Fifo::push(string val){
   FifoElement insElem(val);
   elem.push_back(insElem);
   insElem.setNext(elem.size());
}

void Fifo::pop(){
    elem.erase(elem.begin());
    for(e : elem){
        e.setNext(getNext()-2);
    }
}

Fifo::operator int () const{
    return elem.size();
}

