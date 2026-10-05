#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    // Variables
    double price = 0.0;
    char choice;
    char sizeChoice;
    int quantity;
    char isMember;
    char tip;
    double tipAmount;
    double totalPrice = 0.0;
    string customerName;

    cout << left << "Small " << setw(15) << "Medium " << setw(15) << "Large" << endl;
    cout << left << setw(10) << "Smashburger" << setw(15) << "$5.50" << setw(15) << "$8.25" << setw(15) << "$11.00" << endl;
    cout << left << setw(10) << "Fries" << setw(15) << "$2.50" << setw(15) << "$3.75" << setw(15) << "$5.00" << endl;
    cout << left << setw(10) << "Okra" << setw(15) << "$2.30" << setw(15) << "$3.45" << setw(15) << "$4.60" << endl;
    cout << left << setw(10) << "LimpBiscuit" << setw(15) << "$5.00" << setw(15) << "$7.50" << setw(15) << "$10.00" << endl;
    
    cout << "\nEnter your name: ";
    getline(cin, customerName);

    do { 
        cout << "\nPlease select from the following options:" << endl
             << "A. Smashburger" << endl
             << "B. Fries" << endl
             << "C. Okra" << endl
             << "D. LimpBiscuit" << endl
             << "E. Checkout" << endl; 
        cout << "Enter selection: ";
        cin >> choice;
        choice = toupper(choice);

        while (choice < 'A' || choice > 'E') {
            cout << "Invalid choice. Please select again (A-E): ";
            cin >> choice;
            choice = toupper(choice);
        }

        if (choice != 'E') {
            if (choice == 'A') {
                price = 5.50;
            }
            else if (choice == 'B') {
                price = 2.50;
            }
            else if (choice == 'C') {
                price = 2.30;
            }
            else if (choice == 'D') {
                price = 5.00;
            }

            cout << "Please select the size of your order:" << endl
                 << "S. Small" << endl
                 << "M. Medium" << endl
                 << "L. Large" << endl;
            cout << "Enter size: ";
            cin >> sizeChoice;
            sizeChoice = toupper(sizeChoice);
            
            // FIXED: Corrected alpha bounds checking logic for size variations
            while (sizeChoice != 'S' && sizeChoice != 'M' && sizeChoice != 'L') {
                cout << "Invalid size choice. Please select again (S, M, L): ";
                cin >> sizeChoice;
                sizeChoice = toupper(sizeChoice);
            }

            if (sizeChoice == 'S') {
                price = price * 1.0;
            }
            else if (sizeChoice == 'M') {
                price = price * 1.5;
            }
            else if (sizeChoice == 'L') {
                price = price * 2.0;
            }

            cout << "Enter the quantity of your order: ";
            cin >> quantity;
            while (quantity <= 0) {
                cout << "Quantity must be 1 or more. Re-enter: ";
                cin >> quantity;
            }

            totalPrice += price * quantity;
            cout << fixed << setprecision(2);
            cout << "Item added! Running subtotal: $" << totalPrice << endl;
        }

    } while (choice != 'E');
    
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

        price = conwayTaxPrice;

        cout << "\nSelect a tip amount:" << endl
             << "A. 15%" << setw(20) << "Amount: $" << price * 0.15 << endl
             << "B. 20%" << setw(20) << "Amount: $" << price * 0.20 << endl
             << "C. 25%" << setw(20) << "Amount: $" << price * 0.25 << endl
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
            price = price * 1.15;
        }
        else if (tip == 'B') {
            price = price * 1.20;
        }
        else if (tip == 'C') {
            price = price * 1.25;
        }
        else {
            cout << "Enter the custom tip amount: $";
            cin >> tipAmount;
            while (tipAmount < 0) {
                cout << "Tip amount cannot be negative. Re-enter: $";
                cin >> tipAmount;
            }
            price = price + tipAmount;
        }

        cout << "Receipt for: " << customerName << endl;
        cout << "Thank you for stopping by!" << endl;
        cout << "Total Amount Due: $" << price << endl;
    } else {
        cout << "No items were ordered " << customerName << "!" << endl;
    }

    return 0;
}
