// Preprocessor directives required for the Admin.h file
#ifndef Admin_hpp
#define Admin_hpp
#include <string>
#include "LinkedList.h"
#include "Inventory.h"
#include <stdio.h>
using namespace std;

// Creates class admin
class Admin
{
private:                // Private member variables
    string USERNAME;
    string PASSWORD;
public:
    
    // Checks for valid username and password
    void validateUserPass(string User, string Pass);
    
    // NEWPRODUCT Function -- Creates a new node at the end of the linked list
    void newProduct(class LinkedList *readList);
    
    // LENGTH Function -- Goes through and counts the length of the list
    int length(class LinkedList *readList);
    
    // DELETEPRODUCT Function -- Deletes a node in the inventoryFile
    void deleteProduct(class LinkedList *readList, int position);
    
    // UPDATEQuantity Function -- updates the quantity for an itemNumber
    void updateQuantity(class LinkedList *readList, class LinkedList *shoppingCart, int newQuantity, int itemNumber);
    
    // UPDATECost Function -- updates the cost for an itemNumber
    void updateCost(class LinkedList *readList, class LinkedList *shoppingCart, int newCost, int itemNumber);
    
    
    
};
#endif
