// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "CovidCollection.h"

namespace sdds
{
	std::string CovidCollection::getField(std::string& str, int length)
	{
		std::string field = "";
		field = str.substr(0, length);
		field.erase(0, field.find_first_not_of(" "));
		field.erase(field.find_last_not_of(" ") + 1);
		str = str.erase(0, length);
		return field;
	}
	CovidCollection::CovidCollection(std::string filename)
	{
		std::ifstream file(filename);
		if (file.is_open())
		{
			while (!file.eof()) {
				std::string temp;
				std::getline(file, temp, '\n');
				Covid covid;

				covid.m_country = getField(temp, 25);
				covid.m_city = getField(temp, 25);
				covid.m_variant = getField(temp, 25);
				covid.m_year = std::stoi(getField(temp, 5));
				covid.m_caseNum = std::stoi(getField(temp, 5));
				covid.m_deathNum = std::stoi(getField(temp, 5));

				m_covidcollection.push_back(covid);
			}
		}
		else
			throw "ERROR: CANNOT OPEN THE FILE!\n";
		file.close();
		/*std::ifstream file(filename);
		if (!file)
			throw "ERROR: CANNOT OPEN THE FILE!\n";
		else {
			while (file) {
				std::string temp;
				std::getline(file, temp, '\n');
				Covid covid;

				covid.m_country = getField(temp, 25);
				covid.m_city = getField(temp, 25);
				covid.m_variant = getField(temp, 25);
				covid.m_year = std::stoi(getField(temp, 5));
				covid.m_caseNum = std::stoi(getField(temp, 5));
				covid.m_deathNum = std::stoi(getField(temp, 5));

				m_covidcollection.push_back(covid);
			}
		}
		file.close();*/

	}
	void CovidCollection::display(std::ostream& out) const
	{
		std::for_each(m_covidcollection.begin(), m_covidcollection.end(), [&](const Covid& covid) { out << covid << std::endl; });
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		out << "| " << std::left << std::setw(20) << theCovid.m_country
			<< " | " << std::setw(15) << theCovid.m_city
			<< " | " << std::setw(20) << theCovid.m_variant;
		if (theCovid.m_year > 0)
		{
			out << " | " << std::right << std::setw(6) << theCovid.m_year;
		}
		else
		{
			out << " | " << std::right << std::setw(6) << " ";
		}
		out << " | " << std::right << std::setw(4) << std::setfill(' ') << theCovid.m_caseNum;
		out << " | " << std::right << std::setw(3) << std::setfill(' ') << theCovid.m_deathNum << " |";
		return out;
	}
}