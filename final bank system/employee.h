#pragma once

#include "client.h"
/*#include "Parser.h"
include "client.h"
#include "FileManager.h"*/
using namespace std;
class Employee : public Person
{
private:
    double salary;

public:
    Employee() : Person()
    {
        salary = 0.0;
    }
    Employee(string name, int id, string password, double salary) : Person(name, id, password)
    {
        setSalary(salary);
    }
    void setSalary(double salary)
    {
        if (Validition::validateBalance(salary))
        {
            this->salary = salary;
        }
        else
        {
            cout << "invalid amount of money\n"; // here we need to ask user to input his correct salary again
        }
    }
    double getSalary()
    {
        return salary;
    }
    void displayInfo()
    {
        cout << "Name: " << Person::getName()<<endl;
        cout << "ID: " << Person::getId()<<endl;
        cout << "Password: " << Person::getPassword()<<endl;
        cout << "Salary: " << salary<<endl;
    }

    //==========================CLIENT====================================
    void addClient(Client& client)
    {
        allClientsData.push_back(client);
    }

    Client* searchClient(int id)
    {
       /* Client* cltPtr = nullptr;
        int index = 0;
        for (auto& itr : allClientsData)
        {
            if (itr.getId() == id)
            {
                cltPtr = &itr + (index * sizeof(itr));
                break;
            }
            index++;
        }*/
       
            bool found = false;
            for (clIt = allClientsData.begin(); clIt < allClientsData.end(); clIt++)
            {
                if (id == clIt[0].getId()) {
                    return clIt._Ptr;
                }
            }
            if (!(found))
            {
                return NULL;
            }
        

      /*  return cltPtr;*/
    }

    void editClient(int id, string name, string password, double balance)
    {
        Client* c = searchClient(id);
        
            c->setName(name);
            c->setPassword(password);
            c->setBalance(balance);
        
           
        
    }

    void listClient() {
        for (clIt = allClientsData.begin(); clIt != allClientsData.end(); clIt++) {
            clIt->displayInfo();
            cout << "-------------------------\n";
        }
    }
};
static vector<Employee> allEmployeesData;
static vector<Employee>::iterator eIt;

