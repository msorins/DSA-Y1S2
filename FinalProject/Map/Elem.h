//
// Created by Sorin Sebastian Mircea on 07/05/2017.
//

#ifndef DSA_4MAP_TELEM_H
#define DSA_4MAP_TELEM_H
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

template<class TElement>
class Elem {
public:
    string key;
    TElement el;

public:
    //Overload operators
    friend bool operator== (const Elem &a, const Elem &b) {
        return a.el == b.el;
    };
};


#endif //DSA_4MAP_TELEM_H
