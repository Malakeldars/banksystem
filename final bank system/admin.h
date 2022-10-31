#pragma once

#include "employee.h"
using namespace std;


class Admin : public Employee
{
public:
    Admin(){} /*: Employee() {}*/

    Admin(string name, int id, string password, double salary) : Employee(name, id, password, salary) {}

    //==========================EMPLOYEE==============================

    void addEmployee(Employee& employee)
    {
        allEmployeesData.push_back(employee);

    }

    Employee* searchemployee(int id)
    {
       /* bool found = true;

        Employee* empptr = nullptr;
        int index = 0;
        for (auto& itr : allEmployeesData)
        {
            if (itr.getId() == id)
            {
                empptr = &itr + (index * sizeof(itr));
                break;
            }
            index++;
        }*/

        bool found = false;

        for (eIt = allEmployeesData.begin(); eIt < allEmployeesData.end(); eIt++)
        {
            if (id == eIt[0].getId()) {
                return eIt._Ptr;
            }
        }
        if (!(found))
        {
            return NULL;
        }


      /*  return empptr;*/

    }

    void editEmployee(int id, string name, string password, double Salary)
    {
        Employee* c = searchemployee(id);
       
        
            c->setName(name);
            c->setPassword(password);
            c->setSalary(Salary);
    }

    void listEmployee()
    {
        for (eIt = allEmployeesData.begin(); eIt != allEmployeesData.end(); eIt++) {
            eIt->displayInfo();
            cout << "-------------------------\n";
        }
    }
};
static vector<Admin> allAdminsData;
static vector<Admin>::iterator aIt;

