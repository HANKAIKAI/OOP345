// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_JOB_H
#define SDDS_JOB_H
#include <iostream>
namespace sdds
{
	class Job
	{
		std::string m_title{};
		unsigned int m_totalWork{};
		unsigned int m_remainUnit{};
		bool flag;     // determine if the job is active or not
	public:
		Job();
		Job(const std::string& title);
		bool is_active();
		bool is_complete();
		std::string name();
		void display(std::ostream& os = std::cout) const;
		void operator ()(unsigned int handledWork);
	};
	std::ostream& operator<<(std::ostream& os, Job& job);
}
#endif // !SDDS_JOB_H


