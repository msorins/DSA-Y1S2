//
// Created by Sorin Sebastian Mircea on 22/05/2017.
//

#ifndef DSA_4MAP_MAPITERATOR_H
#define DSA_4MAP_MAPITERATOR_H

#include "../Map/Map.h"
#include "../HashMap/HashMapIterator.h"

template<class TElement>
class MapIterator {
private:
    Map<TElement> *map;
    HashMapIterator< Elem<TElement> > *hashMapIt;

public:
    //Constructor
    MapIterator(Map<TElement> *map);

    //Functionality
    Elem<TElement> getCurrent();
    void next();
    bool valid();
};


#endif //DSA_4MAP_MAPITERATOR_H
