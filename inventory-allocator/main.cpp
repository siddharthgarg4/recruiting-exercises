//
//  main.cpp
//  DeliverrExercise
//
//  Created by Siddharth Garg on 2020-08-28.
//  Copyright © 2020 Siddharth Garg. All rights reserved.
//

#include <iostream>
#include "UnitTests.hpp"

int main(int argc, const char * argv[]) {
    //running tests
    InventoryAllocatorUnitTest cheapestAllocationTests = InventoryAllocatorUnitTest();
    cheapestAllocationTests.runAllTests();
}
