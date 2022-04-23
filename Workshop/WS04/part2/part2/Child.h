// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/12
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include "Toy.h"
namespace sdds 
{
	class Child 
	{
		std::string m_name{""};
		int m_age{0};
		//const sdds::Toy** m_toyArr{nullptr};
		Toy* m_toyArr{nullptr};
		size_t m_numOfToys{0};
	public:
		Child();
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& child);
		Child& operator=(const Child& child);
		Child(Child&& child) noexcept;
		Child& operator=(Child&& child) noexcept;
		size_t size() const;
		~Child();

		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
}
#endif // !SDDS_CHILD_H


