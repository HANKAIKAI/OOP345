// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/06
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "Pair.h"
namespace sdds
{
	std::ostream& operator<<(std::ostream& os, const Pair& pair)
	{
		os.width(20);
		os.setf(std::ios::right);
		os << pair.getKey();
		os << ": ";
		os << pair.getValue();
		os.unsetf(std::ios::right);
		return os;
	}
	bool Pair::operator==(const Pair& pair) const
	{
		return getKey() == pair.getKey();
	}
}