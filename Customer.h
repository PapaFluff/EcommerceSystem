// Preprocessor directives required for the Customer.h file
#ifndef Customer_h
#define Customer_h
#include <string>
#include "LinkedList.h"
#include "Inventory.h"
using namespace std;

//
class Customer
{
private:        // Private member variables
    string First;
    string Last;
    string Address;
    string City;
    string State;
    int zipCode;
    string invoiceFile;
public:                 // Public member variables/functions

    Customer *next; // Used to traverse the linked list
    
    // Default constructor
    Customer();
    
    // Overloaded constructor
    Customer(string first, string last, string address, string city, string state, int zip, string invoice);
    
    // Prints out the cart
    void printCart(class LinkedList *shoppingCart);
    
    // Searches for valid input
    Inventory *searchItem(class LinkedList *shoppingCart, int targetItemNumber);
    
    string getFirst();  // Gets the first name
    string getLast();   // gets the last name
    string getAddress();    // Gets the address
    string getCity();   // Gets city
    string getState();  // Gets state
    int getZipCode();   // Gets zip code
    string getInvoiceFile();    // Gets invoice file
    
    void setFirst(string F);    // sets the first name
    void setLast(string L); // sets the last name
    void setAddress(string A);  // sets the address
    void setCity(string c); // sets the city
    void setState(string s);    // sets the state
    void setZipCode(int z); // set zip code
    void setInvoiceFile(string invoice);    // sets invoice file
    
};

#endif
