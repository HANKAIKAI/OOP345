// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
#include <iostream>

extern double g_taxrate, g_dailydiscount;

namespace sdds {
	class FoodOrder {
		char cusName[10];
		char descripFood[25];
		double price;
		bool dailySpecial;
	public:
		FoodOrder();
		std::istream& read(std::istream& istr = std::cin);
		void display() const;
	};
}
#endif // !SDDS_FOODORDER_H_


