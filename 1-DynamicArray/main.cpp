#include <iostream>
#include "DA.h"
#include "DAIterator.h"

using namespace std;
#include <vector>

void func(vector<int> blabla) {
    
}
int main() {

    DA<int> v(1);
    v.addToEnd(1);
    v.addToEnd(2);
    v.addToEnd(3);
    v.addToEnd(4);
    v.addToEnd(5);
    v.addToEnd(6);
    v.addToEnd(7);
    v.addToEnd(8);
    v.addToEnd(9);
    v.addToEnd(10);
    v.addToEnd(11);
    //v.addToEnd(5);


    DA<int> v2(1);
    v2 = v;

    int c = 3;




}