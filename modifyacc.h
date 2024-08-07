#ifndef modifyacc_h
#define modifyacc_h

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

void edit_account(const int &acc_number);
void modify(const int &f_acc_number, const string &warn)
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

    cout << setw(58) << "|\t\t\t   == MODIFY ACCOUNT ==\t\t\t\t|\n";
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

void modify_acc()
{
    int f_acc_number = 0;

    bool go = false;
    string warn = "?????";
    while (!go)
    {
        modify(f_acc_number, warn);

        cout << setw(50) << "Account Number: ";
        cin >> f_acc_number;

        if (!acc_checker(f_acc_number))
        {

            warn = "Invalid";
            modify(f_acc_number, warn);
            cout << setw(55) << "Wrong Account Number TRY AGAIN!";
            getch();
            f_acc_number = 0;
            warn = "?????";
        }
        else
        {
            warn = "Valid";

            edit_account(f_acc_number, warn);

            go = true;

            break;
        }
    }
}

#endif
