// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/01/30
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "ProteinDatabase.h"

namespace sdds {
	ProteinDatabase::ProteinDatabase()
	{
		this->m_elements = nullptr;
		this->m_count = 0;
	}
	
	ProteinDatabase::ProteinDatabase(const char* filename) {
		std::ifstream fin(filename);
		if (fin.is_open())
		{
			while (fin) 
			{
				if (fin.get() == '>') { m_count++; }
			}
			m_elements = new std::string[m_count];
			fin.clear();
			fin.seekg(std::ios::beg);
			int i = -1;
			while(fin)
			{
				char s = fin.get();
				if(s == '>')
				{
					fin.ignore(2000, '\n');
					i++;
				}
				else if(s != '\n' && s != EOF)
				{
					m_elements[i] += s;
				}
			}
		}
		else
		{
			m_elements = nullptr;
			m_count = 0;
		}
		fin.close();
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& proteindatabase)
	{
		this->m_count = proteindatabase.m_count;
		*this = proteindatabase;
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& proteindatabase)
	{
		if (this != &proteindatabase)
		{
			this->m_count = proteindatabase.m_count;
			
			delete[] this->m_elements;
			this->m_elements = nullptr;
			
			if (proteindatabase.m_elements != nullptr)
			{
				m_elements = new std::string[m_count];
				for (unsigned int i = 0; i < m_count; i++)
				{
					m_elements[i] = proteindatabase.m_elements[i];
				}
			}
		}
		return *this;
	}

	ProteinDatabase::~ProteinDatabase()
	{
		delete[] this->m_elements;
		this->m_elements = nullptr;
	}

	size_t ProteinDatabase::size() const { return this->m_count; }

	std::string ProteinDatabase::operator[](size_t index)
	{
		std::string temp;
		if (index >= 0 && index < m_count)
		{
			temp = this->m_elements[index];
		}
		return temp;
	}

	//move constructor
	ProteinDatabase::ProteinDatabase(ProteinDatabase&& proteindatabase) noexcept
	{
		this->m_count = proteindatabase.m_count;
		*this = std::move(proteindatabase);
	}
	//move assignment operator
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& proteindatabase) noexcept
	{
		if (this != &proteindatabase)
		{
			this->m_count = proteindatabase.m_count;
			proteindatabase.m_count = 0;
			delete[] this->m_elements;
			this->m_elements = proteindatabase.m_elements;
			proteindatabase.m_elements = nullptr;
		}
		return *this;
	}
}