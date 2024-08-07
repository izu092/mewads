#ifndef transac_h
#define transac_h

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

void transfer_money(const int &acc_number, const int &depo_money);
bool acc_checker(int &acc_number);
bool balance_checker(const int &f_acc_number, const int &withdraw_money);
void trans_dipslay(const int &acc_number, const int &depo_money, const string &warn)
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

    if (acc_number == 0)
    {
        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
    }

    if (acc_number != 0)
    {
        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(28 - warn.size()) << warn << setw(19 - log10(acc_number) + 1) << "|" << endl;
    }
    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

    int num_size;
    if (depo_money >= 10)
    {
        num_size = 2;
    }
    if (depo_money >= 100)
    {
        num_size = 3;
    }
    if (depo_money >= 1000)
    {
        num_size = 4;
    }
    if (depo_money >= 10000)
    {
        num_size = 5;
    }
    if (depo_money < 10)
    {
        num_size = 1;
    }

    cout << setw(37) << "|\t DEPOSIT: " << depo_money << setw(55 - num_size) << "|" << endl;

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

void trans_ammount(const int &f_acc_number)
{
    int acc_number = 0;
    int depo_money = 0;
    bool go = false;
    bool error = false;
    string warn = "?????";
    while (!go)
    {
        trans_dipslay(acc_number, depo_money, warn);

        cout << setw(50) << "Account Number: ";
        cin >> acc_number;

        if (!acc_checker(acc_number))
        {

            warn = "Invalid";
            trans_dipslay(acc_number, depo_money, warn);
            cout << setw(55) << "Wrong Account Number TRY AGAIN!";
            getch();
            acc_number = 0;
            warn = "?????";
        }
        else
        {
            warn = "Valid";
            trans_dipslay(acc_number, depo_money, warn);
            while (!error)
            {
                cout << setw(55) << "ENTER AMOUNT TO DEPOSIT ";
                cin >> depo_money;

                if (balance_checker(f_acc_number, depo_money))
                {
                    trans_dipslay(acc_number, depo_money, warn);
                    cout << endl
                         << "\t\t\t\tInsuficient Balance" << endl
                         << endl;

                    string warn = "?????";
                }
                else
                {
                    trans_dipslay(acc_number, depo_money, warn);
                    deposit(acc_number, depo_money);
                    transfer_money(f_acc_number, depo_money);
                    error = true;
                    go = true;
                }
            }
        }
    }
}

#endif
