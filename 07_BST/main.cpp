#include <iostream>
#include "BST/BST.h"
#include "Iterator/Iterator.h"

using namespace std;

int main() {
    BST<int> bst;


    bst.insert(15);
    bst.insert(13);
    bst.insert(16);
    bst.insert(8);
    bst.insert(20);
    bst.insert(10);

    bool ok = true;

    Iterator<int> it(&bst);
    while(it.valid()) {
        cout << it.getInfo() << " ";
        it.next();
    }


    return 0;
}