// Name: Yuan-Kai Han
// Email: yhan77@myseneca.ca
// StudentID: 154477194
// Date: 2022/03/13
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H
#include <iostream>
#include "Directory.h"

namespace sdds
{
	class Filesystem
	{
		Directory* m_root;
		Directory* m_current;
	public:
		Filesystem(std::string fileName, std::string rootName = "");
		Filesystem& operator+=(Resource* src);
		Directory* change_directory(const std::string& dirname = "");
		Directory* get_current_directory() const;
		Filesystem(const Filesystem& src) = delete;
		Filesystem& operator=(const Filesystem& src) = delete;
		Filesystem(Filesystem&& src) noexcept;
		Filesystem& operator=(Filesystem&& src) noexcept;
		~Filesystem();
	};
}
#endif // !SDDS_FILESYSTEM_H

