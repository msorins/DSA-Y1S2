#include <iostream>
#include "DLL.h"

int main() {
    DLL<int> obj;

    obj.insertFirst(5);
    obj.insertFirst(4);
    obj.insertFirst(3);
    obj.insertFirst(2);
    obj.insertFirst(1);

    obj.insertAtPosition(3, 10);
    obj.deleteFirst();
    obj.insertFirst(1);

    obj.deleteByPosition(3);

    obj.deleteByValue(3);
    obj.insertAtPosition(3, 99);
    obj.deleteByValue(99);

    cout<<obj<<"\n";

}