#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

   struct menuItem {
        string food1, food2, food3, food4;
        double food1sm, food1med, food1lg, food2sm, food2med, food2lg, food3sm, food3med, food3lg, food4sm, food4med, food4lg;
    };


    void loadMenu (ifstream& menuFile, string& food, double& sm, double& med, double& lg) { // Function to load menu items from file
        getline(menuFile, food);
        menuFile >> sm >> med >> lg;
        menuFile.ignore();
    }

        void itemSetup(string food, double sm, double med, double lg) { // Function to display menu items with prices
        cout << left << setw(10) << food << setw(15) << "$" << sm << setw(15) << "$" << med << setw(15) << "$" << lg << endl;
    }

    void displayMenu(string food1, string food2, string food3, string food4) { // Function to display the menu
        cout << "\nPlease select from the following options:" << endl
             << food1 << endl
             << food2 << endl
             << food3 << endl
             << food4 << endl
             << "Checkout" << endl;
    }
    string getSize() { // Function to get the size choice from the user
        string sizeChoice;
        cout << "Please select the size of your order:" << endl;
        cout << "Small" << endl
             << "Medium" << endl
             << "Large" << endl;
        cin >> sizeChoice;
        return sizeChoice;

        while (sizeChoice != "Small" && sizeChoice != "Medium" && sizeChoice != "Large") {
            cout << "Invalid size choice. Please select again (Small, Medium, Large): ";
            cin >> sizeChoice; 
        }
        return sizeChoice;
    }

    void writeInventory(ofstream& inventoryFile, menuItem menu, int inventorySize, int burgerTotal, int friesTotal, int okraTotal, int buscuitsTotal) { // Function to write inventory to file
        inventoryFile << "Daily Inventory" << endl;
        inventoryFile << left << setw(20) << "Item" << setw(10) << "Start" << setw(10) << "Change" << setw(10) << "End" << endl;
        inventoryFile << left << setw(20) << menu.food1 << setw(10) << inventorySize << setw(10) << -burgerTotal << setw(10) << inventorySize - burgerTotal << endl;
        inventoryFile << left << setw(20) << menu.food2 << setw(10) << inventorySize << setw(10) << -friesTotal << setw(10) << inventorySize - friesTotal << endl;
        inventoryFile << left << setw(20) << menu.food3 << setw(10) << inventorySize << setw(10) << -okraTotal << setw(10) << inventorySize - okraTotal << endl;
        inventoryFile << left << setw(20) << menu.food4 << setw(10) << inventorySize << setw(10) << -buscuitsTotal << setw(10) << inventorySize - buscuitsTotal << endl;
    }

    void updateCount(int& count, int& total, int quantity) { // Function to update the count and total of items ordered
        count++;
        total += quantity;
    }

