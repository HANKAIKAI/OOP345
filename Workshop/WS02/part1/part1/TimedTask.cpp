// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "TimedTask.h"

namespace sdds {
	TimedTask::TimedTask() { numberOfTask = 0; }
	void TimedTask::startClock() { start_time = std::chrono::steady_clock::now(); }
	void TimedTask::stopClock(){ end_time = std::chrono::steady_clock::now(); }
	void TimedTask::addTask(const char* name)
	{
		auto timeDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
		if (numberOfTask < maxEvents)
		{
			this->tasks[numberOfTask].m_taskName = name;
			this->tasks[numberOfTask].m_units = "nanoseconds";
			this->tasks[numberOfTask].m_duration = timeDuration;
			numberOfTask++;
		}
	}
	std::ostream& operator<<(std::ostream& ostr, const TimedTask& tasks)
	{
		ostr << "--------------------------\n";
		ostr << "Execution Times:\n";
		ostr << "--------------------------\n";
		for (int i = 0; i < tasks.numberOfTask; i++)
		{
			ostr << std::setw(21) << std::left;
			ostr << tasks.tasks[i].m_taskName;
			ostr << ' ' << std::setw(13) << std::right;
			ostr << tasks.tasks[i].m_duration.count() << ' ' << tasks.tasks[i].m_units << std::endl;
		}
		ostr << "--------------------------\n";
		return ostr;
	}
}