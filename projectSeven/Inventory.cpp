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

#include "Inventory.hpp"

// Constructor
Inventory::Inventory() : BinarySearchTree<Item*>() {
    // Initialize empty inventory
}

// Destructor
// Inventory::~Inventory() {
//     // Free all allocated memory for items
//     while (!isEmpty()) {
//         remove(root->data->getName());
//     }
// }

// Adds an item to the inventory
bool Inventory::addItem(Item* item) {
    if (item == nullptr) {
        return false;
    }

    // Check if item already exists
    Item* existingItem = findItem(item->getName());
    if (existingItem != nullptr) {
        // If item is not consumable, return false
        if (item->getType() != "CONSUMABLE") {
            return false;
        }

        // Update quantity and time for consumable item
        existingItem->setQuantity(existingItem->getQuantity() + item->getQuantity());
        existingItem->setTimePickedUp(item->getTimePickedUp());
        return true;
    }

    // Add new item to the BST
    return add(item);
}

// Removes an item from the inventory
bool Inventory::removeItem(const std::string& itemName) {
    Item* item = findItem(itemName);
    if (item == nullptr) {
        return false;
    }

    // Decrement quantity for consumable item
    if (item->getType() == "CONSUMABLE" && item->getQuantity() > 1) {
        item->setQuantity(item->getQuantity() - 1);
        return true;
    }

    // Remove item from the BST
    return BinarySearchTree<Item*>::remove(item);
}

// Finds an item in the inventory -- should work
Item* Inventory::findItem(const std::string& itemName) const {
    Item* j = new Item(itemName);
    std::shared_ptr<BinaryNode<Item*>> storage = getPointerTo(j);
    if(storage == nullptr) {
        return nullptr;
    }
    return storage->getItem();
}

// Gets the total gold value of all items -- work
int Inventory::getTotalGoldValue(){
    int totalGold = 0;
    if (getRoot() == nullptr) {
        return 0;
    } else {
        traverseGold(totalGold, getRoot());
    }
        // totalGold += item->getGoldValue();

    return totalGold;
}


void Inventory::traverseGold(int& totalGold, std::shared_ptr<BinaryNode<Item*>> node) {
    if(node == nullptr) {
        return;
    }
    Item* item = node->getItem();
    totalGold += item->getGoldValue() * item->getQuantity();
    traverseGold(totalGold, node->getLeftChildPtr());
    traverseGold(totalGold, node->getRightChildPtr());
}


// Prints the inventory in ascending order
void Inventory::printInventoryInOrder() const {

    // void Inventory::printInventoryHelper(std::shared_ptr<BinaryNode<Item*>> node) const 
    printInventoryHelper(getRoot());


}

// Prints the inventory based on specified parameters
void Inventory::printInventory(const bool& ascending, const std::string& attribute) {

    std::vector<Item*> tom; // tom represents all items in inventory
    printFillVector(tom, getRoot());
    
    if (attribute == "NAME") {
       if (ascending == true) {
        std::sort(tom.begin(), tom.end(),
        [](Item* x, Item* y) 
            {
                return x->getName() < y->getName();
            } 
        );
       }
        else {
            std::sort(tom.begin(), tom.end(),
            [](Item* x, Item* y) 
            {
                return x->getName() > y->getName();
            } 
        );
        }
    }

    if (attribute == "TYPE") {
       if (ascending == true) {
        std::sort(tom.begin(), tom.end(),
        [](Item* x, Item* y) 
            {
                return x->getType() < y->getType();
            } 
        );
       }
        else {
            std::sort(tom.begin(), tom.end(),
            [](Item* x, Item* y) 
            {
                return x->getType() > y->getType();
            } 
        );
        }
    }

    if (attribute == "LEVEL") {
       if (ascending == true) {
        std::sort(tom.begin(), tom.end(),
        [](Item* x, Item* y) 
            {
                return x->getLevel() < y->getLevel();
            } 
        );
       }
        else {
            std::sort(tom.begin(), tom.end(),
            [](Item* x, Item* y) 
            {
                return x->getLevel() > y->getLevel();
            } 
        );
        }
    }

    if (attribute == "VALUE") {
       if (ascending == true) {
        std::sort(tom.begin(), tom.end(),
        [](Item* x, Item* y) 
            {
                return x->getGoldValue() < y->getGoldValue();
            } 
        );
       }
        else {
            std::sort(tom.begin(), tom.end(),
            [](Item* x, Item* y) 
            {
                return x->getGoldValue() > y->getGoldValue();
            } 
        );
        }
    }

    if (attribute == "TIME") {
       if (ascending == true) {
        std::sort(tom.begin(), tom.end(),
        [](Item* x, Item* y) 
            {
                return x->getTimePickedUp() < y->getTimePickedUp();
            } 
        );
       }
        else {
            std::sort(tom.begin(), tom.end(),
            [](Item* x, Item* y) 
            {
                return x->getTimePickedUp() > y->getTimePickedUp();
            } 
        );
        }
    }

    for (int i = 0; i < tom.size(); i++) {
        std::cout << tom[i]->getName() << " (" << tom[i]->getType() << ")" << std::endl;
        std::cout << "Level: " << tom[i]->getLevel() << std::endl;
        std::cout << "Value: " << tom[i]->getGoldValue() << std::endl;

        if (tom[i]->getType() == "CONSUMABLE") {
            std::cout << "Quantity: " << tom[i]->getQuantity() << std::endl;
        }
        std::cout << std::endl;

    }
    // printInventoryHelper(getRoot(), ascending, attribute);
    
}
//visit every node in the inventory and push back every node's item to the vector
void Inventory::printFillVector(std::vector<Item*>& tom, std::shared_ptr<BinaryNode<Item*>> node) {
    if(node == nullptr) {
        return;
    }
    Item* item = node->getItem();
    tom.push_back(item);
    printFillVector(tom, node->getLeftChildPtr());
    printFillVector(tom, node->getRightChildPtr());
}

// Helper function for printing the inventory
void Inventory::printInventoryHelper(std::shared_ptr<BinaryNode<Item*>> node) const {


    if (node == nullptr) {
        return;
    }

    // Traverse left subtree
    printInventoryHelper(node.get()->getLeftChildPtr());

    // Print current item
    Item* item = node->getItem();
    std::cout << item->getName() << " (" << item->getType() << ")" << std::endl;
    std::cout << "Level: " << item->getLevel() << std::endl;
    std::cout << "Value: " << item->getGoldValue() << std::endl;
    if (item->getType() == "CONSUMABLE") {
        std::cout << "Quantity: " << item->getQuantity() << std::endl;
    }
    std::cout << std::endl;

    // Traverse right subtree
    printInventoryHelper(node.get()->getRightChildPtr());
}







// // Compares two items for print order
// int Inventory::compareItems(const Item* item1, const Item* item2, const std::string& attribute) const {
//     // Compare items based on specified attribute
//     if (attribute == "NAME") {
//         return item1->getName().compare(item2->getName());
//     } else if (attribute == "TYPE") {
//         return item1->getType().compare(item2->getType());
//     } else if (attribute == "LEVEL") {
//         return item1->getLevel() - item2->getLevel();
//     } else if (attribute == "VALUE") {
//         return item1->getGoldValue() - item2->getGoldValue();
//     } else if (attribute == "TIME") {
//         return item1->getTimePickedUp() - item2->getTimePickedUp();
//     } else {
//         // Invalid attribute provided
//         std::cerr << "Error: Invalid attribute provided for inventory printing." << std::endl;
//         return 0;
//     }
// }