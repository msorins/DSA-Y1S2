//
// Created by Sorin Sebastian Mircea on 10/06/2017.
//

#ifndef INC_6_SIMPLIFIED_PRERECURSIVE_H
#define INC_6_SIMPLIFIED_PRERECURSIVE_H
#include <iostream>
#include <vector>
using namespace std;

class PreRecursive {
private:
    int *v;
    int n;
public:
    PreRecursive(int *v, int n);
    void compute(int pos);
};


#endif //INC_6_SIMPLIFIED_PRERECURSIVE_H
