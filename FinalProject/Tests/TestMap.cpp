//
// Created by Sorin Sebastian Mircea on 22/05/2017.
//

#include <cassert>
#include "TestMap.h"
#include "../Map/Map.h"
#include "../Exception/Exception.h"

TestMap::TestMap() {
    this->startTests();
}

void TestMap::startTests() {
    this->testAdd();
    this->testErase();
    this->testSearch();
}


void TestMap::testAdd() {
    Map<int, int> mp(37);

    mp.add(1, 10);
    assert(mp.size() == 1 && mp.find(1));
    mp.add(2, 10);
    assert(mp.size() == 2 && mp.find(2));
    mp.add(3, 10);
    assert(mp.size() == 3 && mp.find(3));
    mp.add(4, 10);
    assert(mp.size() == 4 && mp.find(4));

    try{
        mp.add(1, 25);
        assert(false);

    }catch(Exception ex) {
        assert(true);
    }

    try{
        mp.add(2, 73);
        assert(false);

    }catch(Exception ex) {
        assert(true);
    }

}

void TestMap::testErase() {
    Map<int, int> mp(119);

    mp.add(1, 10);
    assert(mp.size() == 1 && mp.find(1));

    mp.add(103, 999);
    assert(mp.size() == 2 && mp.find(103));

    mp.add(118, 23);
    assert(mp.size() == 3 && mp.find(118));

    assert(mp.erase(103));
    assert(mp.size() == 2 && !mp.find(103));


    mp.add(596, 74);
    assert(mp.size() == 3 && mp.find(596));

    mp.add(120, 63);
    assert(mp.size() == 4 && mp.find(120));

    mp.add(358, 63);
    assert(mp.size() == 5 && mp.find(358));

    assert( mp.erase(120) );
    assert(mp.size() == 4 && !mp.find(120) && mp.find(358) && mp.find(596));

    assert(mp.erase(358));
    assert(mp.size() == 3 && !mp.find(120) && !mp.find(358) && mp.find(596));

    assert(mp.erase(596));
    assert(mp.size() == 2 && !mp.find(120) && !mp.find(358) && !mp.find(596));

    mp.add(596, 101);
    assert(mp.erase(596));


    try {
        assert(!mp.erase(596));
    }catch(Exception ex) {
        assert(true);
    }

}

void TestMap::testSearch() {
    Map<int, int> mp(1113);

    int i;
    for(i = 1; i <= 1000; i++)
        mp.add(i, i*2);

    for(i = 1; i <= 1000; i++)
        assert(mp.find(i));

    for(i = 1; i <= 1000; i+=2)
        assert(mp.erase(i));

    for(i = 1; i <= 1000; i++)
       if(i % 2 == 0)
           assert(mp.find(i));
        else
           assert(!mp.find(i));

    for(i = 2; i <= 1000; i+=2)
        assert(mp.erase(i));

    for(i = 1; i <= 1000; i++)
        assert(!mp.find(i));
}

