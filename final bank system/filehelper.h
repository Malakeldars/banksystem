#pragma once
/*#include<iostream>*/
/*#include<vector>*/
#include<fstream>
#include"parser.h"

/*#include"FileManager.h"*/

using namespace std;
class FileHelper {
public:
    static int getLast(string fileName) {
        string x;
        fstream file(fileName, ios::in);
        file >> x;
        file.close();
        return stoi(x);
    }
    static void saveLast(string fileName, int id) {
        fstream file(fileName, ios::out);
        file << id << endl;
        file.close();
    }

    static void saveClient(string filename, string ClientLastId, Client c) {
        /*int lastID = getLast("ClientLastId.txt");*/
        fstream file;
        file.open("Clients.txt", ios::app);
        file << c.getId() << ';' << c.getName() << ';' << c.getPassword() << ';' << c.getBalance() << endl;
        file.close();
        saveLast("ClientLastId.txt", c.getId());
    }

    static void saveEmployee(string filename, string EmployeeLastId, Employee e)
    {
       /* int lastID = getLast("EmployeeLastId.txt");*/
        fstream file;
        file.open("Employees.txt", ios::app);
        file << e.getId() << ';' << e.getName() << ';' << e.getPassword() << ';' << e.getSalary() << endl;
        file.close();
        saveLast(EmployeeLastId, e.getId());
    }

    static void saveAdmin(string filename, string AdminLastId, Admin a)
    {
       /* int lastId = getLast("AdminLastID.txt");*/
        fstream file;
        file.open("Admin.txt", ios::app);
        file << a.getId() << ';' << a.getName() << ';' << a.getPassword() << ';' << a.getSalary() << endl;
        file.close();
        saveLast(AdminLastId, a.getId());
    }

    //=============GETTERS===============

    static void getClients() {
        string line;
        fstream file("Clients.txt", ios::in);
        while (getline(file, line)) {
            //Client c = Parser::parseToClient(line);
            allClientsData.push_back(Parser::parseToClient(line));
        }
        file.close();
    }
    static void getEmployees()
    {
        string line;
        fstream file("Employees.txt", ios::in);
        while (getline(file, line)) {
            allEmployeesData.push_back(Parser::parseToEmployee(line));
        }
        file.close();
    }
    static void getAdmins()
    {
        string line;
        fstream file("Admin.txt", ios::in);
        while (getline(file, line)) {
            allAdminsData.push_back(Parser::parseToAdmin(line));
        }
        file.close();
    }

    //==================================================================
    static void clearFile(string fileName, string lastIdFile) {
        //clear data file
        fstream dataFile(fileName, ios::out);
        dataFile.close();
        //clear IDs file & back id =0
        fstream idsFile(lastIdFile, ios::out);
        int id = 0;
        idsFile << id << endl;
        idsFile.close();
    }
};