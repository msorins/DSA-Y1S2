//
// Created by Sorin Sebastian Mircea on 22/05/2017.
//

#ifndef DSA_4MAP_HASHMAPITERATOR_H
#define DSA_4MAP_HASHMAPITERATOR_H


#include "HashMap.h"

template<class TElement>
class HashMapIterator {
private:
    HashMap<TElement> *map;
    int currentHash;

public:
    //Constructor
    HashMapIterator(HashMap<TElement> *map);

    //Functionality
    TElement getCurrent();
    void next();
    bool valid();

};



#endif //DSA_4MAP_HASHMAPITERATOR_H
