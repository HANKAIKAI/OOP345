// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/03/13
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Filesystem.h"
#include <fstream>

namespace sdds
{
	sdds::Filesystem::Filesystem(std::string fileName, std::string rootName)
	{

		m_root = new Directory();
		m_current = new Directory();

		std::ifstream file(fileName);
		if (file.is_open())
		{

		}
		else
			throw std::invalid_argument("File cannot be opened.");
		file.close();
	}

	Filesystem& sdds::Filesystem::operator+=(Resource* src)
	{
		m_current->operator+=(src);
		return *this;
	}
	Directory* Filesystem::change_directory(const std::string& dirname)
	{
		if (dirname.empty())
			m_current = m_root;
		else
		{
			m_current = dynamic_cast<Directory*>(m_current->find(dirname));
			if (m_current == nullptr)
				throw std::invalid_argument("Cannot change directory! " + dirname + " not found!");
		}
		return m_current;
	}
	Directory* Filesystem::get_current_directory() const
	{
		return m_current;
	}
	Filesystem::Filesystem(Filesystem&& src) noexcept
	{
		*this = std::move(src);
	}
	Filesystem& Filesystem::operator=(Filesystem&& src) noexcept
	{
		if (this != &src)
		{
			delete m_current;
			m_current = src.m_current;
			delete m_root;
			m_root = src.m_root;
			src.m_current = nullptr;
			src.m_root = nullptr;
		}
		return *this;
	}
	Filesystem::~Filesystem()
	{
		delete m_root;
		m_root = nullptr;
	}
}
