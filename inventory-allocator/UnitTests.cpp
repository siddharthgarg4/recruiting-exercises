//
//  UnitTests.cpp
//  DeliverrExercise
//
//  Created by Siddharth Garg on 2020-08-30.
//  Copyright © 2020 Siddharth Garg. All rights reserved.
//

#include "UnitTests.hpp"

/*
 A test case is {order, warehouses, expectOutput}
 */

InventoryAllocatorUnitTest::InventoryAllocatorUnitTest() {
    
    //warehouses are empty
    Test testCase1 = {
        {{"apple", 1}},
        {{"owd", {{ "apple", 0 }}}},
        "[]"
    };
    
    //no warehouses
    Test testCase2 = {
        {{"apple", 1}},
        {},
        "[]"
    };
    
    //no order
    Test testCase3 = {
        {},
        {{"owd", {{ "apple", 5 },{ "pear", 5 }}}},
        "[]"
    };
    
    //perfect match
    Test testCase4 = {
        {{"apple", 1}},
        {{"owd", {{ "apple", 1 }}}},
        "[{ owd: { apple: 1 } }]"
    };
    
    //perfect match - multiple items
    Test testCase5 = {
        {{ "apple", 5 }, { "pear", 5 }},
        {{"san", {{ "apple", 5 }, { "pear", 5 }}}},
        "[{ san: { apple: 5, pear: 5 } }]"
    };
    
    //warehouse can complete order
    Test testCase6 = {
        {{ "apple", 4 }, { "pear", 1 }},
        {{"san", {{ "apple", 5 }, { "pear", 5 }}}},
        "[{ san: { apple: 4, pear: 1 } }]"
    };
    
    //warehouse cannot complete order
    Test testCase7 = {
        {{ "apple", 5 }, { "pear", 5 }},
        {{"san", {{ "apple", 5 }, { "pear", 4 }}}},
        "[]"
    };
    
    //multiple warehouses
    Test testCase8 = {
        {{ "apple", 10 }},
        {{ "owd", {{ "apple",  5 }} }, {"dm", {{ "apple", 5 }}}},
        "[{ owd: { apple: 5 } }{ dm: { apple: 5 } }]"
    };
    
    //both order and warehouse are 0
    Test testCase9 = {
        {{"apple", 0}},
        {{"owd", {{ "apple", 0 }}}},
        "[]"
    };
    
    //order is 0
    Test testCase10 = {
        {{"apple", 0}},
        {{"owd", {{ "apple", 10 }}}},
        "[]"
    };
    
    testCases = {
        testCase1,
        testCase2,
        testCase3,
        testCase4,
        testCase5,
        testCase6,
        testCase7,
        testCase8,
        testCase9,
        testCase10
    };
}

void InventoryAllocatorUnitTest::runAllTests() {
    for (int i=0; i<numTests; i++) {
        std::cout << "Test " << i+1 << ": ";
        Test currentTest = testCases[i];
        //creating the inventory allocator
        InventoryAllocator allocator = InventoryAllocator(currentTest.order, currentTest.warehouses);
        //checking if the output matches the expected output
        std::cout << (allocator.stringifyWarehouseAllocation(allocator.giveCheapestAllocation()) == currentTest.output ?  " success" : " failure") << std::endl;
        std::cout << "expected output: " << currentTest.output << std::endl;
        std::cout << std::endl;
    }
}
