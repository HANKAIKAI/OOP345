#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds
{
	template<typename T>
	class GeneratingList
	{

		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const {
			return list.size();
		}
		const T& operator[](size_t i) const {
			return list[i];
		}

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's

		bool checkLuhn(const std::string& str) {

			// 1. get the length of the str::string - length()
			// 2. define a sum variable to sum things up
			// 3. we need a variable to determine parity (meaning when we double the digits)
			// 4. loop against all the digits (loop all the digits starting from the second last one) in the str 
			// loop from last digit (right hand side) tillthe first digit (left hand site)
			// - if a given digits is in the 'even' digits from starting from the right then double it
			//   - using division by 10 and mod 10, you can get thetwo digits 18 / 10 = 1, 18 % 10 = 8
			//   - 9 / 10 = 0, 9 % 10 = 9
			//   - sum the division by 10 and mod 10 values to yoursum
			// - sum all the digits in the sum variable defined earlier
			// 5. Return the result of (sum % 10 == 0)
			int nDigits = str.length();
			int nSum = 0, isSecond = false;
			for (int i = nDigits - 1; i >= 0; i--)
			{
				int d = str[i] - '0';
				if (isSecond == true) {
					d = d * 2;
				}

				nSum += d / 10;
				nSum += d % 10;

				isSecond = !isSecond;
			}
			return (nSum % 10 == 0);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T* row) {
			list.push_back(*row);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
