#include <iostream>
#include <string>
#include "Fifo.h"

using namespace std;

void test(){
     Fifo f;
     f.push("123");
     f.push("tesdt");
     f.push("test1234");
     while(f > 0){
         cout << f.pop() << endl;
     }
}


int main(){
    test();
    system("pause");
    return 0;
}
