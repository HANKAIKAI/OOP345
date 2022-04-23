// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/02/06
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include <iostream>
namespace sdds
{
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		const std::string& getKey() const {
			return m_key;
		}
		const std::string& getValue() const {
			return m_value;
		}
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};

		// TODO: Add here the missing the prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.

		// Need 1. default constructer, 2. an insert operator(output a pair or any Function need to ouput a pair) 3. boolean operator==
		Pair() :m_key{}, m_value{} {};
		bool operator==(const Pair&) const;
		friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
	};
}
#endif // !SDDS_PAIR_H_
