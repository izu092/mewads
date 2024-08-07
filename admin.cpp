
#include "database.h"
#include "deposit.h"
#include "balance.h"
#include "addaccount.h"
#include "removeaccount.h"
#include "modifyacc.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <cmath>

int main()
{

    char opt;
    do
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

        cout << setw(61) << "|\t\t\t      == Main Menu ==      \t\t\t|\n";
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

        cout << setw(46) << "|\t[1] New Account\t\t\t\t" << setw(25) << "|" << endl;
        cout << setw(50) << "|\t[2] Deposit Account\t\t\t\t" << setw(17) << "|" << endl;

        cout << setw(50) << "|\t[3] Balance Inquiry\t\t\t\t" << setw(17) << "|" << endl;
        cout << setw(57) << "|\t[4] All Account Holder List\t\t\t" << setw(17) << "|" << endl;
        cout << setw(51) << "|\t[5] Close An Account\t\t\t\t" << setw(17) << "|" << endl;
        cout << setw(52) << "|\t[6] Modify An Account\t\t\t\t" << setw(17) << "|" << endl;
        cout << setw(39) << "|\t[7] Exit\t\t\t\t" << setw(25) << "|" << endl;

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

        cout << setw(50) << "\tENTER YOUR CHOICE: ";
        cin >> opt;

        if (opt == '1')
        {

            new_account();

            cout << endl;
            cout << setw(60) << "===========================" << endl;
            cout << setw(40) << "1. MENU" << endl;
            cout << setw(40) << "2. EXIT" << endl;
            cout << setw(52) << "ENTER YOUR CHOICE: ";
            cin >> opt;
            if (opt == '2')
            {
                break;
            }
        }
        else if (opt == '2')
        {
            system("cls");
            depo_ammount();
            cout << endl;
            cout << setw(60) << "===========================" << endl;
            cout << setw(40) << "1. MENU" << endl;
            cout << setw(40) << "2. EXIT" << endl;
            cout << setw(52) << "ENTER YOUR CHOICE: ";
            cin >> opt;
            if (opt == '2')
            {
                break;
            }
        }
        else if (opt == '3')
        {
            system("cls");
            balance_inq();
            cout << endl;
            cout << setw(60) << "===========================" << endl;
            cout << setw(40) << "1. MENU" << endl;
            cout << setw(40) << "2. EXIT" << endl;
            cout << setw(52) << "ENTER YOUR CHOICE: ";
            cin >> opt;
            if (opt == '2')
            {
                break;
            }
        }
        else if (opt == '4')
        {

            all_acc();
            cout << endl;
            cout << setw(60) << "===========================" << endl;
            cout << setw(40) << "1. MENU" << endl;
            cout << setw(40) << "2. EXIT" << endl;
            cout << setw(52) << "ENTER YOUR CHOICE: ";
            cin >> opt;
            if (opt == '2')
            {
                break;
            }
        }
        else if (opt == '5')
        {

            close_account();
            cout << endl;
            cout << setw(60) << "===========================" << endl;
            cout << setw(40) << "1. MENU" << endl;
            cout << setw(40) << "2. EXIT" << endl;
            cout << setw(52) << "ENTER YOUR CHOICE: ";
            cin >> opt;
            if (opt == '2')
            {
                break;
            }
        }
        else if (opt == '6')
        {

            modify_acc();
            cout << endl;
            cout << setw(60) << "===========================" << endl;
            cout << setw(40) << "1. MENU" << endl;
            cout << setw(40) << "2. EXIT" << endl;
            cout << setw(52) << "ENTER YOUR CHOICE: ";
            cin >> opt;
            if (opt == '2')
            {
                break;
            }
        }
    } while (opt != '7');

    return 0;
}