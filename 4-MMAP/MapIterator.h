//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#ifndef DSA_4MAP_MAPITERATOR_H
#define DSA_4MAP_MAPITERATOR_H

#include "Map.h"
#include <algorithm>
#include <iostream>
using namespace std;

template<class TElement>
class MapIterator {
public:
    Map<TElement>* container;
    int currentKeyPos;
    int currentValuePos;

public:
    //Constructors and destructors
    MapIterator(Map<TElement>* container);
    ~MapIterator();

    //Functionality
    pair<string, TElement> getCurrent();
    bool isValid();
    void next();

};


#endif //DSA_4MAP_MAPITERATOR_H
