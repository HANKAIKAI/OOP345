#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

enum class Month
{
	January, February, March, April, May, June, July,
	August, September, October, November, December
};

struct Article
{
	std::string m_title;//title of article
	std::string m_publisherName;//name of publisher
	Month m_publishedMonth;//month of publication
	int m_publishedDay;//day of publication
	int m_publishedHour;//hour of publication
};

std::vector<Article> processArticle()
{

	std::vector<Article> buf;
	// Create a function named processArticle that receives a collection (std::vector)
	// of Article objects and returns a different collection (std::vector)
	// of Article objects. Your function must perform the following tasks
	// on the received collection using C++ standard template library algorithms:
	buf.push_back({ "title1" , "name1" , Month::August , 1 , 13 });
	buf.push_back({ "title2" , "name2" , Month::February , 2 , 14 });
	buf.push_back({ "title3" , "name3" , Month::April , 2 , 15 });
	buf.push_back({ "title4" , "name4" , Month::February , 3 , 15 });
	buf.push_back({ "title5" , "name5" , Month::September , 3 , 16 });
	return buf;
}

int main()
{

	std::vector<Article> buf;
	// Create a function named processArticle that receives a collection (std::vector)
	// of Article objects and returns a different collection (std::vector)
	// of Article objects. Your function must perform the following tasks
	// on the received collection using C++ standard template library algorithms:
	buf = processArticle();


	// 1. Sort only the first half of the Article objects in the collection in descending order based on their hour of publication.
	sort(buf.begin(), buf.end(), [](const Article& a, const Article& b)
		{
			if (a.m_publishedMonth != b.m_publishedMonth)
				return a.m_publishedMonth > b.m_publishedMonth;
			if (a.m_publishedDay != b.m_publishedDay)
				return a.m_publishedDay > b.m_publishedDay;
			return a.m_publishedHour > b.m_publishedHour;
		});
	for (const auto& d : buf)
		cout << "  " << d.m_title << endl;

	//
	// 2. Display each Article objects data from the collection published in the month of March i
	// n the following format: {title text}(Title),
	// {publisher text}(Publisher), {day number}(Day), {hour number}(Hour).
	// Each objects data should be printed on a new line to the standard output stream.
	std::vector<Article> temp = buf;

	auto it2 = remove_if(temp.begin(), temp.end(), [](const Article& c) {
		bool ret = false;
		if (c.m_publishedMonth == Month::March)
		{
			ret = true;
		}
		return ret;
		});
	temp.resize(it2 - temp.begin());

	for (const Article& d : temp)
		cout << "title: " << d.m_title << " ,name: " << d.m_publisherName
		<< ", day: " << d.m_publishedHour << ", hour: " << d.m_publishedHour << endl;

	// 3. Print the number of Article objects that were published in the month of February to the standard output stream.
	auto x = count_if(buf.begin(), buf.end(), [](Article& c) {
		return c.m_publishedMonth == Month::February;
		});
	cout << "GPU COUNT: " << x << endl;

	// 4. Transform all the Article objects in the received collection by appending the publishers name (within brackets) to the corresponding title. Example, if title is Five reasons why Ontario and publisher name is CTV News, then the title of the transformed object becomes Five reasons why Ontario (CTV News). Store the transformed objects in a newly created collection (std::vector). Your function returns this collection after processing in the next task.
	vector<Article> usedlist(buf.size());
	transform(buf.begin(), buf.end(), usedlist.begin(), [](Article& c) {
		if (c.m_publisherName == "CTV")
			c.m_title = "CTV News";
		return c;
		});
	return 0;
}
