#include <iostream>
using namespace std;
#include "SSL.h"
#include "SSLIterator.h"

int main() {
    SSL<int> v;

    v.insertFirst(1);
    v.insertFirst(2);
    v.insertFirst(3);
    v.insertFirst(4);
    v.insertFirst(5);

    SSLNode<int> *node = v.search(1);
    v.insertAfter(*node, 99);

    SSLIterator<int> it(&v);

    while(it.valid()) {
        cout<<it.getCurrent()<<" ";
        it.next();
    }
}