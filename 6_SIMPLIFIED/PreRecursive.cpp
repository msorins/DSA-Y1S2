//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "PreRecursive.h"

void PreRecursive::compute(int pos) {
    cout<<pos<<" ";

    if(pos * 2 <= this->n)
        compute(pos * 2);
    if(pos * 2 + 1 <= this->n)
        compute(pos * 2 + 1);
}

PreRecursive::PreRecursive(int *v, int n) {
    this->v = v;
    this->n = n;
    compute(1);
}
