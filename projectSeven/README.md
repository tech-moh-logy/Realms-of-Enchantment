# Mohammed's Project 7 - Algorithmic Adventures: Into the Recursive Realms (Inheritance)

### Project 7 - Trinkets and Baubles: The Inventory

## Project Overview

This project involves implementing the Inventory class as a subclass of BinarySearchTree. The Inventory class stores POINTERS to Items, and Items consist of a name, type, level, gold value, quantity, and time-picked-up. Items of type UNKNOWN, WEAPON, and ARMOR have a quantity of 1, while CONSUMABLE items can have multiple units stacked. The Inventory class includes various member functions for managing items, such as adding, removing, finding, and printing.

## Task 1: Implement the Inventory class as a subclass of BinarySearchTree

### Additional Methods

#### `addItem(itemPtr)`
- **Parameters:** A Pointer to the Item object to be added to the inventory.
- **Post-Condition:** The Item is added to the inventory, preserving the BST structure. The BST property is based on ascending alphabetical order of the item's name. If the item is type UNKNOWN, WEAPON, or ARMOR and is already in the inventory, it is not added. If another instance of a CONSUMABLE item is added (an item with the same name), its quantity is updated, and the time_picked_up_ variable is updated to the latest instance.
- **Return:** True if the item was added to the inventory or updated, false otherwise.

#### `removeItem(name)`
- **Parameters:** A reference to the string name of the item to be removed from the inventory.
- **Return:** True if the item was found and removed or updated successfully, false otherwise.
- **Post-Condition:** If the item is found in the inventory, it is removed while preserving the BST structure. If a CONSUMABLE is removed, its quantity is decremented by one, but its time_picked_up_ remains the same. If it is the last item (quantity is 1 and being removed), the item should be removed. Non-CONSUMABLE items are always removed when found.

#### `findItem(name)`
- **Parameters:** A reference to the string name of the item to be found.
- **Return:** An Item pointer to the found item, or nullptr if the item is not in the inventory.

#### `getTotalGoldValue()`
- **Return:** The total sum of gold values of all items in the inventory. Note: consumable items may have quantity >1, and gold value must be added for each item.

#### `printInventoryInOrder()`
- **Post-Condition:** The names of all items in the Inventory are printed in ascending order. This function performs an in-order traversal of the binary search tree and prints the details of each item.

    Example:
    ```
    TIRED GAUNTLETS (ARMOR)
    Level: 3
    Value: 25

    SMALL HEALTH POTION (CONSUMABLE)
    Level: 1
    Value: 10
    Quantity: 2
    ```

#### `printInventory(ascending, attribute)`
- **Parameters:**
  - A reference to bool if the items are to be printed in ascending order.
  - A reference to string attribute which defines the order by which the items are to be printed (["NAME"/"TYPE"/"LEVEL"/"VALUE"/"TIME"]).
- **Post-Condition:** All items in the Inventory are printed in the order specified by the parameter.

    Example usage: `inventory.printInventory(false, "LEVEL")`

    ```
    FEATHER DUSTER (WEAPON)
    Level: 5
    Value: 100

    TIRED GAUNTLETS (ARMOR)
    Level: 3
    Value: 50

    SMALL HEALTH POTION (CONSUMABLE)
    Level: 1
    Value: 10
    Quantity: 2

    NOODLES (CONSUMABLE)
    Level: 0
    Value: 120
    Quantity: 5
    ```

## Testing

### How to compile with your Makefile:
In the terminal, in the same directory as your Makefile and your source files, use the following command:

```bash
make rebuild
