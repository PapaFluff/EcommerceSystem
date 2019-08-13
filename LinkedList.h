// Preprocessor directives required for the LinkedList.h file
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Inventory.h"
#include "Customer.h"

// Creates a class called LinkedList for the LinkedList.h file
class LinkedList
{
public:                 // Public member variables/functions
    Inventory *headPtr;     // Creates a head(inventory pointer)
    
    // Creates a default constructor for the linked list
    LinkedList();
    
    // Creates overloaded constructor that passes in a node
    LinkedList(Inventory *beginning);
    
    // Declares a deconstructor function for the inventory class
    ~LinkedList();
    
    // Declares a overloaded operator that adds a node to the end of list using the += operator
    void operator+=(Inventory * const newNode);
    
    // A function that gets the head ptr
    Inventory* getHead() const;
    
    // A function that sets the head ptr for the delete product function
    Inventory* setHead(Inventory * newNode);
};
#endif
