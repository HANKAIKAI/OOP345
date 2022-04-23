// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/03/16
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
		std::ifstream file(filename);        // cannot work on VS but work on Matrix
		if (!file)
			throw "ERROR: CANNOT OPEN THE FILE!\n";
		else
		{
			while (file) {
				std::string temp;
				std::getline(file, temp, '\n');
				if (!temp.empty())
				{
					Covid covid;

					covid.m_country = getField(temp, 25);
					covid.m_city = getField(temp, 25);
					covid.m_variant = getField(temp, 25);
					covid.m_year = std::stoi(getField(temp, 5));
					covid.m_caseNum = std::stoi(getField(temp, 5));
					covid.m_deaths = std::stoi(getField(temp, 5));

					m_covidcollection.push_back(covid);
				}
			}
			file.close();
		}

		/*std::ifstream file(filename);
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
				covid.m_deaths = std::stoi(getField(temp, 5));

				m_covidcollection.push_back(covid);
			}
		}
		else
			throw "ERROR: CANNOT OPEN THE FILE!\n";
		file.close();*/
	}
	void CovidCollection::display(std::ostream& out) const  // for_each accumulate
	{
		std::for_each(m_covidcollection.begin(), m_covidcollection.end(), [&](const Covid& covid) { out << covid << std::endl; });

		int casetotal = std::accumulate(m_covidcollection.begin(), m_covidcollection.end(), 0, [](int sum, const Covid& covid) {
			return sum + covid.m_caseNum;
			});
		int deathstotal = std::accumulate(m_covidcollection.begin(), m_covidcollection.end(), 0, [](int sum, const Covid& covid) {
			return sum + covid.m_deaths;
			});

		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| " << std::setw(79) << std::right << "Total Cases Around the World:  " << casetotal << " |" << std::endl;
		out << "| " << std::setw(79) << std::right << "Total Deaths Around the World:  " << deathstotal << " |" << std::endl;
	}
	void CovidCollection::sort(std::string sortBy)
	{
		if (sortBy == "country")
		{
			std::sort(m_covidcollection.begin(), m_covidcollection.end(), [](Covid c1, Covid c2) {
				return c1.m_country < c2.m_country;
				});
		}
		else if (sortBy == "variant")
		{
			std::sort(m_covidcollection.begin(), m_covidcollection.end(), [](Covid c1, Covid c2) {
				return c1.m_variant < c2.m_variant;
				});
		}
		else if (sortBy == "cases")
		{
			std::sort(m_covidcollection.begin(), m_covidcollection.end(), [](Covid c1, Covid c2) {
				return c1.m_caseNum < c2.m_caseNum;
				});
		}
		else if (sortBy == "deaths")
		{
			std::sort(m_covidcollection.begin(), m_covidcollection.end(), [](Covid c1, Covid c2) {
				return c1.m_deaths < c2.m_deaths;
				});
		}
		else
			throw "ERROR: INVALID VALUE.\n";
	}
	void CovidCollection::cleanList()
	{
		std::transform(m_covidcollection.begin(), m_covidcollection.end(), m_covidcollection.begin(), [=](Covid covid) {
			if (covid.m_variant == "[None]")
				covid.m_variant = "";
			return covid;
			});
	}
	bool CovidCollection::inCollection(std::string variant) const
	{
		return std::any_of(m_covidcollection.begin(), m_covidcollection.end(), [variant](Covid covid) {
			return covid.m_variant == variant;
			});
	}
	std::list<Covid> CovidCollection::getListForCountry(std::string country) const
	{
		auto count = std::count_if(m_covidcollection.begin(), m_covidcollection.end(), [country](const Covid covid) {
			return country == covid.m_country;
			});

		std::list<Covid> collection(count);

		copy_if(m_covidcollection.begin(), m_covidcollection.end(), collection.begin(), [country](const Covid covid) {
			return country == covid.m_country;
			});
		return collection;
	}
	std::list<Covid> CovidCollection::getListForVariant(std::string variant) const
	{
		auto count = std::count_if(m_covidcollection.begin(), m_covidcollection.end(), [variant](const Covid covid) {
			return variant == covid.m_variant;
			});

		std::list<Covid> collection(count);

		copy_if(m_covidcollection.begin(), m_covidcollection.end(), collection.begin(), [variant](const Covid covid) {
			return variant == covid.m_variant;
			});
		return collection;
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid)
	{
		out << "| " << std::left << std::setw(21) << theCovid.m_country
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
		out << " | " << std::right << std::setw(3) << std::setfill(' ') << theCovid.m_deaths << " |";
		return out;
	}
}