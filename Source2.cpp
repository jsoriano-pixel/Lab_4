#include <iostream>
#include <iomanip>
#include <string>
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
    cout << left << "Small " << setw(15) << "Medium " << setw(15) << "Large" << endl;
    cout << left << setw(10) << "Smashburger" << setw(15) << "$5.50" << setw(15) << "$8.25" << setw(15) << "$11.00" << endl;
    cout << left << setw(10) << "Fries" << setw(15) << "$2.50" << setw(15) << "$3.75" << setw(15) << "$5.00" << endl;
    cout << left << setw(10) << "Okra" << setw(15) << "$2.30" << setw(15) << "$3.45" << setw(15) << "$4.60" << endl;
    cout << left << setw(10) << "LimpBiscuit" << setw(15) << "$5.00" << setw(15) << "$7.50" << setw(15) << "$10.00" << endl;
    


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
             << "Smashburger" << endl
             << "Fries" << endl
             << "Okra" << endl
             << "LimpBiscuit" << endl
             << "Checkout" << endl; 
        cout << "Enter selection: ";
        cin >> choice; // Food choice

        while (choice != "Smashburger" && choice != "Fries" && choice != "Okra" && choice != "LimpBiscuit" && choice != "Checkout") {
            cout << "Invalid choice. Please select again (Smashburger, Fries, Okra, LimpBiscuit, Checkout): ";
            cin >> choice;
        }

        if (choice != "Checkout") {
            if (choice == "Smashburger") {
                price = 5.50;
            }
            else if (choice == "Fries") {
                price = 2.50;
            }
            else if (choice == "Okra") {
                price = 2.30;
            }
            else if (choice == "LimpBiscuit") {
                price = 5.00;
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
        cout << "\nItems Ordered:" << endl;
        cout << receipt;
        cout << "Thank you for stopping by!" << endl;
        cout << "Total Amount Due: $" << totalPrice << endl;
    } else {
        cout << "No items were ordered " << customerName << "!" << endl;
    }
    grandTotalSales += totalPrice;
    totalCustomers++;
    



   }
   }
    cout << fixed << setprecision(2) << endl;
   cout << "End of the Day" << endl;
   cout << "Total Sales: $" << grandTotalSales << endl;
   cout << "Total Customers: " << totalCustomers << endl;

    return 0;
}
    



