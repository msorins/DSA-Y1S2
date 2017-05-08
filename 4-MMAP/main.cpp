#include <iostream>
#include "Map.h"
#include "MapIterator.h"
using namespace std;
int main() {
    Map<string> x;

    x.add("masina", "Lamborghini");
    x.add("motocicleta", "Kawasaky");
    x.add("masina", "Porsche");
    x.add("masina", "Dacie");


    MapIterator<string> it(&x);
    while(it.isValid()) {
        cout<<it.getCurrent().first<<" -> "<<it.getCurrent().second<<"\n";
        it.next();
    }

    //cout<<x;
}