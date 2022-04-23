// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/12
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "ConfirmOrder.h"
namespace sdds
{
	ConfirmOrder::ConfirmOrder(){}
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& confirm){ *this = confirm; }
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& confirm)
	{
		if (this != &confirm)
		{
			if (m_ToyArr)
			{
				delete[] m_ToyArr;
				m_ToyArr = nullptr;
			}
			m_resnum = confirm.m_resnum;
			m_ToyArr = new const Toy * [m_resnum];
			for (size_t i = 0; i < m_resnum; i++)
			{
				m_ToyArr[i] = confirm.m_ToyArr[i];
			}
		}
		return *this;
	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& confirm) noexcept{ *this = std::move(confirm); }

	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& confirm) noexcept
	{
		if (this != &confirm)
		{
			if (m_ToyArr)
			{
				delete[] m_ToyArr;
				m_ToyArr = nullptr;
			}
			
			m_ToyArr = confirm.m_ToyArr;
			confirm.m_ToyArr = nullptr;
			m_resnum = confirm.m_resnum;
			confirm.m_resnum = 0;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		bool exist = false;
		for (size_t i = 0; i < m_resnum && !exist; i++)
		{
			if (&toy == m_ToyArr[i]) { exist = true; };
		}
		if (!exist)
		{
			const Toy** temp = new const Toy * [m_resnum + 1];
			for (size_t i = 0; i < m_resnum; i++)
			{
				temp[i] = m_ToyArr[i];
			}
			temp[m_resnum] = &toy;
			m_resnum++;
			delete[] m_ToyArr;
			m_ToyArr = temp;
		}
		return *this;
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool exist = false;
		for (size_t i = 0; i < m_resnum && !exist; i++)
		{
			if (&toy == m_ToyArr[i])
			{
				m_ToyArr[i] = nullptr;
				exist = true;
				m_resnum--;
			}
		}
		return *this;
	}
	ConfirmOrder::~ConfirmOrder()
	{
		/*delete[] m_ToyArr;
		m_ToyArr = nullptr; */
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& confirm)
	{
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (confirm.m_resnum == 0)
		{
			os << "There are no confirmations to send!" << std::endl;
		}
		else 
		{
			for (size_t i = 0; i < confirm.m_resnum; i++)
			{
				if (confirm.m_ToyArr[i] != nullptr)
				{
					os << *confirm.m_ToyArr[i];
				}
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
