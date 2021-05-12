#include <iostream>
#include "Fifo.h"

int main(){
    Fifo f;

    f.push("test1");
    f.push("test2");
    f.push("test3");


    std::cout << f << endl;

    f.pop();
    
    f.info();

    f << "eins" << "2" << "fuenf";

    f.info();

    f >> "fuenf";
    f.info();
    std::cout << f << endl;
    system("pause");
    return 0;
}
