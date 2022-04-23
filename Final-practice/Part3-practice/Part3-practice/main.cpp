#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct ComputerParts{
	string partType;
	string model;
	double price;
	double powerConsumption;
	bool used;
};

int main() {

	vector<ComputerParts> wishList;

//Task 1. Add to the wishLish some number of desired Computer Parts
//Eg.GPU, RTX 3080, 1000, 300, false
	ComputerParts p1{ "CPU", "Intel 10900k", 700, 250, false };
	ComputerParts p2{ "GPU", "AMD 6800", 800, 300, false };
	ComputerParts p3{ "PSU", "Corsair SF750", 200, 750, true };
	ComputerParts p4{ "RAM", "Gskill 32GB", 150, 60, true };
	wishList.push_back(p1);
	wishList.push_back(p2);
	wishList.push_back(p3);
	wishList.push_back(p4);

//Task 2. Sort the wishList by price in ascending order
	sort(wishList.begin(), wishList.end(), [](const ComputerParts& a, const ComputerParts& b) {
		return a.price < b.price;
	});

	for (auto& x : wishList){
		cout << x.model << ":" << x.price << endl;
	}
	cout << "******************************************" << endl;

//Task 3. Print to the screen the part in the wishList the part that has the most and least powerConsumption
	/*sort(wishList.begin(), wishList.end(), [](const ComputerParts& a, const ComputerParts& b) {
		return a.powerConsumption < b.powerConsumption;
		});*/

	auto maxpow = max_element(wishList.begin(), wishList.end(), [](const ComputerParts& a, const ComputerParts& b) {
		return a.powerConsumption < b.powerConsumption;
		});
	auto minpow = min_element(wishList.begin(), wishList.end(), [](const ComputerParts& a, const ComputerParts& b) {
		return a.powerConsumption < b.powerConsumption;
		});
	
	// first element is now the least power
	/*cout << wishList.front().model << ":" << wishList.front().powerConsumption << endl;
	cout << wishList.back().model << ":" << wishList.back().powerConsumption << endl;*/
	/*cout << (*maxpow).model << ":" << (*maxpow).powerConsumption << endl;
	cout << (*minpow).model << ":" << (*minpow).powerConsumption << endl;*/
	// last element is now the most power

//Task 4. Remove from the wishList all the parts that are 'used'
	auto itr = remove_if(wishList.begin(), wishList.end(), [](const ComputerParts& c) {
		bool ret = false;
		if (c.used){
			ret = true;
		}
		return ret;
	});

	wishList.resize(itr - wishList.begin());

	for (auto& x : wishList){
		cout << x.model << " " << x.partType << " " << x.price << endl;
	}
//Task 5. Find the average cost of all the parts in the wishList
	double sum = accumulate(wishList.begin(), wishList.end(), 0.0, [](double& sum, const ComputerParts& c) {
		return sum += c.price;
	});

	cout << sum << endl;
	cout << sum / wishList.size() << endl;
//Task 6. Change all the items in the wishList to 'used' and reduce their price by 20 % andsave this result to a new vector
	vector<ComputerParts> usedlist(wishList.size());
	transform(wishList.begin(), wishList.end(), usedlist.begin(), [](ComputerParts& c) {
		c.price *= 0.8;
		c.used = true;
		return c;
	});

	for (auto& x : usedlist){
		cout << x.model << " : " << x.price << " " << x.used << endl;
	}
//Task 7. Figure out how many of a given part type is in the wishList eg.how many CPUs and print to the screen
	auto x = count_if(wishList.begin(), wishList.end(), [](ComputerParts& c) {
		return c.partType == "GPU";
	});
	cout << "GPU COUNT: " << x << endl;
//Task 8. Create new wishList of computer parts and add parts to it.Combine it with the original wishList
}



