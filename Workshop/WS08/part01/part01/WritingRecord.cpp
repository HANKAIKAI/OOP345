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
						/*e->rangeValidator();
						activeEmp += e;
						delete e;
						e = nullptr;*/
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
}