// Preprocessor directives required for the LinkedList.cpp file
#include "LinkedList.h"

// Creates a default constructor for the linked list
LinkedList::LinkedList()
{
    headPtr = nullptr;      // Initialize the headPtr pointer to null
}

// Creates overloaded constructor that passes in a node that becomes new head
LinkedList::LinkedList(Inventory *beginning)
{
    headPtr = beginning;    // Sets node called beginning to the pointer(headPtr)
}

LinkedList::~LinkedList()
{
    
}

// Creates an overloaded operator member function that adds a node to the end of list using the += operator
void LinkedList::operator+=(Inventory * const newNode)
{
    // Checks to see if its an empty list
    if (headPtr == nullptr)
    {
        headPtr = newNode;  // Assigns the new node to the headPtr
    }
    else    // When the list is not an empty list it adds a new node to the end of the list
    {
        Inventory *current = headPtr;   // Declares a pointer of type Inventory which becomes the new head
        
        // Loop that continues as long as the next node is not null
        while(current->next != nullptr)
        {
            current = current->next;    // Sets current pointer to the next node
        }
        current->next = newNode;    // Assigns the current pointer to the new node
    }
        
}

// A function that gets the head ptr
Inventory* LinkedList::getHead() const
{
    return headPtr; // Returns the headPtr
}

// A function that sets the head ptr for the delete product function
Inventory* LinkedList::setHead(Inventory * newNode)
{
    return headPtr = newNode;   // Sets new node to headPtr
}
