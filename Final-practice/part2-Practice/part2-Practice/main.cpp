#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <thread>
#include <vector>
using namespace std;

struct Gem{
	string name;
	string colour;
	int shine;
	bool polished;
};

class Box{
//An STL container of Gems as a data member
	vector<Gem> gems;

//A += operator that adds Gems to the box
public:
	Box& operator+=(const Gem& g) {
		gems.push_back(g);
		return *this;
	}

//A -= operator that removes Gems from the Box based on a given string(name) to search for.
//If the string is found then remove any Gems that match.
//If there isn’t a match at all then throw an exception of string type with a relevant error message
	Box& operator-=(const string& name) {
		int currentSize = gems.size();

		// return iterator, that is the new end of the sequence.
		// 1, 2, 3, 4, 5 end
		// 1, 2, 3, end, ?, ?
		auto itr = remove_if(gems.begin(), gems.end(), [name](const Gem& g) {   // need to capture [name]
			return g.name == name;
		});

		gems.resize(itr - gems.begin());

		if (currentSize == gems.size()){
			string err = "Could not rmove" + name + "because it was not in the box";
			throw err;
		}
	}

// A function called process that doesn’t receive any parameters nor returns any value.
//This function will iterate through the Gems in the Boxand polish them if they aren’t yet polished.
//Polishing a Gem will cause its shine value to increase by 20. 
//For this functionality incorporate the use of threads to divide the work.
	void process() {
		// task for thread
		auto polish = [](vector<Gem>::iterator begin, vector<Gem>::iterator end) {
			for (auto x = begin; x != end; x++) {
				if (!(*x).polished) {
					(*x).polished = true;
					(*x).shine += 20;
				}
			}
		};
		/*for (auto& x : gems){
			if (!x.polished){
				x.polished = true;
				x.shine += 20;
			}
		}*/

		auto start = gems.begin();
		auto half = gems.begin() + gems.size() / 2;
		auto end = gems.end();

		thread t1(polish, start, half);
		thread t2(polish, start, end);

		t1.join();
		t2.join();
	}

//A display function that displays the contents of the box
	void display() const {
		for_each (gems.begin(), gems.end(), [](const Gem& g) {
			cout << "Gem Name: " << g.name << endl;
			cout << "Gem Colour: " << g.colour << endl;
			cout << "Gem Polish: " << g.polished << endl;
			cout << "Gem Shine: " << g.shine << endl;
		});
	}
};

int main() {
	Box b;

	cout << "\nAdding Gems" << endl;
	b += Gem{ "Emerald", "Green", 20, false };
	b += Gem{ "Ruby", "Red", 50, true };
	b += Gem{ "Sapphire", "Blue", 80, false };
	b += Gem{ "Onyx", "Black", 60, false };
	b += Gem{ "Opal", "White", 10, false };
	b.display();

	cout << "\nRemoving Gems" << endl;
	try {
		b -= "Ruby";
		b -= "Emerald";
		b -= "Diamond";
		b.display();
	}
	catch (string c) {
		cout << c << endl;
	}

	cout << "\nPolishing Gems" << endl;
	b.process();
	b.display();


	cout << "\nVector of Boxes" << endl;
	vector<Box*> boxes;
	boxes.push_back(new Box());
	boxes.push_back(new Box());
	boxes.push_back(new Box());

	for (auto x : boxes) {
		x->operator+=(Gem{ "Emerald", "Green", 20, false });
		x->operator+=(Gem{ "Ruby", "Red", 90, false });
		x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
	}

	for (auto x : boxes) {
		delete x;
	}
}