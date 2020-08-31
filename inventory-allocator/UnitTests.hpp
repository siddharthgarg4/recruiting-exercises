//
//  UnitTests.hpp
//  DeliverrExercise
//
//  Created by Siddharth Garg on 2020-08-30.
//  Copyright © 2020 Siddharth Garg. All rights reserved.
//

#ifndef UnitTests_hpp
#define UnitTests_hpp
#include <iostream>
#include <array>
#include "InventoryAllocator.hpp"

struct Test {
    Items order;
    std::vector<Warehouse> warehouses;
    std::string output;
};

class InventoryAllocatorUnitTest {
    public:
        InventoryAllocatorUnitTest();
        void runAllTests();
    private:
        static const int numTests = 10;
        std::array<Test, numTests> testCases;
};

#endif
