#pragma once
#include<iostream>

#include"Validation.h"
using namespace std;
class Person
{
private:
    string name;
    int id;
    string password;
public:
    Person()
    {
        name = "";
        id = 0000;
        password = "";
    }
    Person(string name, int id, string password)
    {
        setName(name);
        this->id = id;
        setPassword(password);

        if (Validition::validateName(name)) {
            this->name = name;
        }
        else
        {
            cout << "min size 5 char and max size 20" << endl;
            cout << "must enter alphabetic chars" << endl;
        }
        //password
        if (Validition::validateName(password) == 1) {
            this->password = password;
        }
        else
        {
            cout << "password must be with in 8 to 20 charcters" << endl;
        }
    }
    

    void setName(string name)
    {
        if (Validition::validateName(name) == true)
        {
            this->name = name;
        }
        else {
            cout << "invalid name\n";// need to ask user to re-input his name again
        }
    }

    string getName()
    {
        return name;
    }
    void setPassword(string password)
    {
        if (Validition::validatePassword(password) == true) {
            this->password = password;
        }
        else {
            cout << "invalid pass length\n";// need to ask user to re-input his password again
        }

    }

    string getPassword()
    {
        return password;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }


    void displayInfo() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;

    }

};

