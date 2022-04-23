// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "File.h"

namespace sdds
{
	File::File(std::string fileName, std::string text)
	{
		m_name = fileName;
		m_contents = text;
	}
	void File::update_parent_path(const std::string& parent_path)
	{
		m_parent_path = parent_path;
	}
	NodeType File::type() const
	{
		return NodeType::FILE;
	}
	std::string File::path() const
	{
		return m_parent_path + m_name;
	}
	std::string File::name() const
	{
		return m_name;
	}
	int File::count() const
	{
		return -1;
	}
	size_t File::size() const
	{
		return m_contents.length();
	}
}