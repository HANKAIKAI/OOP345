// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
#include <iostream>
#include <chrono>
namespace sdds {
	const int maxEvents = 10;
	class TimedTask {
		int numberOfTask;
		std::chrono::steady_clock::time_point start_time;
		std::chrono::steady_clock::time_point end_time;

		struct Task
		{
			std::string m_taskName;
			std::string m_units;
			std::chrono::steady_clock::duration m_duration;
		}tasks[maxEvents];
	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* name);
		friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& tasks);
	};
}
#endif // !SDDS_TIMEDTASK_H_




