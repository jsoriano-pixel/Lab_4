/*Log transactions.
Now, extend your inventory section at the end to include all of the items you have on the menu (Let's assume a small, medium, and large each count as one item).  After all the customers have finished ordering, log an updated inventory including the original amount in inventory, the change in amount, and the new amount. For example:

Daily Inventory
Item					Start		Change	End
Bacon Cheeseburgers		50		-6		44
Loaded Cheesy Fries			50		-3		47
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;


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




    struct menuItem {
        string food1, food2, food3, food4;
        double food1sm, food1med, food1lg, food2sm, food2med, food2lg, food3sm, food3med, food3lg, food4sm, food4med, food4lg;
    };

    menuItem menu;


ifstream menuFile("menu.txt");
    if (!menuFile) {
        cout << "Error opening menu.txt file." << endl;
        return 1;
    }
    getline(menuFile, menu.food1);
menuFile >> menu.food1sm >> menu.food1med >> menu.food1lg;
menuFile.ignore();

getline(menuFile, menu.food2);
menuFile >> menu.food2sm >> menu.food2med >> menu.food2lg;
menuFile.ignore();

getline(menuFile, menu.food3);
menuFile >> menu.food3sm >> menu.food3med >> menu.food3lg;
menuFile.ignore();

getline(menuFile, menu.food4);
menuFile >> menu.food4sm >> menu.food4med >> menu.food4lg;

menuFile.close();


ofstream receiptFile("receipt.txt");
    if (!receiptFile) {
        cout << "Error opening receipt.txt file." << endl;
        return 1;
    }

ofstream inventoryFile("inventory.txt");
    if (!inventoryFile) {
        cout << "Error opening inventory.txt file." << endl;
        return 1;
    }


    cout << left << "Small " << setw(15) << "Medium " << setw(15) << "Large" << endl;
    cout << left << setw(10) << menu.food1 << setw(15) << "$" << menu.food1sm << setw(15) << "$" << menu.food1med << setw(15) << "$" << menu.food1lg << endl;
    cout << left << setw(10) << menu.food2 << setw(15) << "$" << menu.food2sm << setw(15) << "$" << menu.food2med << setw(15) << "$" << menu.food2lg << endl;
    cout << left << setw(10) << menu.food3 << setw(15) << "$" << menu.food3sm << setw(15) << "$" << menu.food3med << setw(15) << "$" << menu.food3lg << endl;
    cout << left << setw(10) << menu.food4 << setw(15) << "$" << menu.food4sm << setw(15) << "$" << menu.food4med << setw(15) << "$" << menu.food4lg << endl;
    


    double grandTotalSales = 0.0;
    int totalCustomers = 0;



   while(true) {
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
        cout << "\nPlease select from the following options:" << endl
             << menu.food1 << endl
             << menu.food2 << endl
             << menu.food3 << endl
             << menu.food4 << endl
             << "Checkout" << endl; 
        cout << "Enter selection: ";
        cin >> choice; // Food choice

        while (choice != menu.food1 && choice != menu.food2 && choice != menu.food3 && choice != menu.food4 && choice != "Checkout") {
            cout << "Invalid choice. Please select again (" << menu.food1 << ", " << menu.food2 << ", " << menu.food3 << ", " << menu.food4 << ", Checkout): ";
            cin >> choice;
        }

        if (choice != "Checkout") {
            if (choice == menu.food1) {
                burgerCount += burgerTotal;    
                if (sizeChoice == "Small") price = menu.food1sm;
                else if (sizeChoice == "Medium") price = menu.food1med;
                else price = menu.food1lg;
            }
            else if (choice == menu.food2) {
                friesCount += friesTotal;
                if (sizeChoice == "Small") price = menu.food2sm;
                else if (sizeChoice == "Medium") price = menu.food2med;
                else price = menu.food2lg;
            }
            else if (choice == menu.food3) {
                okraCount += okraTotal;
                if (sizeChoice == "Small") price = menu.food3sm;
                else if (sizeChoice == "Medium") price = menu.food3med;
                else price = menu.food3lg;
            }
            else if (choice == menu.food4) {
                buscuitsCount += buscuitsTotal;
                if (sizeChoice == "Small") price = menu.food4sm;
                else if (sizeChoice == "Medium") price = menu.food4med;
                else price = menu.food4lg;
            }

            cout << "Please select the size of your order:" << endl;

    
            cout << "Small" << endl
                 << "Medium" << endl
                 << "Large" << endl;
            cout << "Enter size: ";
            cin >> sizeChoice; // Size choice
            
            while (sizeChoice != "Small" && sizeChoice != "Medium" && sizeChoice != "Large") {
                cout << "Invalid size choice. Please select again (Small, Medium, Large): ";
                cin >> sizeChoice; 
            }

            if (choice == menu.food1) {
                burgerCount++;
            }
            else if (choice == menu.food2) {
                friesCount++;
            }
            else if (choice == menu.food3) {
                okraCount++;
            }
            else if (choice == menu.food4) {
                buscuitsCount++;
            }

            if (sizeChoice == "Small") {
                price = price * 1.0;
            }
            else if (sizeChoice == "Medium") {
                price = price * 1.5;
            }
            else if (sizeChoice == "Large") {
                price = price * 2.0;
            }

            cout << "Enter the quantity of your order: ";
            cin >> quantity;
            while (quantity <= 0) {
                cout << "Quantity must be 1 or more. Re-enter: ";
                cin >> quantity; // Quantity
            }
            burgerTotal += (choice == menu.food1) ? quantity : 0;
            friesTotal += (choice == menu.food2) ? quantity : 0;
            okraTotal += (choice == menu.food3) ? quantity : 0;
            buscuitsTotal += (choice == menu.food4) ? quantity : 0;
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


       inventoryFile << "Daily Inventory" << endl;
    inventoryFile << left << setw(20) << "Item" << setw(10) << "Start" << setw(10) << "Change" << setw(10) << "End" << endl;
    inventoryFile << left << setw(20) << menu.food1 << setw(10) << inventorySize << setw(10) << -burgerTotal << setw(10) << inventorySize - burgerTotal << endl;
    inventoryFile << left << setw(20) << menu.food2 << setw(10) << inventorySize << setw(10) << -friesTotal << setw(10) << inventorySize - friesTotal << endl;
    inventoryFile << left << setw(20) << menu.food3 << setw(10) << inventorySize << setw(10) << -okraTotal << setw(10) << inventorySize - okraTotal << endl;
    inventoryFile << left << setw(20) << menu.food4 << setw(10) << inventorySize << setw(10) << -buscuitsTotal << setw(10) << inventorySize - buscuitsTotal << endl;
    inventoryFile.close();

    cout << fixed << setprecision(2) << endl;
   cout << "End of the Day" << endl;
   cout << "Total Sales: $" << grandTotalSales << endl;
   cout << "Total Customers: " << totalCustomers << endl;

    return 0;
}
    



