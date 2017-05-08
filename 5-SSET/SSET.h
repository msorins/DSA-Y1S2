//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#ifndef INC_5_SSET_SSET_H
#define INC_5_SSET_SSET_H

#include "DA/DA.h"

template<class TElement>
class SSET {
private:
    DA<TElement> elems;
    int (*comp)(TElement, TElement);
public:
    //Constructor
    SSET(int (*cmp)(TElement, TElement));

    //Setters and getters
    DA<TElement> getElems();
    void setElems(DA<TElement> &elems);

    //Functionality
    bool add(TElement el);
    bool remove(TElement el);
    bool find(TElement el);
    int size();

};




#endif //INC_5_SSET_SSET_H
