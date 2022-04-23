// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/12
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Child.h"

namespace sdds 
{
	Child::Child(){}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
	{
		if (toys != nullptr)
		{
			m_numOfToys = count;
			m_toyArr = new Toy[m_numOfToys];
			for (size_t i = 0; i < m_numOfToys; i++) { m_toyArr[i] = *toys[i]; };
			m_name = name;
			m_age = age;
		}
	}

	Child::Child(const Child& child){ *this = child; }

	Child& Child::operator=(const Child& child)
	{
		if (this != & child)
		{
			delete[] m_toyArr;
			m_toyArr = nullptr;
			m_numOfToys = child.m_numOfToys;
			m_toyArr = new Toy[m_numOfToys];
			for (size_t i = 0; i < m_numOfToys; i++)
			{
				m_toyArr[i] = child.m_toyArr[i];
			}
			m_name = child.m_name;
			m_age = child.m_age;
		}
		return *this;
	}

	Child::Child(Child&& child) noexcept
	{
		*this = std::move(child);
	}

	Child& Child::operator=(Child&& child) noexcept
	{
		if (this != &child)
		{
			delete[] m_toyArr;
			m_toyArr = nullptr;
			m_toyArr = child.m_toyArr;
			child.m_toyArr = nullptr;
			m_name = child.m_name;
			child.m_name = "";
			m_age = child.m_age;
			child.m_age = 0;
			m_numOfToys = child.m_numOfToys;
			child.m_numOfToys = 0;
		}
		return *this;
	}

	size_t Child::size() const{ return m_numOfToys; }

	Child::~Child()
	{
		delete[] m_toyArr;
		m_toyArr = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const Child& child) 
	{
		static size_t CALL_CNT = 0;
		CALL_CNT++;

		os << "--------------------------" << std::endl;
		os << "Child " << CALL_CNT << ": " << child.m_name << " " << child.m_age << " years old:" << std::endl;
		os << "--------------------------" << std::endl;
		if (child.size() == 0)
		{
			os << "This child has no toys!" << std::endl;
		}
		else 
		{
			for (size_t i = 0; i < child.size(); i++)
			{
				os << child.m_toyArr[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
