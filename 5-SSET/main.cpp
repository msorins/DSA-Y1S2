#include <iostream>
#include "SSET.h"
#include "SSETIterator.h"
using namespace std;

int compAsc(int a, int b) {
    return a < b;
}

int compDesc(int a, int b) {
    return a > b;
}

int main() {

    SSET<int> set(compAsc);
    set.add(5);
    set.add(1);
    set.add(9);
    set.add(4);
    set.add(100);


    SSETIterator<int> it(&set);
    while(it.valid()) {
        cout<<it.getCurrent()<<" ";
        it.next();
    }

    return 0;
}