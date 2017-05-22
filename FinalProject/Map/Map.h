//
// Created by Sorin Sebastian Mircea on 21/05/2017.
//

#ifndef DSA_4MAP_MAP_H
#define DSA_4MAP_MAP_H


#include "Elem.h"
#include "../HashMap/HashMap.h"

template<class TKey, class TElement>
class Map {
private:
    int m;
    HashMap< Elem<TKey, TElement> > *elems;

public:
    //Constructor
    Map(int m);

    //Getters and Setters
    HashMap< Elem<TKey, TElement> > getElems();
    HashMap< Elem<TKey, TElement> > *getElemsRef();

    //Functionality
    void add(TKey key, TElement value);
    bool erase(TKey key);
    bool find(TKey key);
    int size();
};



#endif //DSA_4MAP_MAP_H
