// Name: Yuan-Kai Han
// Seneca Student ID: 154477194
// Seneca email: yhan77@myseneca.ca
// Date of completion: MS3
// 
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"
namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder{ 0 };
		Workstation* m_firstStation{ nullptr };
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_LINEMANAGER_H


