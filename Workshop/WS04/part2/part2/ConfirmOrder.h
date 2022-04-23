// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/12
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONFIRMORDER_H
#define SDDS_CONFIRMORDER_H
#include "Toy.h"
namespace sdds 
{
	class ConfirmOrder
	{
		const Toy** m_ToyArr{nullptr};
		size_t m_resnum{0};
	public:
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& confirm);
		ConfirmOrder& operator=(const ConfirmOrder& confirm);
		ConfirmOrder(ConfirmOrder&& confirm) noexcept;
		ConfirmOrder& operator=(ConfirmOrder&& confirm) noexcept;
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);
		~ConfirmOrder();
		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& confirm);
	};
}
#endif // !SDDS_CONFIRMORDER_H

