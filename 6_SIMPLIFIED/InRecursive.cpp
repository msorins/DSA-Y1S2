//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#include "InRecursive.h"

InRecursive::InRecursive(int *v, int n) {
    this->v = v;
    this->n = n;
    this->compute(1);
}

void InRecursive::compute(int pos) {
    if(pos * 2 <= this->n)
        this->compute(pos * 2);

    cout << pos << " ";

    if(pos * 2 + 1 <= this->n)
        this->compute(pos * 2 + 1);

}


