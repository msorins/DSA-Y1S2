//
// Created by Sorin Sebastian Mircea on 08/05/2017.
//

#ifndef INC_5_SSET_SSETITERATOR_H
#define INC_5_SSET_SSETITERATOR_H

#include "SSET.h"

template<class TElement>
class SSETIterator {
private:
    SSET<TElement> *set;
    int current;
public:
    //Constructor
    SSETIterator(SSET<TElement> *st);

    //Functionality
    TElement getCurrent();
    void next();
    bool valid();

};




#endif //INC_5_SSET_SSETITERATOR_H
