#ifndef remoceaccount_h
#define remoceaccount_h

#include "database.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <cmath>

using namespace std;

void remove_account(const int &acc_number);

void remove_display(const int &f_acc_number, const string &warn)
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

    cout << setw(58) << "|\t\t\t   == REMOVE ACCOUNT ==\t\t\t\t|\n";
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

bool opt_closeaccount(const int &f_acc_number, const string &warn)
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
    cout << setw(58) << "|\t\t\t   == REMOVE ACCOUNT ==\t\t\t\t|\n";
    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

    cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(25 - 10) << warn << setw(23 - warn.size()) << "|" << endl;
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

    cout << "\t\t\t\tKindly select option 1 to proceed with the deletion process,\n \t\t\t\tor choose option 2 to abort." << endl;
    char opt;
    cout << "\t\t\t\tChoose: ";
    cin >> opt;

    if (opt == '2')
    {
        return false;
    }
    if (opt == '1')
    {
        cout << "\n\n \t\t\t== Account with account number " << f_acc_number << " has been successfully deleted. == " << endl;
        return true;
    }
    return false;
}
void close_account()
{
    int f_acc_number = 0;

    bool go = false;
    string warn = "?????";
    while (!go)
    {
        remove_display(f_acc_number, warn);

        cout << setw(50) << "Account Number: ";
        cin >> f_acc_number;

        if (!acc_checker(f_acc_number))
        {

            warn = "Invalid";
            remove_display(f_acc_number, warn);
            cout << setw(55) << "Wrong Account Number TRY AGAIN!";
            getch();
            f_acc_number = 0;
            warn = "?????";
        }
        else
        {
            warn = "Valid";
            if (opt_closeaccount(f_acc_number, warn))
            {
                remove_account(f_acc_number);
                go = true;
            }
            else
            {
                break;
            }
        }
    }
}

#endif
