#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()

{
	string foodName;
	char itemCode;
	int itemQuantity;
	double unitPrice;
	char isMember;
	string cashierNotes;
	string Smashburger


	double member2 = 0;
	double total = 0;
	cout << "Small	Medium	Large
		Smashburger	5.5	7.8	11.5
		Fries	2.5	5.5	7.5
		Okra	2.3	4.5	6.5
		LimpBiscuit	5	10	15.5";
	cout << "Select an option";
	if (Smashburger == true )

	cout << "Enter the item quantity: ";
	cin >> itemQuantity;

	cout << "Enter the unit price: " << endl;
	cin >> unitPrice;
	cout << "Are you a member? (y/n) ";
	cin >> isMember;
	cin.ignore();
	cout << "Enter cashier notes: ";
	getline(cin, cashierNotes);


	if (isMember == 'y' || isMember == 'Y') {
		member2 = (unitPrice * itemQuantity) * 0.2;
		total = (unitPrice * itemQuantity) - member2;


	}
	else {
		total = unitPrice * itemQuantity;
	}

	cout << left;
	cout << setw(15) << "Name" << setw(15) << "Code" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Member?" << endl;
	cout << left;
	cout << setw(15) << foodName << setw(15) << itemCode << setw(15) << itemQuantity << fixed << setprecision(2) << total << setw(15) << isMember << endl;
	cout << "Cashier notes: " << cashierNotes;



}




