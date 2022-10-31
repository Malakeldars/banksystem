#pragma once
//#include<iostream>
//#include"client.h"
//#include"Employee.h"
//#include "clientmanager.h"
#include <Windows.h>
#include "adminmanager.h"

//#include"employeemanager.h"
using namespace std;

class Screens
{
public:
	static void bankname()
	{
		cout << "======================MADGSCAR WORLD WIDE BANK================" << endl;

		
		Sleep(600);
	}

	static void welcome()
	{
		cout << "================welcome to our bank================" << endl;
		
		Sleep(600);
		cout << "\n";
	}

	static void loginoptions()
	{

		cout << "LOGIN AS:" << endl;
		cout << "1-Admin" << endl << "2-Employee" << endl << "3-Client" << endl;
	}

	static int loginas()
	{
		loginoptions();
		int num;
		cin >> num;
		if (num == 1 || num == 2 || num == 3)
		{
			return num;
		}
		else
		{
			cout << "Invalid choice";
			loginas();
		}
	}

	static void invalid(int c)
	{
		cout << "INVALID NUMBER";
		loginscreen(c);
	}

	static bool logout()
	{
		char again;
		cout << "Are you sure you want to log out? (y/n)\n";
		for (int i = 0; i < 4; i++) {
			cout << ".";
			Sleep(400);
		}
		cout << "\n";
		cin >> again;
		while (again != 'Y' && again != 'y' && again != 'N' && again != 'n')
		{
			cout << "  Invalid character, Please choose character from the options:  ";  cin >> again;
			break;
		}
		if (again == 'Y' || again == 'y')
		{
			return true;
		}
		else if (again == 'n' || again == 'N')
		{
			cout << "goodbye\n";
		}
	}

	static void loginscreen(int c)
	{
		int num = c;
		int id;
		string password;
		cout << "Enter ID: " << endl;
		cin >> id;
		cout << "Enter Password: " << endl;
		cin >> password;

		switch (num)
		{
		case 1:
		{

			if (Adminmanager::login(id, password) != NULL)
			{
				while (Adminmanager::printadminMenu(Adminmanager::login(id, password)) != false);
				logout();
			}
			else invalid(1);
			break;
		}
		case 2:
		{

			if (Employeemanager::login(id, password) != NULL)
			{
				while (Employeemanager::printEmployeetMenu(Employeemanager::login(id, password)) != false);
				logout();
			}
			else invalid(2);
			break;
		}

		case 3:
		{
			if (ClientManager::login(id, password) != NULL)
			{
				while (ClientManager::printClientMenu(ClientManager::login(id, password)) != false);
				logout();
			}
			else invalid(3);
			break;
		}

		default:
		loginoptions();

		
		}
	
	}

	static void runapp()
	{

		FileManager::getAllData();
		loginscreen(loginas());
		FileManager::refill_all();
		/*bankname();
		welcome();
		loginoptions();*/
	}

};
