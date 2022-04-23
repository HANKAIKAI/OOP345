// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Job.h"
namespace sdds
{
	Job::Job() : flag{ false } {}
	Job::Job(const std::string& title) : m_title{ title } {
		m_totalWork = title.length() % 10 + 1;
		m_remainUnit = title.length() % 10 + 1;
	}
	bool Job::is_active() {
		return flag;
	}
	bool Job::is_complete() {
		return m_remainUnit == 0;  // job is done
	}
	std::string Job::name() {
		return m_title;
	}
	void Job::display(std::ostream& os) const {
		// output looks like `JOB NAME` [XX/XX remaining]
		os << "`" << m_title << "`" << " ";
		os << "[";
		os.width(2);
		os.fill('0');
		os << m_remainUnit;
		os << "/";
		os.width(2);
		os.fill('0');
		os << m_totalWork;
		os << " ";
		os << "remaining]";
		os << std::endl;
	}
	void Job::operator ()(unsigned int handledWork) {   // a functor
		if (m_remainUnit >= handledWork)
			m_remainUnit -= handledWork;
		else if (handledWork > m_remainUnit)
		{
			m_remainUnit = 0;
			throw std::underflow_error("UNDERFLOW ERROR");
		}
		flag = m_remainUnit != 0;
	}
	std::ostream& operator<<(std::ostream& os, Job& job) {
		job.display(os);
		return os;
	}
}