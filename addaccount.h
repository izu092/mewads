#ifndef addaccount_h
#define addaccount_h

#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include "database.h"

using namespace std;

void add_account(const string &full_name, const string &age, const char &gender, const string &cellphone_num, const string &email, const string &address, const int &acc_number, const int &balance, const string &pin_number);

void display(const string &full_name, const string &age, const char &gender, const string &cellphone_num, const string &email, const string &address)
{

        system("cls");
        cout << "\n\n\n\n\n";
        cout << setw(27);
        for (int i = 0; i < 70; i++)
        {
                cout << "=";
        }
        cout << endl;
        cout << "                         |\t\t\t      CREATE ACCOUNT     \t\t\t|" << endl;
        cout << setw(27);
        for (int i = 0; i < 70; i++)
        {
                cout << "=";
        }
        cout << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << "                         |\t\t\t    == USER DETAILS ==  \t\t\t|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << setw(60) << "|  [1] Name of the Account Holder: " << full_name << setw(37 - full_name.size()) << "|" << endl;
        cout << setw(59) << "|  [2] Age of The Account Holder: " << age << setw(38 - age.size()) << "|" << endl;
        cout << setw(68) << "|  [3] Gender of The Account Holder (M/F): " << gender << setw(29 - 1) << "|" << endl;
        cout << setw(69) << "|  [4] Mobile Number of The Account Holder: " << cellphone_num << setw(28 - cellphone_num.size()) << "|" << endl;
        cout << setw(61) << "|  [5] Email of the Account Holder: " << email << setw(36 - email.size()) << "|" << endl;
        cout << setw(63) << "|  [6] Address of the Account Holder: " << address << setw(34 - address.size()) << "|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << setw(27);
        for (int i = 0; i < 70; i++)
        {
                cout << "=";
        }
        cout << endl
             << endl
             << endl;
}

void new_account()
{
        string full_name, email, address;
        string age;
        char gender = ' ';
        int acc_number;
        string cellphone_num;
        int balance = 0;
        string pin_number = "none";
        bool error = false;

        display(full_name, age, gender, cellphone_num, email, address);
        cout << setw(60) << "\t[1] Name of the Account Holder: ";
        cin.ignore();
        getline(cin, full_name);

        while (!error)
        {
                display(full_name, age, gender, cellphone_num, email, address);
                cout << setw(60) << "\t[2] Age of the Account Holder: ";
                cin >> age;
                int valid_age = true;
                int size = age.size();
                for (int i = 0; i < size; i++)
                {
                        if (!isdigit(age[i]))
                        {
                                valid_age = false;
                                break;
                        }
                }

                if (!valid_age)
                {
                        age = " ";
                        display(full_name, age, gender, cellphone_num, email, address);
                        cout << "\t\t\t\t\tInvalid age input." << endl;
                        cout << setw(57) << "\t\t\tPlease press any key to try again!";
                        getch();
                }
                else
                {
                        error = true;
                }
        }

        error = false;

        while (gender != 'M' && gender != 'F')
        {
                display(full_name, age, gender, cellphone_num, email, address);
                cout << setw(60) << "\t\t[3] Gender of The Account Holder (M/F): ";
                cin.ignore();
                cin >> gender;
                if (gender != 'M' && gender != 'F')
                {
                        gender = ' ';
                        display(full_name, age, gender, cellphone_num, email, address);
                        cout << "\t\t\t    Invalid gender input. Please enter 'M' for male or 'F' for female: " << endl;
                        cout << setw(57) << "\t\t\tPlease press any key to try again!";
                        getch();
                }
        }

        while (!error)
        {
                display(full_name, age, gender, cellphone_num, email, address);
                cout << setw(60) << "\t\t[4] Mobile Number of The Account Holder: ";
                cin.ignore();
                cin >> cellphone_num;
                if (cellphone_num.size() < 10 || cellphone_num.size() > 11)
                {
                        cellphone_num = " ";
                        display(full_name, age, gender, cellphone_num, email, address);
                        cout << setw(60) << "\t\t Invalid Number " << endl;
                        cout << setw(60) << "\t\t\t\tPlease press any key to try again!";
                        getch();
                }
                else
                {
                        error = true;
                }
        }

        display(full_name, age, gender, cellphone_num, email, address);
        cout << setw(60) << "\t[5] Email of the Account Holder: ";
        cin.ignore();
        getline(cin, email);
        display(full_name, age, gender, cellphone_num, email, address);
        cout << setw(60) << "\t[6] Address of the Account Holder: ";
        cin.ignore();
        getline(cin, address);
        display(full_name, age, gender, cellphone_num, email, address);
        cout << setw(60) << "Please press any key to continue! ";

        getch();
        system("cls");
        cout << "\n\n\n\n\n";
        cout << setw(27);
        for (int i = 0; i < 70; i++)
        {
                cout << "=";
        }
        cout << endl;
        cout << "                         |\t\t\t      CREATE ACCOUNT     \t\t\t|" << endl;
        cout << setw(27);
        for (int i = 0; i < 70; i++)
        {
                cout << "=";
        }
        cout << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << "                         |\t\t\t      == ATM CARD ==\t\t\t\t|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << setw(34) << "|\t USER: " << full_name << setw(58 - full_name.size()) << "|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        srand(time(NULL));
        acc_number = rand() % 8888888889 + 1111111111;
        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(43 - 10) << "|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << setw(41) << "|\tUser account: " << acc_number << " has been successfully created!" << setw(20 - 10) << "|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << setw(27);
        for (int i = 0; i < 70; i++)
        {
                cout << "=";
        }
        cout << endl
             << endl
             << endl;
        add_account(full_name, age, gender, cellphone_num, email, address, acc_number, balance, pin_number);
}
#endif