//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#ifndef DSA_4MAP_TELEM_H
#define DSA_4MAP_TELEM_H
#include <string.h>
#include <iostream>
#include <list>
#include "DA/DA.h"

using namespace std;

template<class TElement>
class Elem {
public:
    string key;
    DA<TElement> vl;
};


#endif //DSA_4MAP_TELEM_H
