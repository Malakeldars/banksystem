#include<iostream>
#include "admin.h"
#include "screens.h"
#include "filemanager.h"


using namespace std;

int main()
{

	Admin a("malak", 1, "malak400", 4999);
	/*FileHelper::saveAdmin("Adim.txt", "AdminLastId.txt", a);

	Employee emp("menna", 1, "menna849", 53094);
	FileHelper::saveEmployee("EmployeeId", "EmployeeLastId.txt", emp);

	Client c("salma", 1, "salma848", 382020);
	FileHelper::saveClient("Client.txt", "ClientLastId.txt", c);*/

	Screens::runapp();
}