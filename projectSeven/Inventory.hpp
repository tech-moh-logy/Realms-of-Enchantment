//////////////////////////////////////////////////////////////////////////////
// Project: Project 7 - Trinkets and Baubles: The Inventory
// Author:  Mohammed 
//
// Notes:
// Data Structures & Algorithm
//
// Copyright:
// © 2024 Mohammed. All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////
    //                        [Root]
    //                      /        |
    //            [LeftChild]    [RightChild]
    //            /           \          /           |
    //    [LeftChild1]  [RightChild1] [LeftChild2]  [RightChild2]

#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

// Assuming the Item class is defined somewhere else
#include "Item.hpp"
#include "BinaryNode.hpp"
#include "BinarySearchTree.hpp"

class Inventory : public BinarySearchTree<Item*> {
public:
    Inventory();
    // ~Inventory();

    bool addItem(Item* item);
    bool removeItem(const std::string& itemName);
    Item* findItem(const std::string& itemName) const;
    int getTotalGoldValue();
    void printInventoryInOrder() const;
    void printInventory(const bool& ascending, const std::string& attribute);

private:
    // Helper functions for printInventory
    void printInventoryHelper(std::shared_ptr<BinaryNode<Item*>> root) const;
    // int compareItems(const Item* item1, const Item* item2, const std::string& attribute) const;
    void printFillVector( std::vector<Item*>& tom, std::shared_ptr<BinaryNode<Item*>> node);
    void traverseGold(int& totalGold, std::shared_ptr<BinaryNode<Item*>> node);

};

#endif
