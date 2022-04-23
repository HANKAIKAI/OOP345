// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <string>
#include "Directory.h"

namespace sdds
{
	Directory::Directory(std::string drcName)
	{
		m_name = drcName;
	}
	void Directory::update_parent_path(const std::string& parent_path)
	{
		//m_parent_path = parent_path;
		//if vector m_contents has File or Directory, you want to loop through all of items(vector) and sets there path to whatever this fall absolute path is of current directory
		for (std::vector<Resource*>::iterator i = m_contents.begin(); i != m_contents.end(); i++)
		{
			if (!m_contents.empty())
				m_parent_path = parent_path;
		}
	}
	NodeType Directory::type() const
	{
		return NodeType::DIR;
	}
	std::string Directory::path() const
	{
		return m_parent_path + m_name;
	}
	std::string Directory::name() const
	{
		return m_name;
	}
	int Directory::count() const
	{
		return m_contents.size();
	}
	size_t Directory::size() const
	{
		size_t sum{ 0u };
		if (!m_contents.empty())
		{
			for (size_t i = 0; i < m_contents.size(); i++)
				sum += m_contents[i]->size();
		}
		return sum;
	}
	Directory& Directory::operator+=(Resource* src)   // got some problem
	{
		for (size_t i = 0; i < m_contents.size(); i++)
		{
			if (m_contents[i]->name() == src->name())
				throw "A match was found!";
		}
		src->update_parent_path(m_parent_path + m_name);
		m_contents.push_back(src);
		return *this;
	}
	Resource* Directory::find(const std::string& filename, const std::vector<OpFlags>& oflags)
	{
		//Resource* temp = nullptr;     // defaults to an empty collection
		//bool flag = true;
		//for (size_t i = 0; i < m_contents.size(); i++)
		//{
		//	for (size_t i = 0; i < oflags.size(); i++)
		//	{
		//		if (oflags[i] == OpFlags::RECURSIVE)
		//			flag = false;
		//	}
		//	if (m_contents[i]->type() == NodeType::FILE && (m_contents[i]->name().compare(filename) == 0)) 
		//		temp = m_contents[i];
		//	else if (m_contents[i]->type() == NodeType::DIR && flag == false)
		//		temp = dynamic_cast<Directory*>(m_contents[i])->find(filename, oflags);
		//}

		Resource* temp = nullptr;
		bool flag = true;
		for (size_t i = 0; i < m_contents.size(); i++)
		{
			for (auto i = oflags.begin(); i != oflags.end(); i++)
			{
				if ((*i) == OpFlags::RECURSIVE)
					flag = false;
			}
			if (m_contents[i]->type() == NodeType::FILE && (m_contents[i]->name().compare(filename) == 0))
				temp = m_contents[i];
			else if (m_contents[i]->type() == NodeType::DIR && flag == false)
				temp = dynamic_cast<Directory*>(m_contents[i])->find(filename, oflags);
		}
		return temp;
	}
	Directory::~Directory()
	{
		m_contents.clear();
	}
}