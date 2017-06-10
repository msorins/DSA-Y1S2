//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_6_SIMPLIFIED_INRECURSIVE_H
#define INC_6_SIMPLIFIED_INRECURSIVE_H


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class InRecursive {
private:
    int *v;
    int n;
public:
    InRecursive(int *v, int n);
    void compute(int pos);
};




#endif //INC_6_SIMPLIFIED_INRECURSIVE_H
