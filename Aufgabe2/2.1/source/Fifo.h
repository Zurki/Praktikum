#include <string>
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////

class Fifo{
    private:
        typedef struct FifoElement{ //struct mit typedef
            FifoElement* next;
            string data;
        } * fifoPtr; //fifoPtr = FifoElement* (alias)


        fifoPtr head; //start der linkedList
        fifoPtr curr; //currently used
        fifoPtr temp; //temporärer elementpointer

        void deleteHead();
        
    public:
        Fifo();
        Fifo(const Fifo&);
        ~Fifo();
       
        Fifo& operator<<(const string&);
        void operator>>(string&);
        operator int () const;
        Fifo operator=(const Fifo&);
        bool operator>(int i);

        int size()const;
        void info();
        string pop();
        void push(string val);
};

//////////////////////////////////////////////////////
