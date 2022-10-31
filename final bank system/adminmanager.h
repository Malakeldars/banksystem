#pragma once
#include"employeemanager.h"
using namespace std;

class Adminmanager
{
public:
    static bool printadminMenu(Admin* a) {
        int choice = 0;
        cout << "1- if you want to add employee\n";
        cout << "2- if you want to search for an employee\n";
        cout << "3- if you want to search for a client\n";
        cout << "4- if you want to display all employees\n";
        cout << "5- if you want to display all clients\n";
        cout << "6- if you want to edit an employee\n";
        cout << "7- if you want to display your information\n";
        cout << "8- if you want to edit a client\n";
        cout << "9- if you want to change your password\n";
        cout << "10- if you want to log out\n";
        cin >> choice;
        switch (choice) {
        case 1:
        {
            newEmployee(a);
            break;
        }
        case 2: {
            searchforemployee(a);
            break; }
        case 3: {
            Employeemanager::searchforclient(a);
            break;
        }
        case 4:
        {
            listemployee(a);
            break;
        }
        case 5:
        {
            Employeemanager::listclient(a);
            break;
        }
        case 6:
        {
            editemployee(a);
            break;
        }
        case 7:
        {
            a->displayInfo();
            break;
        }
        case 8:
        {
            Employeemanager::editclient(a);
            break;
        }
        case 9:
        {
            ClientManager::updatePassword(a);
            break;
        }
        case 10:
        {
            return false;
            break;
        }
        default:
        {
            cout << "invalid input\n";
            break;
        }
        }
        return true;
    }

    static Admin* login(int id, string password) {

        for (int i = 0; i < allAdminsData.size(); i++)
        {
            if (allAdminsData[i].getId() == id && allAdminsData[i].getPassword() == password)
            {
                return &allAdminsData[i];
            }
        }
        return NULL;
    }
    static void newEmployee(Admin* admin)
    {
        int id;
        string name, password;
        double salary;
        Employee e;
        cout << "Enter Employee name: " << endl;
        cin >> name;
        e.setName(name);
        cout << "Enter employee password: " << endl;
        cin >> password;
        e.setPassword(password);
        cout << "The employee's id: ";
        id = FileHelper::getLast("EmployeeLastId.txt");
        id++;
        cout << id << endl;
        e.setId(id);
        FileHelper::saveLast("EmployeeLastId.txt", id);
        cout << "Enter employee salary: " << endl;
        cin >> salary;
        e.setSalary(salary);
        admin->addEmployee(e);
    }
    static void searchforemployee(Admin* admin)
    {
        int id;
        cout << "Enter ID of the employee you are looking for: \n";
        cin >> id;
        if (admin->searchemployee(id) != NULL)
        {
            admin->searchemployee(id)->displayInfo();
        }
        else cout << "Invalid id";
    }
    static void editemployee(Admin* admin)
    {
        string newname, newpass;
        double salary = 0.0;
        int id=0;
        cout << "Enter Employee id: " << endl;
        cin >> id;
        if (admin->searchemployee(id) == NULL)
        {
            cout << "Invalid id";
        }
        else
        {
            cout << "Enter employee name: " << endl;
            cin >> newname;

            cout << "Enter employee password: " << endl;
            cin >> newpass;

            cout << "Enter new salary: " << endl;
            cin >> salary;

            admin->editEmployee(id, newname, newpass, salary);
            FileManager::updateEmployees();
        }
    }
    static void listemployee(Admin* admin)
    {
        admin->listEmployee();
    }
};

