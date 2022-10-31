#pragma once

#include "clientmanager.h"
#include"screens.h"
using namespace std;

class Employeemanager {
public:
    static bool printEmployeetMenu(Employee* e) {
        int choice = 0;
        cout << "1- if you want to add new client\n";
        cout << "2- if you want to search for a client\n";
        cout << "3- if you want to list all clients\n";
        cout << "4- if you want to edit clients info\n";
        cout << "5- if you want to displayInfo\n";
        cout << "6- if you want to updatePassword\n";
        cout << "7-logout\n";
        cin >> choice;
        

        switch (choice) {
        case 1:
        {
            newclient(e);
            break;
        }
        case 2:
        {
            searchforclient(e);
            break;
        }
        case 3:
        {
            listclient(e);
            break;
        }
        case 4:
        {
            editclient(e);
            break;
        }
        case 5:
        {
            e->displayInfo();
            break;
        }
        case 6:
        { 
            ClientManager::updatePassword(e);
            break; 
        }
        case 7:
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

    static void newclient(Employee* employee)
    {
        int id;
        string name, password;
        double balance;
        Client clt;
        cout << "Enter client name: " << endl;
        cin >> name;
        clt.setName(name);
        cout << "Enter client password: " << endl;
        cin >> password;
        clt.setPassword(password);
        cout << "The client's id: ";
        id = FileHelper::getLast("ClientLastId.txt");
        id++;
        cout << id << endl;
        clt.setId(id);
        FileHelper::saveLast("ClientLastId.txt", id);
        cout << "Enter client balance: " << endl;
        cin >> balance;
        clt.setBalance(balance);

        employee->addClient(clt);
    }

    static void listclient(Employee* employee)
    {
        employee->listClient();
    }

    static void searchforclient(Employee* employee)
    {
        int id;
        cout << "Enter ID of the client you are looking for: \n";
        cin >> id;
        if (employee->searchClient(id) != NULL)
        {
            employee->searchClient(id)->displayInfo();
        }
        else cout << "Invalid id";

    }

    static void editclient(Employee* employee)
    {
        string newname, newpass;
        double balance = 0.0;
        int id;
        cout << "Enter client id: " << endl;
        cin >> id;
        if (employee->searchClient(id) == NULL)
        {
            cout << "Invalid id";
        }
        else
        {
            cout << "Enter client name: " << endl;
            cin >> newname;

            cout << "Enter client password: " << endl;
            cin >> newpass;

            cout << "Enter new balance: " << endl;
            cin >> balance;

            employee->editClient(id, newname, newpass, balance);
            FileManager::updateClients();
        }
    }

    static Employee* login(int id, string password) {
        
       /* cout << "enter your id\n";
        if (a.searchemployee(id) != nullptr) {
            cout << "enter your password\n";
            if (e->getPassword() == password) {
                printClientMenu();
            }
            else {
                cout << "wrong data\n";
            }
        }
        return e;*/

        for (eIt = allEmployeesData.begin(); eIt < allEmployeesData.end(); eIt++)
        {
            if (eIt[0].getId() == id && eIt[0].getPassword() == password)
            {
                return eIt._Ptr;
            }
        }
        return NULL;
    }
};


