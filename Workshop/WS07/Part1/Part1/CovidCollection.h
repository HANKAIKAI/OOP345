// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

namespace sdds
{
	struct Covid
	{
		std::string m_country;
		std::string m_city;
		std::string m_variant;
		int m_caseNum;
		int m_year;
		int m_deathNum;
	};
	class CovidCollection
	{
		std::vector<Covid> m_covidcollection;
		std::string getField(std::string& str, int length);
	public:
		CovidCollection(std::string filename);
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif // !SDDS_COVIDCOLLECTION_H


