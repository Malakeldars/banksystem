#pragma once
#include<iostream>
#include<string>
using namespace std;
class Validition {
public:
    static bool validateName(string name) {
        bool isValid = false;
        int minSize = 5;
        int maxSize = 20;
        if (!(name.length() >= minSize && name.length() <= maxSize)) {
            isValid = false;
        }
        else {
            for (char i : name) {
                if (!((i >= 65 && i <= 90) || (i >= 97 && i <= 122))) {
                    isValid = false;
                    break;
                }
                isValid = true;
            }
        }
        return isValid;
    }

    static bool validatePassword(string password) {
        int minSize = 8;
        int maxSize = 20;
        bool isValid = true;
        if (!(password.length() >= minSize && password.length() <= maxSize)) {
            isValid = false;
        }
        else {
            isValid = true;
        }
        return isValid;
    }

    static bool validateBalance(double balance) {
        double minBalance = 1500;
        bool isValid = false;
        if (!(balance >= minBalance)) {
            isValid = false;
        }
        else {
            isValid = true;
        }
        return isValid;


    }

    static bool adminValidateSalary(double salary) {
        double minsalary = 5000;
        bool isValid = false;
        if (!(salary >= minsalary)) {
            isValid = false;
        }
        else {
            isValid = true;
        }
        return isValid;
    }

};

