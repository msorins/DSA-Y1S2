//
// Created by Sorin Sebastian Mircea on 21/05/2017.
//


#include "../HashMap/HashMap.h"

class TestHashMap {
private:
    HashMap<int> *container;

public:
    //Functionality
    TestHashMap();
    void initialiseContainer(int size);
    void startTests();
    void testInsert();
    void testRemove();
    void testFind();
};

