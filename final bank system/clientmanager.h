#pragma once
/*#include<iostream>*/
#include"client.h"
#include"filemanager.h"
#include <string>
/*#include"employee.h"*/
using namespace std;
class ClientManager {
public:
    static bool printClientMenu(Client* c) {
        int choice = 0;
        cout << "1- if you want to deposit\n";
        cout << "2- if you want to withdraw\n";
        cout << "3- if you want to transferTo\n";
        cout << "4- if you want to checkBanlance\n";
        cout << "5- if you want to displayInfo\n";
        cout << "6- if you want to updatePassword\n";
        cout << "7- if you want to logout\n";

        cin >> choice;
        double amount = 0.0;
        Employee e;
        switch (choice) {
        case 1:
        {
            cout << "enter amount of money\n";
            cin >> amount;
            c->deposit(amount);
            FileManager::updateClients();
            break;
        }
        case 2:
        {
            cout << "enter amount of money\n";
            cin >> amount;
            c->withdraw(amount);
            FileManager::updateClients();
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter ID of the person you want to transfer to: \n";
            cin >> id;
            if (e.searchClient(id) != NULL)
            {
                Client recipent = *(e.searchClient(id));
                cout << "Enter amount to be transfered: \n";
                cin >> amount;
                c->transferTo(amount, recipent);
                FileManager::updateClients();
            }
            else
                cout << "Client does not exist, try again...\n";
            break;
        }
        case 4: {
            c->checkBalance();
            break; }
        case 5:
        {
            c->displayInfo();
            break;
        }
        case 6:
        {
            updatePassword(c);
            FileManager::updateClients();
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
    static void updatePassword(Person* person) {
        Employee e;
        Client* c = e.searchClient(person->getId());
        string newPassword = "";
        cout << "enter new password\n";
        cin >> newPassword;
        c->setPassword(newPassword);
    }
    static Client* login(int id, string password) {
       
        /*cout << "enter your id\n";*/
        /*if (e.searchClient(id) != nullptr) {
            c = e.searchClient(id);
            cout << "enter your password\n";
            if (c->getPassword() == password) {
                printClientMenu();
            }
            else 
            {
                cout << "wrong password\n";
            }
        }*/

        for (clIt = allClientsData.begin(); clIt < allClientsData.end(); clIt++)
        {
            if (clIt[0].getId() == id && clIt[0].getPassword() == password)
            {
                return clIt._Ptr;
            }
        }
        return NULL;


       /* return c;*/
    }
};