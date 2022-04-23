// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include <iostream>
#include <string>
#include "Resource.h"
#include "Flags.h"

namespace sdds
{
	class File : public Resource    // A file is considered a resource of a filesystem
	{
		std::string m_contents{};   // stores the contents of a file

	public:
		File() {};
		File(std::string fileName, std::string text = "");
		void update_parent_path(const std::string& parent_path);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		~File() {};
	};
}
#endif // !SDDS_FILE_H


