// main.cpp
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <thread>
#include "sample.h"
#include "sample.h"
int main() {
	std::string strs[]{ "Ruby", "Emerald", "Sapphire", "Opal" };
	unsigned nums[]{ 18, 20, 30, 40 };
	std::unique_ptr<TreasureBox> tbr(new TreasureBox());     // Compile error, No default constructor. We've created a custom constructor so no default are provide by the compiler
	std::unique_ptr<TreasureBox> ptr(new TreasureBox(strs, nums, 4));
	std::string_view sv = "Ruby";
	std::string s = "Opal";
	ptr->update(sv);   // Compile error, passing a string_view where a string is expected. A string_view is not implicitly coverable to a string.  Fix don't pass string_view/convert to
	ptr->update(s);
	ptr->display();
	*ptr += Gem{ "Diamond", 50 } += Gem{ "Amber", 60 };   // Compile error, No defined opearator for Gem+=
	(*ptr += Gem{ "Pearl", 70 }).display();

	std::promise<unsigned> pro;
	std::future<unsigned> fut = pro.get_future();

	std::thread t1;
	t1.join();
	t1 = std::thread(task, std::ref(pro));
	std::cout << "Promised Future: " << fut.get() << std::endl;
	t1.join();
}


//There are 6 errors in the following code(eg.Compile, Undefined Behavior, Memory Leak, Runtime Crash...).Identify them in the following format :
//
//File, Line Number
//
//Type Of Error
//
//Description of Error
//
//Fix for Error
//
//Make use of the following hints to locate each error :
//
//Error #1 located in sample.h / main.cpp related to the use of redefinitions
// File:      Line Number:
// Type Of ERROR: 
// Header guard needed
// All the stuff get redefined because headers are exclusion
// Fixed with the header guard
//Error #2 located in sample.h / main.cpp related to the use of objects
//Error #3 located in sample.cpp / main.cpp related to the use of types
//Error #4 located in main.cpp related to order of precedence
//Error #5 located in main.cpp related to threading
//Error #6 located in sample.cpp / main.cpp related to the use of shared states