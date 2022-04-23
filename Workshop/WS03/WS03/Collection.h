// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/06
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_
#include <iostream>
#include "Pair.h"
namespace sdds
{
	template<typename T, size_t CAPACITY>
	class Collection
	{
	protected:
		size_t numOfElements{ 0 };
		T collection[CAPACITY]{};
		T dummy{};
	public:
		Collection();
		size_t size();
		std::ostream& display(std::ostream& os = std::cout) const;
		virtual bool add(const T& item);
		T& operator[](size_t index);
		virtual ~Collection() {};
	};
	template<class T, size_t CAPACITY>
	Collection<T, CAPACITY>::Collection() {};

	template<typename T, size_t CAPACITY>
	size_t Collection<T, CAPACITY>::size()
	{
		return numOfElements;
	};

	template<typename T, size_t CAPACITY>
	std::ostream& Collection<T, CAPACITY>::display(std::ostream& os) const
	{
		os << "----------------------" << std::endl;
		os << "| Collection Content |" << std::endl;
		os << "----------------------" << std::endl;
		for (size_t i = 0; i < numOfElements; i++)
		{
			os << collection[i] << std::endl;
		}
		os << "----------------------" << std::endl;
		return os;
	};

	template<typename T, size_t CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item)
	{
		bool res = false;
		if (size() < CAPACITY)
		{
			collection[size()] = item;
			numOfElements++;
			res = true;
		}
		return res;
	};

	template<typename T, size_t CAPACITY>
	T& Collection<T, CAPACITY>::operator[](size_t index)
	{
		return (index >= 0 && index < size()) ? collection[index] : dummy;
	};

	template<>
	Collection<Pair, 100>::Collection()
	{
		dummy = Pair("No Key", "No Value");
	}
}
#endif // !SDDS_COLLECTION_H_


