// Name: Yuan - Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Processor.h"
#include <exception>

namespace sdds
{
	Processor::Processor(CentralUnit<Processor>* host, std::string brand, std::string code, size_t power)
	{
		m_host = host;
		m_brand = brand;
		m_code = code;
		m_power = power;
	}
	void Processor::run()
	{
		try
		{
			if (m_current != nullptr)
			{
				if (m_current->is_complete())
				{
					delete m_current;
					m_current = nullptr;
				}
				else
				{
					(*m_current)(m_power);
				}
			}
		}
		catch (std::underflow_error&)
		{
			//std::cout << "Processed over quota for " << m_current->name() << std::endl;  // not finish
			std::cout << "Processed over quota for " << *m_current;
			delete m_current;
			m_current = nullptr;
		}

	}
	Processor::operator bool() const
	{
		return m_current ? true : false;
	}
	Processor& Processor::operator+=(Job*& job)
	{
		if (m_current == nullptr)
			m_current = job;
		else
			throw std::string("Have a job!");
		return *this;
	}
	Job* Processor::get_current_job() const
	{
		return m_current;
	}
}