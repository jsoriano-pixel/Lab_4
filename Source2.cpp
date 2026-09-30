#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double price;
    char choice;
    char sizeChoice;
    int quantity;
    char isMember;
    char tip;
    double tipAmount;

    cout << left << "Small " << setw(15) << "Medium " << setw(15) << "Large" << endl;
    cout << left << setw(10) << "Smashburger" << setw(15) << "$5.50" << setw(15) << "$8.25" << setw(15) << "$11.00" << endl;
    cout << left << setw(10) << "Fries" << setw(15) << "$2.50" << setw(15) << "$3.75" << setw(15) << "$5.00" << endl;
    cout << left << setw(10) << "Okra" << setw(15) << "$2.30" << setw(15) << "$3.45" << setw(15) << "$4.60" << endl;
    cout << left << setw(10) << "LimpBiscuit" << setw(15) << "$5.00" << setw(15) << "$7.50" << setw(15) << "$10.00" << endl;

    cout << "Please select from the following options:" << endl
         << "A. Smashburger" << endl
         << "B. Fries" << endl
         << "C. Okra" << endl
         << "D. LimpBiscuit" << endl;
    cin >> choice;

    if (choice == 'A') {
        price = 5.50;
    }
    else if (choice == 'B') {
        price = 2.50;
    }
    else if (choice == 'C') {
        price = 2.30;
    }
    else {
        price = 5.00;
    }

    cout << "Please select the size of your order:" << endl
         << "S. Small" << endl
         << "M. Medium" << endl
         << "L. Large" << endl;
    cin >> sizeChoice;

    if (sizeChoice == 'S') {
        price = price * 1.0;
    }
    else if (sizeChoice == 'M') {
        price = price * 1.5;
    }
    else {
        price = price * 2.0;
    }

    cout << "Enter the quantity of your order: ";
    cin >> quantity;

    price = price * quantity;

    cout << "Are you a member? (Y/N): ";
    cin >> isMember;

    if (isMember == 'Y') {
        price = price * 0.90;
    }
    else {
        cout << "Invalid membership choice." << endl;
    }

    double stateTaxPrice = price * 1.065;
    double countyTaxPrice = stateTaxPrice * 1.005;
    double conwayTaxPrice = countyTaxPrice * 1.02125;

    cout << fixed << setprecision(2) << endl;

    cout << "Your price after Arkansas State Tax (6.5%): $"
         << stateTaxPrice << endl;

    cout << "Your price after Faulkner County Tax (0.5%): $"
         << countyTaxPrice << endl;

    cout << "Your price after Conway Municipal Tax (2.125%): $"
         << conwayTaxPrice << endl;

    price = conwayTaxPrice;

    
    cout << "Select a tip amount:" << endl
         << "A. 15%" << setw(20) << "Amount: $" << price * 0.15 << endl
         << "B. 20%" << setw(20) << "Amount: $" << price * 0.20 << endl
         << "C. 25%" << setw(20) << "Amount: $" << price * 0.25 << endl
         << "D. Other" << endl;
    cin >> tip;

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
        cout << "Enter the tip amount: ";
        cin >> tipAmount;
        price = price + tipAmount;
    }

    cout << endl;
    cout << "You have selected " << choice
         << " and the size is " << sizeChoice
         << ". The quantity is " << quantity << "." << endl;

    cout << "The total price is: $" << price << endl;

}