int main()
{
    // Variables
    double price = 0.0;
    string choice;
    string sizeChoice;
    int quantity;
    char isMember;
    char tip;
    double tipAmount;
    double totalPrice = 0.0;
    string customerName;
    char anotherCustomer;
    string receipt;
    int inventorySize = 50;
    int burgerCount = 0;
    int burgerTotal = 0;
    int friesCount = 0;
    int friesTotal = 0;
    int okraCount = 0;
    int okraTotal = 0;
    int buscuitsCount = 0;
    int buscuitsTotal = 0;




 
    menuItem menu;


ifstream menuFile("menu.txt");  // Open the menu.txt file
    if (!menuFile) {
        cout << "Error opening menu.txt file." << endl;
        return 1;
    }



 loadMenu(menuFile, menu.food1, menu.food1sm, menu.food1med, menu.food1lg);
    loadMenu(menuFile, menu.food2, menu.food2sm, menu.food2med, menu.food2lg);
    loadMenu(menuFile, menu.food3, menu.food3sm, menu.food3med, menu.food3lg);
    loadMenu(menuFile, menu.food4, menu.food4sm, menu.food4med, menu.food4lg);

ofstream receiptFile("receipt.txt"); // Open the receipt.txt file
    if (!receiptFile) {
        cout << "Error opening receipt.txt file." << endl;
        return 1;
    }

ofstream inventoryFile("inventory.txt"); // Open the inventory.txt file
    if (!inventoryFile) {
        cout << "Error opening inventory.txt file." << endl;
        return 1;
    }


       
    cout << left << "Small " << setw(15) << "Medium " << setw(15) << "Large" << endl;
    itemSetup(menu.food1, menu.food1sm, menu.food1med, menu.food1lg);
    itemSetup(menu.food2, menu.food2sm, menu.food2med, menu.food2lg);
    itemSetup(menu.food3, menu.food3sm, menu.food3med, menu.food3lg);
    itemSetup(menu.food4, menu.food4sm, menu.food4med, menu.food4lg);



    double grandTotalSales = 0.0;
    int totalCustomers = 0;



   while(true) { // Daily loop for customers
   cout << "Is there a customer? (Y/N): ";
   cin >> anotherCustomer;
   anotherCustomer = toupper(anotherCustomer);
   

   if (anotherCustomer == 'N') {
       break;
   }


   else if (anotherCustomer == 'Y') {



   cin.ignore();

   totalPrice = 0.0;
   receipt = "";
    cout << "\nEnter your name: ";
    getline(cin, customerName);
   
    do { 
        displayMenu(menu.food1, menu.food2, menu.food3, menu.food4);
        cout << "Enter selection: ";
        cin >> choice; // Food choice variable

        while (choice != menu.food1 && choice != menu.food2 && choice != menu.food3 && choice != menu.food4 && choice != "Checkout") {
            cout << "Invalid choice. Please select again (" << menu.food1 << ", " << menu.food2 << ", " << menu.food3 << ", " << menu.food4 << ", Checkout): ";
            cin >> choice; 
        }

        if (choice != "Checkout") {


            sizeChoice = getSize(); // Assigns the size choice to the variable sizeChoice
            if (choice == menu.food1) {
                if (sizeChoice == "Small") price = menu.food1sm;
                else if (sizeChoice == "Medium") price = menu.food1med;
                else price = menu.food1lg;
            }
            else if (choice == menu.food2) {
                if (sizeChoice == "Small") price = menu.food2sm;
                else if (sizeChoice == "Medium") price = menu.food2med;
                else price = menu.food2lg;
            }
            else if (choice == menu.food3) {
                if (sizeChoice == "Small") price = menu.food3sm;
                else if (sizeChoice == "Medium") price = menu.food3med;
                else price = menu.food3lg;
            }
            else if (choice == menu.food4) {
                if (sizeChoice == "Small") price = menu.food4sm;
                else if (sizeChoice == "Medium") price = menu.food4med;
                else price = menu.food4lg;
            }

            cout << "Enter the quantity of your order: ";
            cin >> quantity;
            while (quantity <= 0) {
                cout << "Quantity must be 1 or more. Re-enter: ";
                cin >> quantity; // Quantity variable
            }
            if (choice == menu.food1) { // This updates the count and total of each item ordered based on the user's choice
                updateCount(burgerCount, burgerTotal, quantity);
            }
            else if (choice == menu.food2) {
                updateCount(friesCount, friesTotal, quantity);
            }
            else if (choice == menu.food3) {
                updateCount(okraCount, okraTotal, quantity);
            }
            else if (choice == menu.food4) {
                updateCount(buscuitsCount, buscuitsTotal, quantity);
            }
            receipt += choice + " - " + sizeChoice + " - Quantity: " + to_string(quantity) + "\n";

    

            totalPrice += price * quantity;
            cout << fixed << setprecision(2);
            cout << "Item added! Running subtotal: $" << totalPrice << endl;
        }

    } while (choice != "Checkout"); 
    
    if (totalPrice > 0) {
        cout << "\nAre you a member? (Y/N): ";
        cin >> isMember;
        isMember = toupper(isMember);

        while (isMember != 'Y' && isMember != 'N') {
            cout << "Invalid choice. Please enter Y or N: ";
            cin >> isMember;
            isMember = toupper(isMember);
        }

        if (isMember == 'Y') {
            totalPrice = totalPrice * 0.90; 
        }

        double stateTaxPrice = totalPrice * 1.065;
        double countyTaxPrice = stateTaxPrice * 1.005;
        double conwayTaxPrice = countyTaxPrice * 1.02125;

        cout << fixed << setprecision(2) << endl;
        cout << "Your price after Arkansas State Tax (6.5%): $" << stateTaxPrice << endl;
        cout << "Your price after Faulkner County Tax (0.5%): $" << countyTaxPrice << endl;
        cout << "Your price after Conway Municipal Tax (2.125%): $" << conwayTaxPrice << endl;

        totalPrice = conwayTaxPrice;

        

        cout << "\nSelect a tip amount:" << endl
             << "A. 15%" << setw(20) << "Amount: $" << totalPrice * 0.15 << endl
             << "B. 20%" << setw(20) << "Amount: $" << totalPrice * 0.20 << endl
             << "C. 25%" << setw(20) << "Amount: $" << totalPrice * 0.25 << endl
             << "D. Other" << endl;
        cout << "Enter tip choice: ";
        cin >> tip;
        tip = toupper(tip);

        while (tip < 'A' || tip > 'D') {
            cout << "Invalid selection. Please enter A, B, C, or D: ";
            cin >> tip;
            tip = toupper(tip);
        }

        if (tip == 'A') {
            totalPrice = totalPrice * 1.15;
        }
        else if (tip == 'B') {
            totalPrice = totalPrice * 1.20;
        }
        else if (tip == 'C') {
            totalPrice = totalPrice * 1.25;
        }
        else {
            cout << "Enter the custom tip amount: $";
            cin >> tipAmount;
            while (tipAmount < 0) {
                cout << "Tip amount cannot be negative. Re-enter: $";
                cin >> tipAmount;
            }
            totalPrice = totalPrice + tipAmount;
        }
        int loyaltyPoint = totalPrice/3;
        for (int i = 0; i < loyaltyPoint; ++i) {
            cout << "*";
        }

        

        cout << "Receipt for: " << customerName << endl;
        receiptFile << "Receipt for: " << customerName << endl;
        cout << "\nItems Ordered:" << endl;
        receiptFile << "\nItems Ordered:" << endl;
        cout << receipt;
        receiptFile << receipt;
        cout << "Thank you for stopping by!" << endl;
        receiptFile << "Thank you for stopping by!" << endl;
        cout << "Total Amount Due: $" << totalPrice << endl;
        receiptFile << "Total Amount Due: $" << totalPrice << endl;
    } else {
        cout << "No items were ordered " << customerName << "!" << endl;
        receiptFile << "No items were ordered " << customerName << "!" << endl;
    }
    grandTotalSales += totalPrice;
    totalCustomers++;
   }
   }
       writeInventory(inventoryFile, menu, inventorySize, burgerTotal, friesTotal, okraTotal, buscuitsTotal); // Write inventory to file

    cout << fixed << setprecision(2) << endl;
   cout << "End of the Day" << endl;
   cout << "Total Sales: $" << grandTotalSales << endl;
   cout << "Total Customers: " << totalCustomers << endl;
    return 0;
}