// Workshop 8 - Smart Pointers
// Name: Yuan-Kai Han
// Email: yhan773@myseneca.ca
// StudentID: 154477194
// Date: 2022. Mar. 25.
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds
{
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers

		// 1. loop over the list of employees and salaries

		// 2. as we loop over the two lists, check that the SIN is valid (checkLuhn from generating list), if not valid
		// we should throw an exception (type std::string)

		// 3. if the SIN is valid, check if agiven id in the employee list matches the one in the salary list
		//    - dynamically generate the object of type EmployeeWage based on the name/salary from the emp/salary list element

		// 4. then we need to valid the salary for that employeewage object, if it's good then push it to the activeEMP
		//    - if not good then deallocate the memory instead, throw exception

		// 5. keep looping till end of both lists
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (activeEmp.checkLuhn(emp[i].id) || activeEmp.checkLuhn(sal[j].id))
				{
					if (emp[i].id == sal[j].id)
					{
						EmployeeWage* e = new EmployeeWage(emp[i].name, sal[j].salary);
						try
						{
							e->rangeValidator();
							activeEmp += e;
							delete e;
							e = nullptr;
						}
						catch (...)
						{
							delete e;
							e = nullptr;
							throw;
						}
					}
				}
				else
					throw std::string("Not Valid!");
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers

		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (activeEmp.checkLuhn(emp[i].id) || activeEmp.checkLuhn(sal[j].id))
				{
					if (emp[i].id == sal[j].id)
					{
						std::unique_ptr<EmployeeWage> e(new EmployeeWage(emp[i].name, sal[j].salary));
						e->rangeValidator();
						activeEmp += e;
					}
				}
				else
					throw std::string("Not Valid!");
			}
		}
		return activeEmp;
	}
}