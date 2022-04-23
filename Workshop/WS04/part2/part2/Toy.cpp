// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/12
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Toy.h"

using namespace std;

namespace sdds
{
	Toy::Toy() {};
	void Toy::update(int numItems)
	{
		m_numItems = numItems;
	};

	// ID:NAME:NUM:PRICE
	Toy::Toy(const string& toy)
	{
		string atemp = toy;

		// ID
		m_orderId = atemp.substr(0, atemp.find(':'));
		m_orderId.erase(m_orderId.find_last_not_of(' ') + 1);
		//erase temp space
		atemp.erase(0, atemp.find(':') + 1);

		// Name
		m_name = atemp.substr(0, atemp.find(':'));
		m_name.erase(0, m_name.find_first_not_of(' '));
		m_name.erase(m_name.find_last_not_of(' ') + 1);
		//erase temp space
		atemp.erase(0, atemp.find(':') + 1);

		// NUM
		m_numItems = stoi(atemp.substr(0, atemp.find(':')));
		atemp.erase(0, atemp.find(':') + 1);

		// PRICE
		m_price = stod(atemp.substr(0, atemp.find(":")));
	};
	std::ostream& operator<<(std::ostream& os, const Toy& toy)
	{
		os << "Toy";
		os.width(8);
		os << toy.m_orderId << ":";
		os.width(18);
		os.setf(std::ios::right);
		os << toy.m_name;
		os.unsetf(std::ios::right);
		os.width(3);
		os << toy.m_numItems;
		os << " items";
		os.width(8);
		os << toy.m_price << "/item  subtotal:";
		os.width(7);
		os.setf(std::ios::fixed);
		os.precision(2);
		os << toy.m_numItems * toy.m_price << " tax:";
		os.width(6);
		os << toy.m_numItems * toy.m_price * toy.m_HST;
		os << " total:";
		os.width(7);
		os << (toy.m_numItems * toy.m_price) + (toy.m_numItems * toy.m_price * toy.m_HST) << std::endl;
		return os;
	};
}