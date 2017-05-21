//
// Created by Sorin Sebastian Mircea on 21/05/2017.
//

#include <cassert>
#include "TestHashMap.h"

TestHashMap::TestHashMap() {
    this->startTests();
}

void TestHashMap::initialiseContainer(int size) {
    this->container = new HashMap<int>(size);
}

void TestHashMap::startTests() {
    this->testInsert();
    this->testFind();
    this->testRemove();
}

void TestHashMap::testInsert() {
    HashMap<int> h(10);

    h.insert(10);
    h.insert(15);
    h.insert(26);
    h.insert(30);
    h.insert(25);
    h.insert(35);
    h.insert(45);
    h.insert(12);
    h.insert(24);
    h.insert(24);

    vector<int> elems = h.getElems();
    vector<int> nexts = h.getNexts();


    assert(elems[0] == 10 && nexts[0] == 9);
    assert(elems[1] == 24 && nexts[1] == 0);
    assert(elems[2] == 12 && nexts[2] == 0);
    assert(elems[3] == 24 && nexts[3] == 1);
    assert(elems[4] == 45 && nexts[4] == 3);
    assert(elems[5] == 15 && nexts[5] == 8);
    assert(elems[6] == 26 && nexts[6] == 0);
    assert(elems[7] == 35 && nexts[7] == 4);
    assert(elems[8] == 25 && nexts[8] == 7);
    assert(elems[9] == 30 && nexts[9] == 0);
}

void TestHashMap::testRemove() {
    HashMap<int> h(17);

    h.insert(2);
    h.insert(15);
    h.insert(15);

    assert( h.find(2) );
    assert( h.find(15) );

    assert( h.remove(15) );
    assert( h.find(15) );

    assert( h.remove(15) );
    assert( !h.find(15) );

    assert( !h.remove(15) );

    h.insert(17); //BYE
    h.insert(34); //BYE3
    h.insert(51); //BYE1
    h.insert(68);
    h.insert(85); //BYE2

    assert(h.remove(51));
    assert(!h.find(51));
    assert(h.find(68));
    assert(h.find(85));
    assert(h.find(17));
    assert(h.find(34));

    assert(h.remove(85));
    assert(!h.find(85));

    assert(h.remove(17));
    assert(!h.remove(17));
    assert(!h.find(17));
    assert(h.find(34));
    assert(h.find(68));

    assert(h.remove(34));
    assert(!h.find(34));
    assert(h.find(68));


}

void TestHashMap::testFind() {

    HashMap<int> h(15);

    h.insert(10);
    h.insert(15);
    h.insert(30);
    h.insert(45);

    assert( h.find(10) );
    assert( h.find(15) );
    assert( h.find(30) );
    assert( h.find(45) );

    assert( !h.find(25) );

    h.insert(25);
    assert( h.find(25) );

}
