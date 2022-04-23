// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/03/13
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_DIRECTORY_H
#define SDDS_DIRECTORY_H

#include <iostream>
#include <vector>
#include "Resource.h"
#include "Flags.h"

namespace sdds
{
	class Directory : public Resource
	{
		// Each element of the vector can either be a Directory or a File
		std::vector<Resource*> m_contents;

	public:
		Directory() {};
		Directory(std::string drcName);
		void update_parent_path(const std::string& parent_path);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		Directory& operator+=(Resource* src);
		Resource* find(const std::string& filename, const std::vector<OpFlags>& oflags = {});
		Directory(const Directory& src) = delete;
		Directory& operator=(const Directory& src) = delete;
		Directory(const Directory&& src) = delete;
		Directory& operator=(Directory&& src) = delete;
		~Directory();

		// part2
		void remove(const std::string& dirname, const std::vector<OpFlags>& oflags = {});
		void display(std::ostream& os, const std::vector<FormatFlags>& oflags = {}) const;
	};
}
#endif // !SDDS_DIRECTORY_H

