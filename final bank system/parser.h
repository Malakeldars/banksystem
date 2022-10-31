#pragma once
#include<sstream>
#include"admin.h"

using namespace std;
class Parser {
private:
    static vector<string> split(string line) {
        vector<string>info;
        stringstream splitline(line);
        string part;
        while (getline(splitline, part, ';')) {
            info.push_back(part);
        }
        return info;
    }
public:
    static Client parseToClient(string line) {
        vector <string> clientline = split(line);
        Client c;
        c.setId(stoi(clientline[0]));
        c.setName(clientline[1]);
        c.setPassword(clientline[2]);
        c.setBalance(stod(clientline[3]));
        return c;
    }
    static Employee parseToEmployee(string line)
    {
        vector<string>employeeData = split(line);
        Employee myEmployee;
        myEmployee.setId(stoi(employeeData[0]));
        myEmployee.setName(employeeData[1]);
        myEmployee.setPassword(employeeData[2]);
        myEmployee.setSalary(stod(employeeData[3]));
        return myEmployee;

    }

    static Admin parseToAdmin(string line)
    {
        vector<string>adminData = split(line);
        Admin myAdmin;
        myAdmin.setId(stoi(adminData[0]));
        myAdmin.setName(adminData[1]);
        myAdmin.setPassword(adminData[2]);
        myAdmin.setSalary(stod(adminData[3]));
        return myAdmin;

    }
};

