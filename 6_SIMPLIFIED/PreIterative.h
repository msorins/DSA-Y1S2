//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_6_SIMPLIFIED_PREITERATIVE_H
#define INC_6_SIMPLIFIED_PREITERATIVE_H


#include "PreRecursive.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class PreIterative {
private:
    int *v;
    int n;
public:
    PreIterative(int *v, int n);
    void compute(int pos);
};


#endif //INC_6_SIMPLIFIED_PREITERATIVE_H
