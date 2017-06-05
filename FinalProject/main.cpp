#include <iostream>
#include <fstream>
#include "HashMap/HashMap.h"
#include "Tests/TestHashMap.h"
#include "Map/Map.h"
#include "HashMap/HashMapIterator.h"
#include "Map/MapIterator.h"
#include "Tests/TestMap.h"

#include <cmath>
using namespace std;

struct pc {
    double x, y;
};

void printSquare(pc pc0, pc pc1, pc pc2, pc pc3) {
    cout<<"("<<pc0.x<<" "<<pc0.y<<")"<<", ";
    cout<<"("<<pc1.x<<" "<<pc1.y<<")"<<", ";
    cout<<"("<<pc2.x<<" "<<pc2.y<<")"<<", ";
    cout<<"("<<pc3.x<<" "<<pc3.y<<")"<<", ";
    cout<<"\n";
}

pc computePc2(pc pc0, pc pc1) {
    /*
     * DESCR: computes the the 2nd of the square
     * INPUT: pc0 and pc1 are 'diagonalele'
     */

    double mijX = ( pc0.x + pc1.x ) / 2;
    double mijY = ( pc0.y + pc1.y ) / 2;

    double dX = abs(mijX - pc0.x);
    double dY = abs(mijY - pc0.y);

    pc pc2;

    if(pc0.y < pc1.y) {
        pc2.x = mijX + dY;
        pc2.y = mijY - dX;
    } else {
        pc2.x = mijX - dY;
        pc2.y = mijY - dX;
    }

    return pc2;
}

pc computePc3(pc pc0, pc pc1) {
    /*
     * DESCR: computes the the 3rd of the square
     * INPUT: pc0 and pc1 are 'diagonalele'
     */

    double mijX = ( pc0.x + pc1.x ) / 2;
    double mijY = ( pc0.y + pc1.y ) / 2;

    double dX = abs(mijX - pc0.x);
    double dY = abs(mijY - pc0.y);

    pc pc3;

    if(pc0.y < pc1.y) {
        pc3.x = mijX - dY;
        pc3.y = mijY + dX;
    } else {
        pc3.x = mijX + dY;
        pc3.y = mijY + dX;
    }

    return pc3;
}

int main() {
    TestHashMap testHashMap;
    TestMap testMap;

    ifstream in("data.in");

    Map<double, double> mapX( 1039 );
    int n, numberOfPoints = 0;
    pc crtPc;

    in >> n;
    for(int i = 1; i <= n; i++) {
        in >> crtPc.x >> crtPc.y;
        mapX.add(crtPc.x, crtPc.y);
    }

    MapIterator< double, double > mpItI(&mapX);
    MapIterator< double, double > *mpItJ;

    while(mpItI.valid()) {

        mpItJ = new MapIterator<double, double> (&mapX);
        while(mpItJ->valid()) {
            pc pc0, pc1, pc2, pc3;
            pc0.x = mpItI.getCurrent().key;
            pc0.y = mpItI.getCurrent().el;

            pc1.x = mpItJ->getCurrent().key;
            pc1.y = mpItJ->getCurrent().el;

            if(pc0.x == pc1.x && pc0.y == pc1.y ) {
                mpItJ->next();
                continue;
            }

            pc2 = computePc2(pc0, pc1);
            pc3 = computePc3(pc0, pc1);


            if(mapX.find(pc2.x) &&  mapX.get(pc2.x).el - pc2.y <= 0.0001) // pc2 is a match
                if(mapX.find(pc3.x) &&  mapX.get(pc3.x).el -  pc3.y  <= 0.0001) //pc3 is a match
                    printSquare(pc0, pc1, pc2, pc3), numberOfPoints++;

            mpItJ->next();
        }

        delete mpItJ;
        mpItI.next();
    }
    
    cout<<"Total number of points: " << numberOfPoints ;
    return 0;
}
