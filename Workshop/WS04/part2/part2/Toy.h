// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/12
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TOY_H_
#define SDDS_TOY_H_
#include <iostream>
#include <string>

namespace sdds
{
	class Toy
	{
		std::string m_orderId{};
		std::string m_name{};
		int m_numItems{ 0 };
		double m_price{ 0.0 };
		double m_HST{ 0.13 };
	public:
		Toy();
		void update(int numItems);
		Toy(const std::string& toy);
		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};
}
#endif // !SDDS_TOY_H_