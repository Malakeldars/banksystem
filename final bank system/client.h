#pragma once
#include"person.h"
#include<vector>
#include<iterator>
using namespace std;

class Client :public Person {
private:
	double balance;
public:
	Client(){}/* : Person() {
		balance = 0.0;
	}*/
	Client(string name, int id, string password, double balance) :Person(name, id, password) {
		setBalance(balance);
	}
	void setBalance(double balance) {
		if (Validition::validateBalance(balance)) {
			this->balance = balance;
		}
		else {
			cout << "invalid amount of money\n";// here we need to ask user to input his correct balance again
		}
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		this->balance += amount;
		cout << "Successful transaction\n";
	}
	void withdraw(double amount) {
		if (amount <= this->balance) {
			this->balance -= amount;
			cout << "Successful transaction\n";
		}
		else {
			cout << "amount exceed\n"; ;
		}
	}
	void transferTo(double amount, Client& recipient) {
		if (amount <= this->balance) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << "Successful transaction\n";

		}
		else {
			cout << "amount excced\n"; ;

		}

	}
	void checkBalance() {
		cout << "Your balance = " << this->balance << endl;
	}
	void displayInfo() {
		Person::displayInfo();
		cout << "Balance: " << this->balance << endl;
	}
};

static vector<Client>allClientsData;
static vector<Client>::iterator clIt;




