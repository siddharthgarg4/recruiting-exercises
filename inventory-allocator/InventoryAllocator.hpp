//
//  InventoryAllocator.hpp
//  DeliverrExercise
//
//  Created by Siddharth Garg on 2020-08-28.
//  Copyright © 2020 Siddharth Garg. All rights reserved.
//

#ifndef InventoryAllocator_hpp
#define InventoryAllocator_hpp
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_map>

//items - name : quantity
typedef std::unordered_map<std::string, int> Items;
//warehouse - name : {items - name : quantity}
typedef std::pair<std::string, Items> Warehouse;

class InventoryAllocator {
    public:
        //stores the information (in the starting the warehouse input is in a map of string to any
        InventoryAllocator(Items, std::vector<Warehouse>);
        //returns the cheapest way of obtaining current order from the list of warehouses
        std::vector<Warehouse> giveCheapestAllocation();
        //output the warehouse or cheapest allocation as a string
        static std::string stringifyWarehouseAllocation(const std::vector<Warehouse> &warehouses);
    private:
        Items currentOrder = Items();
        std::vector<Warehouse> warehouses = std::vector<Warehouse>();
        //returns if an order is empty - that is all the quantity is 0
        bool isOrderEmpty(Items &);
};

#endif
