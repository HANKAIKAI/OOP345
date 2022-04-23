// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PROCESSOR_H
#define SDDS_PROCESSOR_H
#include "CentralUnit.h"
#include "Job.h"
namespace sdds
{

	class Processor
	{
		CentralUnit<Processor>* m_host{};     // sdds::CentralUnit<sdds::Processor>* cpu
		std::string m_brand{};
		std::string m_code{};
		unsigned int m_power{};         // representing the unit's work capacity
		Job* m_current{};

		////part2
		//void (*m_funcptr)(CentralUnit<Processor>&, Processor*);
		//CentralUnit<void(int, int)> targets;
	public:
		Processor(CentralUnit<Processor>* host, std::string brand, std::string code, size_t power);
		void run();
		explicit operator bool() const;
		Processor& operator+=(Job*& job);
		Job* get_current_job() const;

		////part2
		//on_complete(*m_host, this);

		//free();
	};
}
#endif // !SDDS_PROCESSOR_H


