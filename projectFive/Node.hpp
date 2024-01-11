///////////////////////////////////////////////////////////////////////////////
// Project: Project 5 - Quest Management with Doubly Linked Lists
// Author:  Mohammed 
//
// Notes:
// Data Structures & Algorithm
//
// Copyright:
// © 2024 Mohammed. All Rights Reserved.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef NODE_HPP_
#define NODE_HPP_

template<class ItemType>
class Node
{

public:
   Node(); //default constructor
   Node(const ItemType& an_item); // parameterized constructor
   Node(const ItemType& an_item, Node<ItemType>* next_node_ptr); // parameterized constructor
    
   /**@param an_item the data item */
   void setItem(const ItemType& an_item);
    
   /**@param next_node_ptr a pointer to the next node in the chain*/
   void setNext(Node<ItemType>* next_node_ptr);
    
   /**@param previous_node_ptr a pointer to the previous node in the chain*/
   void setPrevious(Node<ItemType>* previous_node_ptr);
    
   /**@return returns the data item*/
   ItemType getItem() const ;
    
   /**@return returns a pointer to the next node in the chain*/
   Node<ItemType>* getNext() const ;
    
   /**@return returns a pointer to the previous node in the chain*/
   Node<ItemType>* getPrevious() const ;
    
private:
    ItemType        item_; // A data item
    Node<ItemType>* next_; // Pointer to next node
    Node<ItemType>* previous_; // Pointer to next node
}; // end Node

#include "Node.cpp"
#endif