// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CENTRALUNIT_H
#define SDDS_CENTRALUNIT_H
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "Job.h"
namespace sdds
{
	const size_t MAXOFJOB = 4;  // Only a maximum of 4 jobs can be queued up at any given time

	template<typename T>
	class CentralUnit
	{
		std::string m_type{};
		T** m_items{};         // These are the units that will be hosted in the CentralUnit object.
		Job* m_jobs[MAXOFJOB];
		size_t m_size{};       // stores the number of individual units hosted by the central unit
		size_t m_count{};      // stores the number of jobs queued up and waiting to be handled  NO MORE THEN 4   
	public:
		std::ostream& log = std::cout;
		CentralUnit();
		CentralUnit(const std::string& type, const char* filename);

		// This design does not support copy operations
		CentralUnit<T>(const CentralUnit<T>& C);
		CentralUnit<T>& operator=(const CentralUnit<T>& C) = delete;

		CentralUnit(CentralUnit<T>&& C);
		CentralUnit<T>& operator=(CentralUnit<T>&& C);
		CentralUnit<T>& operator+=(std::string jobName);
		~CentralUnit();

		void run();  // not sure
		bool has_jobs() const;
		size_t get_available_units() const;
	};

	template<typename T>
	CentralUnit<T>::CentralUnit() {}

	template<typename T>
	CentralUnit<T>::CentralUnit(const std::string& type, const char* filename) {
		std::string unitType{};
		std::string unitName{};
		std::string workCapacity{};

		std::ifstream file(filename);
		if (file.is_open())
		{
			if (m_items != nullptr)
			{
				delete m_items;
				m_items = nullptr;
			}

			m_type = type;
			std::string temp;
			while (!file.eof())
			{
				std::getline(file, temp, '\n'); // reads the file to count the number of each line present in the file. 
				m_size++;
			}

			m_items = new T * [m_size];

			file.clear();
			file.seekg(std::ios::beg);     // back to start

			int tmp{};

			while (!file.eof())
			{
				char ch;
				file >> unitType >> ch >> unitName >> ch;
				std::getline(file, workCapacity, '\n');

				size_t a;
				try {
					a = std::stoi(workCapacity);
				}
				catch (...) {
					a = 1;
				}
				//size_t newitem{};
				m_items[tmp++] = new T(this, unitType, unitName, a);   // this (it is pointer of CentralUnit)

			}
		}
		else
			throw std::invalid_argument("File cannot be opened.");

		file.close();
	}

	template<typename T>
	CentralUnit<T>::CentralUnit(const CentralUnit<T>& C) {
		throw std::string("We cannot copy an object in copy constructor!!!");
	}

	template<typename T>
	CentralUnit<T>::CentralUnit(CentralUnit<T>&& C) {
		*this = move(C);
	}

	template<typename T>
	CentralUnit<T>& CentralUnit<T>::operator=(CentralUnit<T>&& C) {
		if (this != &C)
		{
			for (auto i = 0; i < m_size; i++)
			{
				delete m_items[i];
				m_items[i] = nullptr;
			}
			delete[] m_items;
			m_items = nullptr;
			m_items = C.m_items;
			C.m_items = nullptr;

			m_type = C.m_type;

			m_jobs = C.m_jobs;
			C.m_jobs = nullptr;
			m_size = C.m_size;
			m_count = C.m_count;
		}
		return *this;
	}

	template<typename T>
	CentralUnit<T>& CentralUnit<T>::operator+=(std::string jobName) {
		if (m_count >= MAXOFJOB)
		{
			throw std::string("It's full!");
		}
		else
		{
			Job* job = new Job(jobName);
			m_jobs[m_count] = job;    // m_jobs[m_count++] = job;
			m_count++;
			job = nullptr;
		}
		return *this;     // returns a reference to the current central unit.
	}

	template<typename T>
	void CentralUnit<T>::run() {
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_count > 0 && !*m_items[i]) {
				// remove the last job from the queue and assign it to the unit before running the unit
				//*m_item[i] = m_job[--m_count];
				*m_items[i] += m_jobs[--m_count];
				m_jobs[m_count] = nullptr;
			}
			// TODO
			m_items[i]->run();
		}
	}

	template<typename T>
	bool CentralUnit<T>::has_jobs() const {
		if (m_count != 0)
			return true;

		for (size_t i = 0; i < m_size; ++i)
			if (*m_items[i])
				return true;

		return false;
	}

	template<typename T>
	size_t CentralUnit<T>::get_available_units() const {
		int ret = 0;
		for (size_t i = 0; i < m_size; ++i)
			if (!*m_items[i])
				ret++;
		return ret;
	}

	template<typename T>
	CentralUnit<T>::~CentralUnit() {
		for (unsigned int i = 0; i < m_size; i++)
		{
			delete m_items[i];
			m_items[i] = nullptr;
		}
		delete[] m_items;
		m_items = nullptr;
		for (size_t i = 0; i < m_count; ++i) delete m_jobs[i];
	}
}
#endif // !SDDS_CENTRALUNIT_H

