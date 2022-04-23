#include <iostream>
#include <string>
#include <vector>
#include <future>
struct Gem
{
	std::string name{};
	unsigned weight{};

};
class TreasureBox
{
	std::vector<Gem> gems;
	unsigned weight{};
public:
	TreasureBox(const std::string* names, unsigned* weights, unsigned size);
	TreasureBox& operator+=(const Gem& g);
	void update(const std::string& name);
	std::ostream& display() const;

};
void task(std::promise<unsigned>& p);
