#include <iostream>
#include <vector>
#include "PreRecursive.h"
#include "PreIterative.h"
#include "InRecursive.h"
#include "InIterative.h"
#include "PostRecursive.h"
#include "PostIterative.h"

using namespace std;

int main() {
    int v[100];
    for(int i = 0; i <= 15; i++)
        v[i] = i;

    PreRecursive pr(v, 15); cout<<"\n";
    PreIterative pi(v, 15); cout<<"\n";
    InRecursive ir(v, 15); cout<<"\n";
    InIterative it(v, 15); cout<<"\n";
    PostRecursive por(v, 15); cout<<"\n";
    PostIterative poi(v, 15); cout<<"\n";
}