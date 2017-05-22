#include <iostream>
#include "HashMap/HashMap.h"
#include "Tests/TestHashMap.h"
#include "Map/Map.h"

using namespace std;
int main() {
    TestHashMap test;

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

    /*
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
     */


    Map<int> mp(17);
    mp.add("masina", 10);
    mp.add("masina", 23);

    cout<<mp.size();

    

}