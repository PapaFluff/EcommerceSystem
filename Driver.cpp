// Preprocessor directives required for the Driver.cpp file
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Inventory.h"
#include "Admin.h"
#include "Customer.h"
#include <iomanip>
using namespace std;

int main()
{
    fstream productFile("ProductData.csv", ios::in);    // Declares fstream object for productFile and opens it in input
    
    // Tests if the file fails when being opened
    if (productFile.fail())
    {
        cout << "The file could not be opened. \n";    // ERROR message
        return 0;
    }
    
    LinkedList readList;    // Creates object for reading the file
    
    productFile.seekg(0L, ios::beg);                    // Sets read position to the beginning of the file
    
    while (productFile)
    {
        Inventory *tempNode = new Inventory();    // Creates a new temporary node
        int number; // Declares for itemNumber
        productFile >> number;    // Reads the first column of the row into number
        tempNode->setItemNumber(number);    // Sets into private variable
        productFile.seekg(9L, ios::cur);                  // Sets read position to 10th byte(byte 9th)
        
        int Name; // Declares for itemName
        productFile >> Name;   // Reads the second column of the row into name
        string NameAsString = to_string(Name);  // Changes to string
        tempNode->setItemName(NameAsString);    // Sets into private variable
        productFile.seekg(1L, ios::cur);    // Sets read position to 1st byte
        
        double Cost;    // Declares for itemCost
        productFile >> Cost;    // Reads the third column of the row into cost
        tempNode->setItemCost(Cost);    // Sets into private variable
        productFile.seekg(1L, ios::cur);             // Sets read position to 1st byte
        
        int Quantity; // Declares for quantity
        productFile >> Quantity;        // Reads the fourth column of the row into quantity
        tempNode->setQuantity(Quantity);   // Sets into private variable
        productFile.ignore(1, '\n');    // Ignores line
        
        readList += tempNode;   // Adds node using overloaded operator
        
    }
    
    LinkedList shoppingCart;    // Creates object for shoppingCart
    Admin ADMIN;    // Creates object for admin
    int adminOrUser = 3;    // Declares and initializes adminOrUser variable to 3
    
    // do while that does admin, user, or exits the program
    do {
        
        cout << "Hello welcome to Amazon-wannabe! Are you an admin or customer?" << endl;   // Prompts the user if they admin or user
        cout << "Type 1 for admin. Type 2 for customer. Type 3 to exit: ";  // Gives the user options
        cin >> adminOrUser; // Takes in input
        
        cout << endl;   ;   // Creates a new line
        // A switch statement that takes in adminOrUser and outputs and calls the functions if they have chosen admin or user
        
    switch (adminOrUser)
        {
        case 1: {
            cout << "Are you really admin?!" << endl;           // If the user types in 1 they are admin
            string USER;    // Declares for private variable
            string PASS;    // Declares for private variable
            
            // Prompts user
            cout << "Username: ";
            cin >> USER;    // Input here
            
            cout << "Password: ";   // Prompts user
            cin >> PASS;    // Input here
            
            ADMIN.validateUserPass(USER, PASS);
            
            int adminChoice = 0;    // Declares the variable that will take in the users input
            int newQuantity = 0;    // Declares newQuantity because of updateQuantity being called
            int newCost = 0;    // Declares newCost because of updateQuantity
            int itemNumber = 0;    // Declares itemNumber because of updateQuantity being called
            int position = 0;   // Declares position because of delete being called
            
            // Prompts user with menu
            cout << "Since your admin, you have 3 choices for the inventory file!" << endl;
            cout << "Type 1 to add a product" << endl;
            cout << "Type 2 to delete a product" << endl;
            cout << "Type 3 to update a quantity" << endl;
            cout << "Type 4 to update an item cost" << endl;
            cout << "Type anything else to go back" << endl;
            cin >> adminChoice; // Takes in the users choice as input
            
            // Switch statement that allows the user to add/delete a product, or update a quantity
            switch (adminChoice)
            {
                case 1: cout << "Adding a product..." << endl;  // If the user types 1, he/she wants to add a product
                    ADMIN.newProduct(&readList); // Calls newProduct function to add a product
                    break;  // Break statement
                case 2: cout << "Deleting a product..." << endl;    // If the user types 2, he/she wants to delete a product
                    ADMIN.deleteProduct(&readList, position);    // Calls deleteProduct function to delete a product
                    break;  // Break statement
                case 3: cout << "Updating a quantity..." << endl;   // If the user types 3, he/she wants update a quantity
                    ADMIN.updateQuantity(&readList, &shoppingCart, newQuantity, itemNumber);    // Calls updateQuantity function to update a quantity
                case 4: cout << "Updating an item cost..." << endl;   // If the user types 4, he/she wants update item cost
                    ADMIN.updateCost(&readList, &shoppingCart, newCost, itemNumber);
                    break;  // Break statement
                default:    // Goes to original menu
                    break;  // Break statement
            }
            
            break;  // Break statement
        }
        case 2: {
            cout << "Welcome CUSTOMER!" << endl;    // If the user types in 2 they are user
            Customer *currentCustomer = new Customer();
            string firstName;   // Declares string for first name
            string lastName;    // Declares string for lastname
            string ADDRESS; // Declares string for address
            string city;    // Declares string for city
            string state;   // Declares string for state
            int zipC = 0;   // Declares int for zipCode
            
            // Prompts user for first name and sets it
            cout << "First name: ";
            cin >> firstName;
            currentCustomer->setFirst(firstName);
            
            cin.clear();
            cin.ignore();
            cout << endl;
            
            // Prompts user for last name and sets it
            cout << "Last name: ";
            cin >> lastName;
            currentCustomer->setFirst(lastName);
            
            cin.clear();
            cin.ignore();
            cout << endl;
            
            // Prompts user for street address and sets it
            cout << "Street Address: ";
            cin >> ADDRESS;
            currentCustomer->setAddress(ADDRESS);
            cin.clear();
            cin.ignore();
            
            // Prompts user for city and sets it
            cout << "What city do you live in: ";
            cin >> city;
            currentCustomer->setCity(city);
            
            cout << endl;
            cin.clear();
            cin.ignore();
            
            // Prompts user for state and sets it
            cout << "What state do you live in: ";
            cin >> state;
            currentCustomer->setState(state);
            
            cin.clear();
            cin.ignore();
            cout << endl;
            
            // Prompts user for zipcode and sets it
            cout << "What is your zipcode: ";
            cin >> zipC;
            currentCustomer->setZipCode(zipC);
            cout << endl;
            
            bool exists = false;    // Creates a bool for checking for duplicates
            int itemInput = 1;  // Declares and initializes itemInput to 1
            string itemInputString; // Creates a string
            int quantity = 0;   // Initializes quantity to 0
            
            // A do-while loop that asks the user for itemNumber, to show the cart, and quantity if its valid as long as they dont input 0
            do {
                cout << "What products would you like to buy?(If you are done shopping type 0)" << endl;       // Prompts the user for what item number
                cout << "Type cart or Cart whenever to see your current items!" << endl;
                cin.clear();
                cin.ignore();
                cin >> itemInputString; // Takes input as string
                
                // If the input is equal to any of these values, the current cart is printed
                if (itemInputString == "Cart" || itemInputString == "cart" || itemInputString == "CART")
                {
                    currentCustomer->printCart(&shoppingCart); // Calls the print function
                    continue;   // Continues the loop
                }
                
                itemInput = stoi(itemInputString);  // Changes from string to int
                
                Inventory *lastofCart = currentCustomer->searchItem(&readList, itemInput);  // Creates a temporary node to transverse through the linked list
                
                Inventory *checkReadList = readList.getHead();
                
                // If/else statement that checks if input is invalid or vallid
                if (lastofCart == NULL)
                {
                    cout << "Invalid input." << endl;   // Error message
                    continue;
                }
                else
                {
                    cout << "Type how many you would like to buy: ";    // Prompts user for quantity
                    cin >> quantity;    // User input for quantity
                    
                    // Checks if quantity is 0 in the inventory file
                    if (lastofCart->getQuantity() == 0)
                    {
                        cout << "We apologize for the inconvience. We are currently out of stock :(" << endl;   // ERROR message
                        continue;   // Continues the loop
                    }
                    
                    // Loop checks if the quantity inputted is bigger than whats in the inventory file
                    while (quantity > lastofCart->getQuantity())
                    {
                        cout << "There is not enough available! Please reenter a quantity." << endl;    // ERROR message
                        cin >> quantity;    // Prompts reinput for quantity
                    }
                    
                    exists = false; // Sets exists for duplicates to false
                    Inventory *checkshoppingCart = shoppingCart.getHead();   // Creates a temporary node to transverse through the linked list
                    
                    // While loop that traverses and checks if the same itemNumber is typed more than once
                    while (checkshoppingCart != NULL)
                    {
                        // If statement that checks for duplicate input for itemNumber
                        if ((itemInput == checkshoppingCart->getItemNumber()) && quantity < checkReadList->getQuantity() && checkReadList->getQuantity() != 0){
                            exists = true;  // sets exists to true
                            checkshoppingCart->setQuantity(checkshoppingCart->getQuantity()+quantity); // Adds on to the original quantity of the first duplicate
                            checkReadList->setQuantity(checkReadList->getQuantity()-quantity);  // Deletes quantity from the inventory file
                            break;  // Break statement
                        }
                        
                        checkshoppingCart = checkshoppingCart->next;  // Goes to the next node
                    }
                    
                    Inventory *current = nullptr;   // Declares pointer
                    // If loop if there is not a duplicate
                    if (exists == false)
                    {
                        current = new Inventory();  // Creates new version
                        current->next = nullptr;    // Sets next ptr to null
                        shoppingCart += current;    // Adds the node
                    }
                    
                    
                    // If loop if there is not a duplicate
                    if (!exists)
                    {
                        current->setItemNumber(lastofCart->getItemNumber());   // Stores itemNumber
                        current->setItemName(lastofCart->getItemName());       // Stores itemName
                        current->setItemCost(lastofCart->getItemCost());       // Stores itemCost
                        
                        // If statement that checks if quantity is valid
                        if (quantity <= lastofCart->getQuantity())
                        {
                            current->setQuantity(quantity);    // Adds the quantity to the node
                            lastofCart->setQuantity(lastofCart->getQuantity() - quantity);  // Updates quantity in the inventory file
                            continue;
                        }
                        
                        // Checks if quantity in the inventory file is 0
                        if (lastofCart->getQuantity() == 0)
                        {
                            cout << "We apologize for the inconvience. We are currently out of stock :(" << endl;   // ERROR message
                            continue;
                        }
                        
                        // While loop that loops if the user keeps typing incorrect quantity
                        while (quantity > lastofCart->getQuantity())
                        {
                            cout << "There is not enough available! Please reenter a quantity." << endl;    // ERROR message
                            cin >> quantity;    // Takes in quantity
                            
                            // If statement is valid
                            if (quantity < lastofCart->getQuantity())
                            {
                                lastofCart->setQuantity(checkshoppingCart->getQuantity()+quantity);    // Adds the quantity to the node
                                checkReadList->setQuantity(checkReadList->getQuantity()-quantity);  // Updates quantity in the inventory file
                                break;
                            }
                        }
                        
                        checkshoppingCart->next = checkshoppingCart; // Traverses through the shoppingCart linked list
                        
                    }
                }
            }
            while (itemInput != 0); // User types 0
            
            currentCustomer->printCart(&shoppingCart); // Calls the print function
            
            string invoiceName; // Creates string variable for invoicename
            invoiceName = lastName + "_Invoice.txt";    // takes in the last name of the customer
            
            fstream shoppingFile(invoiceName, ios::out);  // DECLARES fstream object to write to a file called "_invoice.txt"
            
            shoppingFile << "Customer First Name: " << currentCustomer->getFirst() << endl; // Displays the customer's first name
            shoppingFile << "Customer Last Name: " << currentCustomer->getLast() << endl; // Displays the customer's last name
            shoppingFile << "Street Address: " << currentCustomer->getAddress() << endl; // Displays the customer's address
            shoppingFile << "City: " << currentCustomer->getCity() << endl; // Displays the customer's city
            shoppingFile << "State: " << currentCustomer->getState() << endl; // Displays the customer's state
            shoppingFile << "Zip Code: " << currentCustomer->getZipCode() << endl; // Displays the customer's zipCode
            shoppingFile << '\n' << endl;     // Skips line
            
            // Displays headers
            shoppingFile << "Item Number" << '\t' << "Item Name" << '\t' << "    " <<
            "Qty" << '\t' << "    " << "Unit Cost" << '\t' << "Total" << '\n';
            shoppingFile << "----------------------------------------------------------------------------" <<endl;   // Writes line
            
            double TOTAL = 0;       // Declares double variable called TOTAL to add the cost of all the items
            
            Inventory *current = shoppingCart.getHead();    //Creates a temporary node that runs through the linked list
            
            // WHILE-LOOP used to display the products the user has selected and keep adding the total cost to the variable TOTAL
            while (current != NULL)
            {
                shoppingFile << current->getItemNumber() << setw(14);                                         // Displays the item number
                shoppingFile << "Product " << current->getItemName() << setw(14);                            // Displays the product name
                shoppingFile << current->getItemCost() << setw(14);                                         // Displays the quantity
                shoppingFile << "$" << current->getQuantity() << setw(14);                                 // Displays the unit cost
                shoppingFile << "$" << current->getItemCost()  * current->getQuantity() << endl;              // Displays the total cost for the item
                
                TOTAL += current->getItemCost() * current->getQuantity();   // Keeps adding the total cost of the item to the variable TOTAL
                current = current->next;    // Traverses through the linked list
            }
            shoppingFile << "----------------------------------------------------------------------------" <<endl;   // Writes line
            shoppingFile << setw(70) << "Total: " << TOTAL;    // Displays the final total
            break;
        }
        case 3: {
            adminOrUser = 3;        // If the user types in 3, input is set to 3
            cout << "EXITING..." << endl;     // Tells the user the file is exitting
            
            fstream updatedFile;    // Creates a new fstream object to output the updated "ProductData.csv" file
            Inventory *updateCSV = readList.getHead()->next;   // Creates a temporary node that runs through the linked list
            updatedFile.open("ProductData.csv", ios::in | ios::out | ios::trunc);   // Opens the file in input, output, and trunc
            
            // While loop that runs through the linked list and outputs the updated file
            while (updateCSV != NULL)
            {
                // An if statement that only outputs products that dont have a quantity of 0
                if (updateCSV->getQuantity() > 0)
                {
                    updatedFile << updateCSV->getItemNumber() << ", Product " << updateCSV->getItemName() << ","  << updateCSV->getItemCost() << // Outputs the item info
                    "," << updateCSV->getQuantity() << endl;
                }
                updateCSV = updateCSV->next;    // Traverses to the next node
            }
            updatedFile.close();    // Closes the updatedFile list
            
            Inventory* currentNodeREAD = readList.getHead();       // Create a temporary node to use to transverse through the linked list
            Inventory* nextNodeREAD;             // Create a temporary node to keep track of the next node
            
            while (currentNodeREAD != nullptr) {                // Traverse the linked list until you reach the end
                nextNodeREAD = currentNodeREAD->next;                // Set the next node
                delete currentNodeREAD;                            // Delete the current node
                currentNodeREAD = nextNodeREAD;                        // Set current node to the next node
            }
            currentNodeREAD = NULL;                                // Return null ptr to the calling function
            
            Inventory* currentNodeShopping = shoppingCart.getHead();          //Create a temporary node to use to transverse through the linked list
            Inventory* nextNodeShopping;             //Create a temporary node to keep track of the next node
            
            
            while (currentNodeShopping != nullptr) {                // Traverse the linked list until you reach the end
                nextNodeShopping = currentNodeShopping->next;                // Set the next node
                delete currentNodeShopping;                            // Delete the current node
                currentNodeShopping = nextNodeShopping;                        // Set current node to the next node
            }
            currentNodeShopping = NULL;                                // Return null ptr to the calling function
            
            break;  // Break statement
        }
    }
        
    }
    while (adminOrUser != 3);
    
}

