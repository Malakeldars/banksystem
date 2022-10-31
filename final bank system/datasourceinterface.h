#pragma once
/*#include<iostream>*/
#include"admin.h"
using namespace std;

class DataSourceInterface {
public:
    //addition
    virtual void addClient(Client) = 0;
    virtual void addEmployee(Employee) = 0;
    virtual void addAdmin(Admin) = 0;


    //getter
    virtual vector<Client> getAllClients() = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual vector<Admin> getAllAdmins() = 0;

    //removal
    virtual void removeAllEmployees() = 0;
    virtual void removeAllClients() = 0;
    virtual void removeAllAdmins() = 0;
};

