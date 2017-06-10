//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "PostRecursive.h"

PostRecursive::PostRecursive(int *v, int n) {
    this-> v = v;
    this-> n = n;
    this->compute(1);
}

void PostRecursive::compute(int pos) {

    if(pos * 2 <= this->n)
        compute(pos * 2);

    if(pos * 2 + 1 <= this->n)
        compute(pos * 2 + 1);

    cout << pos << " ";
}
