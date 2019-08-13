// Preprocessor directives required for the Customer.cpp file
#include "Customer.h"
#include <iostream>
#include <iomanip>
using namespace std;

Customer::Customer()
{
    
}

Customer::Customer(string first, string last, string address, string city, string state, int zip, string invoice)
{
    First = first;  // sets parameter to private variable
    Last = last;  // sets parameter to private variable
    Address = address;  // sets parameter to private variable
    City = city;  // sets parameter to private variable
    State = state;  // sets parameter to private variable
    zipCode = zip;;  // sets parameter to private variable
    invoiceFile = invoice;  // sets parameter to private variable
}

// PRINTCART -- Goes through and prints the current items in the cart
void Customer::printCart(LinkedList *shoppingCart)
{
    Inventory *current = shoppingCart->getHead();
    
    // While loop that goes through and prints the itemNumber, itemName, itemCost, and quantity
    while (current != NULL)
    {
        cout << current->getItemNumber() << "\t";    // Outputs the itemNumber
        cout << current->getItemName() << "\t";    // Outputs the itemName
        cout << "$" << fixed << setprecision(2) << current->getItemCost() << "\t";    // Outputs the itemCost
        cout << current->getQuantity() << endl;     // Outputs the quantity
         
        current = current->next;    // Traverses to the next node
    }
    
}

// SEARCHITEM -- Goes through searching to see if the user input matches with values within the file
Inventory * Customer::searchItem(LinkedList *shoppingCart, int targetItemNumber)
{
    Inventory *lastofCart = shoppingCart->getHead();
    // While loop that goes through and prints the itemNumber, itemName, itemCost, and quantity
    while (lastofCart != NULL)
    {
        // IF statement, that displays item number, name, and quantity upon the item input being valid
        if (lastofCart->getItemNumber() == targetItemNumber)
        {
            cout << lastofCart->getItemNumber() << "\t";     // Outputs the itemNumber
            cout << lastofCart->getItemName() << "\t";   // Outputs the itemName
            cout << "$" << fixed << setprecision(2) << lastofCart->getItemCost() << "\t";    // Outputs the itemCost
            cout << lastofCart->getQuantity() << endl;   // Outputs the quantity
            
            return lastofCart;  // Returns the item  if found
        }
        
        lastofCart = lastofCart->next;  // Traverses to the next node
    }
    
    return lastofCart;  // If not found returns lastofCart
}

// Gets the first name
string Customer::getFirst()
{
    return First;
}

// Gets the last name
string Customer::getLast()
{
    return Last;
}

// gets the address
string Customer::getAddress()
{
    return Address;
}

// gets the city
string Customer::getCity()
{
    return City;
}

// gets state
string Customer::getState()
{
    return State;
}

// gets zip code
int Customer::getZipCode()
{
    return zipCode;
}

// gets invoice
string Customer::getInvoiceFile()
{
    return invoiceFile;
}

// set first name
void Customer::setFirst(string F)
{
    First= F;
}

// set last name
void Customer::setLast(string L)
{
    Last = L;
}

// set address
void Customer::setAddress(string A)
{
    Address = A;
}

// set city
void Customer::setCity(string c)
{
    City = c;
}

// set state
void Customer::setState(string s)
{
    State = s;
}

// set zip code
void Customer::setZipCode(int z)
{
    zipCode = z;
}


// set invoice
void Customer::setInvoiceFile(string invoice)
{
    invoiceFile = invoice;
}
