// Preprocessor directives required for the Inventory.cpp file
#include "Inventory.h"
#include <string>
using namespace std;

// Creates a default constructor for the inventory class that sets the inventory pointer to null
Inventory::Inventory()
{
    next = nullptr;
}

Inventory::Inventory(int Number, string Name, double Cost, int quanti)
{
    itemNumber = Number;
    itemName = Name;
    itemCost = Cost;
    quantity = quanti;
    
}

// Declares a deconstructor function for the inventory class
Inventory::~Inventory()
{
    
}

// Creates a member function used to retrieve the itemNumber
int Inventory::getItemNumber() const
{
    return itemNumber;
}

// Creates a member function used to retrieve the itemName
string Inventory::getItemName() const
{
    return itemName;
}

// Creates a member function used to retrieve the itemCost
double Inventory::getItemCost() const
{
    return itemCost;
}

// Creates a member function used to retrieve the quantity
int Inventory::getQuantity() const
{
    return quantity;
}

// Declares a member function used to set the itemNumber
void Inventory::setItemNumber(int number)
{
    itemNumber = number;
}

// Declares a member function used to set the itemName
void Inventory::setItemName(string name)
{
    itemName = name;
}

// Declares a member function used to set the itemCost
void Inventory::setItemCost(double cost)
{
    itemCost = cost;
}

// Declares a member function used to set the quantity
void Inventory::setQuantity(int quantit)
{
    quantity = quantit;
}
