// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/01/30
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_
#include <iostream>
namespace sdds {
	class ProteinDatabase {
		std::string* m_elements{ nullptr };
		unsigned int m_count = 0;
	public:
		ProteinDatabase();
		ProteinDatabase(const char* filename);
		ProteinDatabase(const ProteinDatabase& proteindatabase);
		ProteinDatabase& operator=(const ProteinDatabase& proteindatabase);
		~ProteinDatabase();
		size_t size() const;
		std::string operator[](size_t index);
		ProteinDatabase(ProteinDatabase&& proteindatabase) noexcept;  //move constructor
		ProteinDatabase& operator=(ProteinDatabase&& proteindatabase) noexcept;  //move assignment
	};
}
#endif // !SDDS_PROTEINDATABASE_H_