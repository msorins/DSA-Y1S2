//
// Created by Sorin Sebastian Mircea on 21/05/2017.
//

#ifndef DSA_4MAP_MAP_H
#define DSA_4MAP_MAP_H


#include "Elem.h"
#include "../HashMap/HashMap.h"

template<class TElement>
class Map {
private:
    int m;
    HashMap< Elem<TElement> > *elems;

public:
    //Constructor
    Map(int m);

    //Getters and Setters
    HashMap< Elem<TElement> > getElems();

    //Functionality
    void add(string key, TElement value);
    bool remove(string key);
    bool search(string key, TElement value);
    int size();
};



#endif //DSA_4MAP_MAP_H
