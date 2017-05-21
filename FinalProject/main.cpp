#include <iostream>
#include "HashMap/HashMap.h"
#include "Tests/TestHashMap.h"

using namespace std;
int main() {
    /*
    Map<string> x;

    x.add("masina", "Lamborghini");
    x.add("motocicleta", "Kawasaky");
    x.remove("masina");
    x.insert("masina", "Lamborghini");

    MapIterator<string> it(&x);
    while(it.isValid()) {
        cout<<it.getCurrent().first<<" -> "<<it.getCurrent().second<<"\n";
        it.next();
    }
     */

    HashMap<int> h(10);
    h.insert(10);
    h.insert(15);
    h.insert(26);
    h.insert(30);
    h.insert(25);
    h.insert(35);
    h.insert(45);
    h.insert(12);
    h.insert(24);
    h.insert(24);
    //cout<<h;

    TestHashMap test;

}