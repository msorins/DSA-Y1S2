#include <iostream>
#include "HashMap/HashMap.h"
#include "Tests/TestHashMap.h"
#include "Map/Map.h"
#include "HashMap/HashMapIterator.h"
#include "Map/MapIterator.h"
#include "Tests/TestMap.h"

using namespace std;
int main() {
    TestHashMap testHashMap;
    TestMap testMap;

    /*
    Map<string> x;

    x.add("masina", "Lamborghini");
    x.add("motocicleta", "Kawasaky");
    x.erase("masina");
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


    Map<string, int> mp(17);
    mp.add("masina", 10);
    mp.add("costel", 23);
    mp.add("jenica", 23);
    mp.add("A", 23);


    MapIterator< string, int > mpIt(&mp);


    while(mpIt.valid()) {
        Elem<string, int> crt = mpIt.getCurrent();
        cout<<crt.key<<" "<<crt.el<<"\n";
        mpIt.next();
    }



    //MAP 2
    cout<<"\n\n\n";

    Map<int, int> mpI(17);
    mpI.add(1, 10);
    mpI.add(2, 23);
    mpI.add(3, 23);
    mpI.add(4, 23);



    MapIterator< int, int > mpItI(&mpI);


    while(mpItI.valid()) {
        Elem<int, int> crt = mpItI.getCurrent();
        cout<<crt.key<<" "<<crt.el<<"\n";
        mpItI.next();
    }

}