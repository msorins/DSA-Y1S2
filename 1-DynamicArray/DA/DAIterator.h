//
// Created by Sorin Sebastian Mircea on 30/04/2017.
//

#ifndef INC_1_SINGLYLINKEDLISTDYNAMIC_SLLITERATOR_H
#define INC_1_SINGLYLINKEDLISTDYNAMIC_SLLITERATOR_H
#include "DA.h"

template<class TElement>
class DAIterator {
private:
    DA<TElement>* bag;
    int currentPos;
public:
    //CONSTRUCTOR
    DAIterator(DA<TElement>* b);

    //Functionality
    TElement getCurrent();
    bool valid();
    void next();
};




#endif //INC_1_SINGLYLINKEDLISTDYNAMIC_SLLITERATOR_H
