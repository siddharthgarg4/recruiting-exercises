//
//  InventoryAllocator.cpp
//  DeliverrExercise
//
//  Created by Siddharth Garg on 2020-08-28.
//  Copyright © 2020 Siddharth Garg. All rights reserved.
//

#include "InventoryAllocator.hpp"

InventoryAllocator::InventoryAllocator(Items currentOrder, std::vector<Warehouse> warehouses) : currentOrder(currentOrder), warehouses(warehouses) {}

std::vector<Warehouse> InventoryAllocator::giveCheapestAllocation() {
    std::vector<Warehouse> cheapestAllocation;
    Items itemsLeftInOrder = currentOrder;
    //looping through warehouses to find the order
    for (auto &warehouse : warehouses) {
        if (itemsLeftInOrder.empty()) {
            //the order has been fulfilled
            break;
        }
        Items currentWarehouseAllocationToOrder;
        //iterating over the items present in current warehouse
        for (auto &currentWarehouseItem : warehouse.second) {
            for (auto currentOrderItem=itemsLeftInOrder.begin(); currentOrderItem!=itemsLeftInOrder.end(); currentOrderItem++) {
                //if the number of items for that currentWarehouseItem is 0 or negative we continue to next currentWarehouseItem
                if (currentWarehouseItem.second <= 0 || currentOrderItem->second <= 0) { continue; }
                //checking if current currentWarehouseItem's name is same as order's current item's name
                if (currentWarehouseItem.first == currentOrderItem->first) {
                    int itemsAllocated = 0;
                    if (currentOrderItem->second <= currentWarehouseItem.second) {
                        itemsAllocated = currentOrderItem->second;
                    } else {
                        itemsAllocated = currentWarehouseItem.second;
                    }
                    currentOrderItem->second -= itemsAllocated;
                    if (itemsAllocated > 0) {
                        currentWarehouseAllocationToOrder[currentOrderItem->first] = itemsAllocated;
                    }
                }
            }
        }
        if (!currentWarehouseAllocationToOrder.empty()) {
            cheapestAllocation.emplace_back(warehouse.first, currentWarehouseAllocationToOrder);
        }
    }
    //if current order is not empty means it is not possible to allocate order and thus return empty allocation
    return isOrderEmpty(itemsLeftInOrder) ? cheapestAllocation : std::vector<Warehouse>();
}

bool InventoryAllocator::isOrderEmpty(Items &currentOrder) {
    //checks if the order is empty
    for (auto &item : currentOrder) {
        if (item.second > 0) {
            return false;
        }
    }
    return true;
}

std::string InventoryAllocator::stringifyWarehouseAllocation(const std::vector<Warehouse> &warehouses) {
    //creating the string for the warehouse allocation
    std::string output;
    output += "[";
    for (auto &warehouse : warehouses) {
        output += "{ ";
        output += warehouse.first;
        output += ": {";
        bool isFirstItem = true;
        for (auto &item : warehouse.second) {
            if (isFirstItem) {
                isFirstItem = false;
            } else {
                output +=  ",";
            }
            output +=  " ";
            output += item.first;
            output += ": ";
            output += std::to_string(item.second);
        }
        output += " } }";
    }
    output +=  "]";
    return output;
}
