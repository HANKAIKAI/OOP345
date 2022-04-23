// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "foodorder.h"
using namespace std;
double g_taxrate = 0.0, g_dailydiscount = 0.0;

namespace sdds {
	FoodOrder::FoodOrder() {
		this->cusName[0] = '\0';
		this->descripFood[0] = '\0';
		this->price = 0.0;
		this->dailySpecial = true;
	}
	istream& FoodOrder::read(istream& istr) {
		/*char _cusName[10]{};
		char _descripFood[25]{};
		double _price = 0.0;*/
		char _dailySpecial = '\0';

		if (istr) {
			istr.getline(this->cusName, 10, ',');
			istr.getline(this->descripFood, 25, ',');
			istr >> this->price;
			istr.ignore();
			istr >> _dailySpecial;
			if (_dailySpecial == 'Y') {
				this->dailySpecial = true;
			}
			else if (_dailySpecial == 'N') {
				this->dailySpecial = false;
			}
		}
		return istr;
	}
	void FoodOrder::display() const {
		static unsigned int COUNTER = 0;
		double priceWithTax = this->price * (1 + g_taxrate);
		double specialPrice = priceWithTax - g_dailydiscount;

		cout.width(2);
		cout.setf(ios::left);
		cout << ++COUNTER << ". ";
		cout.unsetf(ios::left);

		if (this->cusName[0] != '\0') {
			// Name
			cout.width(10);
			cout.setf(ios::left);
			cout << this->cusName;
			cout.unsetf(ios::left);

			cout << "|";
			// Order Description
			cout.width(25);
			cout.setf(ios::left);
			cout << this->descripFood;
			cout.unsetf(ios::left);

			cout << "|";
			// Price w/Tax
			cout.width(12);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.setf(ios::left);
			cout << priceWithTax;
			cout.unsetf(ios::left);

			cout << "|";
			// Special Price
			if (this->dailySpecial == true) {
				cout.width(13);
				cout.setf(ios::right);
				cout << specialPrice;
				cout.unsetf(ios::right);
			}
			cout << endl;
		}
		else {
			cout << "No Order" << endl;
		}
	}
}