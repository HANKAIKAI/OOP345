// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date:
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "ProteinDatabase.h"
using namespace std;

namespace sdds {
	ProteinDatabase::ProteinDatabase()
	{
		this->m_elements = nullptr;
		this->m_count = 0;
	}
	/*ProteinDatabase::ProteinDatabase(const std::string& fname)
	{
		m_count = 0;
		std::ifstream fin(fname);
		std::string fstring;

		if (fin.is_open())
		{
			
			while (fin)
			{
				if (fin.get() == '>')
				{
					m_count++;
				}
			}

			m_elements = new std::string[m_count];
			fin.clear();
			fin.seekg(0);
			for (unsigned int i = 0; i < m_count; i++)
			{
				if (fin.get() == '>')
				{
					fin.ignore(131, '\n');
					std::getline(fstring, 80);
				}
				getline(fin, m_elements[i]);
			}
			fin.close();
		}
	}*/
	ProteinDatabase::ProteinDatabase(const char* file) {
		fstream f(file, ios::in);
		if (f) {
			while (f)
			{
				if (f.get() == '>') {
					m_count++;
				}
			}
			m_elements = new string[m_count];
			f.clear();
			f.seekp(ios::beg);
			char temp[80] = "";
			int i = 0;
			while (f) {
				if (f.get() == '>') {
					f.ignore(2000, '\n');
					f.get(temp, 80);
					m_elements[i] = temp;
					i++;
				}
			}
		}
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
			if (this->m_elements != nullptr)
			{
				delete[] this->m_elements;
				this->m_elements = nullptr;
			}
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

	size_t ProteinDatabase::size() const{ return m_count;}

	std::string ProteinDatabase::operator[](size_t index)
	{
		std::string temp;
		if (index >= 0 && index < m_count)
		{
			temp = m_elements[index];
		}
		return temp;
	}

}