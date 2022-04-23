// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/06
// Assignment Part 2 Set.h:  the add() Specailization idea is from Yavuz Alper Yigitoglu
#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include <iostream>
#include <cmath>
#include "Collection.h"

namespace sdds
{
	template<typename T>
	class Set : public Collection<T, 100>
	{
	public:
		virtual bool add(const T& additem) override;
		virtual ~Set() {};
	};

	template<class T>
	bool Set<T>::add(const T& additem) {
		bool res = true;

		for (size_t i = 0; i < Collection<T, 100>::size(); i++) {
			if ((*this)[i] == additem)
				res = false;
		}

		if (Collection<T, 100>::size() < 100 && res) {
			Collection<T, 100>::collection[Collection<T, 100>::size()] = additem;
			Collection<T, 100>::numOfElements++;
			res = true;
		}
		return res;
	};

	template<>
	bool Set<double>::add(const double& additem) {
		bool res = false;

		for (size_t i = 0; i < size(); i++) {
			double diff = collection[i] - additem;
			if (fabs(diff) <= 0.01)
				res = true;
		}
		if (numOfElements < 100 && !res) {
			collection[size()] = additem;
			numOfElements++;
			res = true;
		}
		return res;
	};

}
#endif // !SDDS_SET_H_



