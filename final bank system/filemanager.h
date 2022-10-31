#pragma once
#include"datasourceinterface.h"
#include"filehelper.h"
using namespace std;

//==============CREATING FILE======================

class FileManager :public DataSourceInterface {
public:
	/*static void createFile(string name) {
		ofstream file(name + ".txt");
		file.close();
	}*/
	///===================Adding===================


	static void addClient(Client newClient) {
		FileHelper::saveClient("Clients.txt", "ClientLastId.txt", newClient);
	}

	static void addEmployee(Employee newEmployee) {
		FileHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", newEmployee);
	}

	static void addAdmin(Admin newAdmin)
	{
		FileHelper::saveAdmin("Admin.txt", "AdminLastId", newAdmin);
	}
	//==================GETTING All=================
	static void getAllClients() {
		FileHelper::getClients();
	}
	static void getAllEmployees() {
		FileHelper::getEmployees();
	}
	static void getAllAdmins() {
		FileHelper::getAdmins();
	}
	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

	//=================REMOVE DATA====================
	static void removeAllClients() {
		FileHelper::clearFile("Clients.txt", "ClientLastId.txt");

	}
	static void removeAllEmployees()
	{
		FileHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
	}

	static void removeAllAdmins()
	{
		FileHelper::clearFile("Admin.txt", "AdminLastId.txt");

	}
//public:

	static void updateClients() {
		removeAllClients();
		for (clIt = allClientsData.begin(); clIt != allClientsData.end(); clIt++) addClient(*clIt);
	}
	static void updateEmployees() {
		removeAllEmployees();
		for (eIt = allEmployeesData.begin(); eIt != allEmployeesData.end(); eIt++) addEmployee(*eIt);
	}
	static void updateAdmins() {
		removeAllAdmins();
		for (aIt = allAdminsData.begin(); aIt != allAdminsData.end(); aIt++) addAdmin(*aIt);
	}
	static void refill_all() {
		updateClients();
		updateEmployees();
		updateAdmins();
	}
};


