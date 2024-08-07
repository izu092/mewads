#ifndef balance_h
#define balance_h

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

void balance(const int &acc_number, const string &warn);
bool acc_checker(int &acc_number);

void balance_display(const int &f_acc_number, const string &warn)
{

    system("cls");
    cout << "\n\n\n\n\n";
    cout << setw(27);
    for (int i = 0; i < 70; i++)
    {
        cout << "=";
    }
    cout << endl;
    cout << "                         |\t\t\t  Bank Management System\t\t\t|" << endl;
    cout << setw(27);
    for (int i = 0; i < 70; i++)
    {
        cout << "=";
    }
    cout << endl;

    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

    cout << setw(59) << "|\t\t\t      == DEPOSIT ==      \t\t\t|\n";
    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

    if (f_acc_number == 0)
    {
        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
    }

    if (f_acc_number != 0)
    {
        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(19 - log10(f_acc_number) + 1) << "|" << endl;
    }

    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

    cout << setw(37) << "|\t DEPOSIT: " << 0 << setw(55 - 1) << "|" << endl;

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

void balance_inq()
{
    int f_acc_number = 0;

    bool go = false;
    string warn = "?????";
    while (!go)
    {
        balance_display(f_acc_number, warn);

        cout << setw(50) << "Account Number: ";
        cin >> f_acc_number;

        if (!acc_checker(f_acc_number))
        {

            warn = "Invalid";
            balance_display(f_acc_number, warn);
            cout << setw(55) << "Wrong Account Number TRY AGAIN!";
            getch();
            f_acc_number = 0;
            warn = "?????";
        }
        else
        {
            warn = "Valid";
            balance(f_acc_number, warn);
            go = true;
        }
    }
}

#endif
