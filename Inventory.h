// Preprocessor directives required for the Inventory.h file
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
using namespace std;

// Creates class inventory
class Inventory
{
private:        // Private member variables
    int itemNumber;
    string itemName;
    double itemCost;
    int quantity;
public:                 // Public member variables/functions
    
    Inventory *next;        // Creates a pointer of type inventory to traverse
    
    // Creates a default constructor for the inventory class
    Inventory();
    
    // Creates a overloaded constructor for the inventory class
    Inventory(int itemNumber, string itemName, double itemCost, int quantity);
    
    // Declares a deconstructor function for the inventory class
    ~Inventory();
    
    // Declares a member function used to retrieve the itemNumber
    int getItemNumber() const;
    
    // Declares a member function used to retrieve the itemName
    string getItemName() const;
    
    // Declares a member function used to retrieve the itemCost
    double getItemCost() const;
    
    // Declares a member function used to retrieve the quantity
    int getQuantity() const;
    
    // Declares a member function used to set the itemNumber
    void setItemNumber(int number);
    
    // Declares a member function used to set the itemName
    void setItemName(string name);
    
    // Declares a member function used to set the itemCost
    void setItemCost(double cost);
    
    // Declares a member function used to set the quantity
    void setQuantity(int quantit);
    
};
#endif
