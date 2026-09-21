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
	bool isMember;

	cout << "Enter the food name: ";
	getline(cin, foodName);
	cout << "Enter the item code: ";
	cin >> itemCode;
	cout << "Enter the item quantity: ";
	cin >> itemQuantity;

	cout << "Enter the unit price: " << endl;
	cin >> unitPrice;
	cout << "Are you a member? (y/n) ";
	cin >> isMember;

	cout << left;
	cout << setw(15) << "Name" << setw(15) << "Code" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Member?" << endl;
	cout << left;
	cout << setw(15) << foodName << setw(15) << itemCode << setw(15) << itemQuantity << fixed << setprecision(2) << unitPrice << setw(15) << isMember << endl;


}