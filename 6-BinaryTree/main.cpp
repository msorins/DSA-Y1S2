#include <iostream>
#include "Heap/Heap.h"
#include "Iterators/InOrderRecursive.h"

int main() {
    Heap<int> heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);
    heap.insert(8);
    heap.insert(9);


    InOrderRecursive<int> heapIterator(&heap);
    while(heapIterator.valid()) {
        int crt = heapIterator.getInfo();

        cout<<crt<<" ";
        heapIterator.next();
    }
    return 0;
}