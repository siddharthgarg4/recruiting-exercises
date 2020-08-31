# recruiting-exercises

## Deliverr Challenge Inventory Allocator - Siddharth Garg
Completed the Inventory Allocator challenge using C++

## Compiling and Running
```sh
cd recruiting-exercises/inventory-allocator
g++ -std=c++14 -Wall main.cpp InventoryAllocator.cpp UnitTests.cpp -o InventoryAllocator ; ./InventoryAllocator
```

moves to the inventory allocator folder to where the files are stored, compiling the files into an exe and then running the exe to run the tests. 

## Description

- main.cpp (runs the test cases)
- InventoryAllocator.hpp[.cpp] (actual class that finds the minimal cost allocation from warehouses)
- UnitTests.hpp[.cpp] (contains all the test cases for the inventory allocator including edge cases)
