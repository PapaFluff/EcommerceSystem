// Preprocessor directives required for the Admin.cpp file
#include "Admin.h"
#include <iostream>
using namespace std;

// Checks for valid username and password
void Admin::validateUserPass(string User, string Pass)
{
    USERNAME = User;        // Sets user to private member variable
    PASSWORD = Pass;        // Sets pass to private member variable
    
    // If/else while used for error checking
    if ((User == "admin" && Pass == "admin") || (User == "ADMIN" && Pass == "ADMIN"))
    {
        cout << "Welcome ADMIN!" << endl;
    }
    else while (User != "admin" || Pass != "admin" || User != "ADMIN" || Pass != "ADMIN")   // Invalid
    {
        cout << "The username or password you entered is invalid! Try again!" << endl;
        
        cout << "Username: ";
        cin >> User;
        
        cout << "Password: ";
        cin >> Pass;
        
        if ((User == "admin" && Pass == "admin") || (User == "ADMIN" && Pass == "ADMIN")) // if valid
        {
            cout << "Welcome ADMIN!" << endl;
            break;
        }
    }
}

// NEWPRODUCT Function -- Creates a new node at the end of the linked list
void Admin::newProduct(class LinkedList *readList)
{
    int Number;
    int Name;
    double Cost;
    int Quantity;
    
    Inventory *head = readList->getHead();;     // Create a temporary node to keep track of the orginal head node
    Inventory *current = NULL;                                   // Create a temporary node to use to transverse through the linked list
    Inventory* newNode = new Inventory();                   // Create a new node to add to the end of the list
    
    cout << "Item NUMBER for the new product: ";    // Prompts user for item number
    cin >> Number;
    
    cout << "Item NAME for the new product: ";    // Prompts user for item name
    cin >> Name;
    
    cout << "Item COST for the new product: $";    // Prompts user for item cost
    cin >> Cost;
    
    cout << "Item QUANTITY for the new product: ";    // Prompts user for quantity
    cin >> Quantity;
    
    newNode->setItemNumber(Number);                            // Set the Node Data
    string NameAsString = to_string(Name);                         // Change to string
    newNode->setItemName(NameAsString);                             // Set the Node Data
    newNode->setItemCost(Cost);                            // Set the Node Data
    newNode->setQuantity(Quantity);                           // Set the Node Data
    newNode->next = NULL;
    
    if (!head) {                                    // Check to see if linked list is empty
        head = newNode;                                // If it is append the new node onto the empty list
    }
    else
    {
        current = head;                                // Set the current node to the head node
        
        while (current->next)                           // Traverse the linked list until you reach the end
        {
            current = current->next;
        }
        current->next = newNode;                    // At the end set the current to point to the new node.
    }
    
    readList->getHead();            // Return the new linked list to the calling function
    cout << endl;
}

// LENGTH Function -- Goes through and counts the length of the list
int Admin::length(class LinkedList *readList)
{
    Inventory *current = readList->getHead();  // Create a temporary node to keep track of the current node
    int count = 0;
    
    while (current != NULL) {      // Loop through the list until we find the end
        count++;
        current = current->next;
    }
    return count;
}

// DELETEPRODUCT Function -- Deletes a node in the inventoryFile
void Admin::deleteProduct(class LinkedList *readList, int position)
{
    int itemNumber; // Declares int for itemNumber
    cout << "Which node do you want to delete?" << endl;    // Prompts user
    cout << "Give an item number: ";    // Prompts user
    cin >> itemNumber;
    
    int count = 0;  // Count is used for length
    Inventory *current = readList->getHead();    // Creates a temporary node to traverse through the list
    Inventory *prev = readList->getHead();   // Creates a temporary node to go back in the list
    
    // For invalid positions
    if ((position < 0 || position > length(readList)) && itemNumber != current->getItemNumber())
    {
        cout << "Invalid index!" << endl;
        return;
    }
    else if (position == 0)     // If position is at 0
    {
        current = current->next;
        delete prev;
        readList->setHead(current);
        return;
    }
    else if (position == length(readList) - 1 && itemNumber == current->getItemNumber())     // If itemNumber is found within the list
    {
        while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        delete current;
        return;
    }
    else        // Deletes node otherwise
    {
        while (current != NULL)
        {
            if (count == position)
            {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
            count++;
        }
    }
    
    cout << endl;   // Creates a new line
}

// UPDATEQuantity Function -- updates the quantity for an itemNumber
void Admin::updateQuantity(class LinkedList *readList, class LinkedList *shoppingCart, int newQuantity, int itemNumber)
{
    Inventory *current = readList->getHead();    // Creates a temporary node that traverses the linked list
    
    cout << "Which product quantity would you like to update?" << endl;     // Prompts user
    cout << "Type a product here: ";    // Prompts user
    cin >> itemNumber;  // Takes in input
    
    // While loop that traverses checking if valid input was found
    while (current != NULL)
    {
        // If the input is valid
        if (itemNumber == current->getItemNumber())
        {
            cout << "The new quantity: ";   // Prompts user for new quantity
            cin >> newQuantity;     // Takes input
            
            current->setQuantity(newQuantity);    // Stores new quantity
        }
        
        current = current->next;    // Goes to the next node
    }
    cout << endl;   // Creates newline
}

// UPDATECost Function -- updates the cost for an itemNumber
void Admin::updateCost(class LinkedList *readList, class LinkedList *shoppingCart, int newCost, int itemNumber)
{
    Inventory *current = readList->getHead();    // Creates a temporary node that traverses the linked list
    
    cout << "Which product quantity would you like to update?" << endl;     // Prompts user
    cout << "Type a product here: ";    // Prompts user
    cin >> itemNumber;  // Takes in input
    
    // While loop that traverses checking if valid input was found
    while (current != NULL)
    {
        // If the input is valid
        if (itemNumber == current->getItemNumber())
        {
            cout << "The new quantity: ";   // Prompts user for new quantity
            cin >> newCost;     // Takes input
            
            current->setItemCost(newCost);    // Stores new quantity
        }
        
        current = current->next;    // Goes to the next node
    }
    cout << endl;   // Creates newline
}
