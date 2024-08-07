#include "database.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "transac.h"

using namespace std;

bool set_up(int &acc_number)
{
    ifstream inFile("data.txt");
    if (inFile.is_open())
    {
        int storedAcc_number, storedBalance;
        string storedFull_name, storedCellphone_num, storedEmail, storedAddress, storedPin_number, storedAge;
        char storedGender;
        while (inFile >> storedAcc_number)
        {
            getline(inFile >> ws, storedFull_name);
            inFile >> storedAge >> storedGender >> storedCellphone_num >> storedEmail >> storedBalance >> storedPin_number;
            getline(inFile >> ws, storedAddress);

            if (storedAcc_number == acc_number)
            {
                if (storedPin_number == "none")
                {
                    return true;
                }
            }
        }

        inFile.close();

        return false;
    }
    else
    {
        cout << "Error: Unable to open data file." << endl;
        return false;
    }
}

void withdraw_inq(const int &f_acc_number, const string &warn)
{
    int withdraw_money = 0;

    withdraw(withdraw_money, f_acc_number, warn);

    cout << "\t\t\t\tENTER AMOUNT TO WITHDRAW ";

    cin >> withdraw_money;
    if (balance_checker(f_acc_number, withdraw_money))
    {
        cout << endl
             << "\t\t\t\tInsuficient Balance" << endl;
    }
    else
    {
        withdraw(withdraw_money, f_acc_number, warn);
    }
}

void user_menu(const int &f_acc_number, const string &warn)
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
    cout << setw(61) << "|\t\t\t      == User Menu ==      \t\t\t|\n";

    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

    if (f_acc_number == 0)
    {
        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
    }

    if (f_acc_number != 0)
    {
        if (warn == "Invalid")
        {
            cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(19 - log10(f_acc_number) + 1) << "|" << endl;
        }
        if (warn == "Valid")
        {
            cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(17 - log10(f_acc_number) + 1) << "|" << endl;
        }
    }

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

int main()
{
    char opt;
    string password;

    bool go = false;
    string pin;
    bool flow = false;
    string warn = "?????";
    int f_acc_number = 0;
    while (true)
    {

        user_menu(f_acc_number, warn);

        cout << setw(57) << "INPUT YOUR ACCOUNT NUMBER: ";
        cin >> f_acc_number;
        if (!acc_checker(f_acc_number))
        {
            warn = "Invalid";
            user_menu(f_acc_number, warn);
            cout << "\t\t\t\tApologies, it appears the account number provided is invalid." << endl;
            cout << "\t\t\t\tPlease Select any Key to Continue ";
            getch();
            f_acc_number = 0;
            warn = "?????";
        }
        else
        {
            warn = "Valid";

            user_menu(f_acc_number, warn);
            cout << "\t\t\t\tPlease Select any Key to Continue";
            getch();
            if (set_up(f_acc_number))
            {
                setup_pin(f_acc_number, warn);
                cout << "\t\t\t\tPlease Select any Key to Continue";
                getch();
                warn = "?????";
                f_acc_number = 0;
            }
            else
            {

                while (!go)
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
                    cout << setw(61) << "|\t\t\t      == ATM LOGIN ==      \t\t\t|\n";

                    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                    if (f_acc_number == 0)
                    {
                        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
                    }

                    if (f_acc_number != 0)
                    {
                        if (warn == "Invalid")
                        {
                            cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(19 - log10(f_acc_number) + 1) << "|" << endl;
                        }
                        if (warn == "Valid")
                        {
                            cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(17 - log10(f_acc_number) + 1) << "|" << endl;
                        }
                    }
                    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                    cout << setw(75) << "|\t\t   Please Enter a 4-digit PIN of your account: " << setw(10) << "|" << endl;
                    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                    cout << setw(41) << "|\t\t\t\t[] [] [] []" << setw(30) << "|" << endl;

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

                    cout << "\t\t\t\t\t\tEnter Your Pin: ";
                    cin >> pin;
                    if (pin_pass(pin, f_acc_number))
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
                        cout << setw(61) << "|\t\t\t      == ATM LOGIN ==      \t\t\t|\n";

                        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                        if (f_acc_number == 0)
                        {
                            cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
                        }

                        if (f_acc_number != 0)
                        {
                            if (warn == "Invalid")
                            {
                                cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(19 - log10(f_acc_number) + 1) << "|" << endl;
                            }
                            if (warn == "Valid")
                            {
                                cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - warn.size()) << warn << setw(17 - log10(f_acc_number) + 1) << "|" << endl;
                            }
                        }
                        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                        cout << setw(66) << "|\t\t   Your Have Been Successfully Log In!" << setw(19) << "|" << endl;

                        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                        cout << setw(41) << "|\t\t\t\t *  *  *  *" << setw(30) << "|" << endl;

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
                        cout << "\t\t\t\tPlease Select any Key to Continue";
                        getch();
                        go = true;
                    }
                    else
                    {
                        cout << "\t\t\t\tInvalid Pin" << endl;
                        cout << "\t\t\t\tPlease Select any Key to try again ";
                        getch();
                    }
                }
                while (!flow)
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

                    cout << setw(48) << "|\t[1] Check Balance\t\t\t\t" << setw(17) << "|" << endl;
                    cout << setw(43) << "|\t[2] Withdraw\t\t\t\t" << setw(25) << "|" << endl;

                    cout << setw(45) << "|\t[3] Change Pin\t\t\t\t" << setw(25) << "|" << endl;
                    cout << setw(48) << "|\t[4] Transfer Funds\t\t\t" << setw(25) << "|" << endl;
                    cout << setw(39) << "|\t[5] Exit\t\t\t\t" << setw(25) << "|" << endl;

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

                    switch (opt)
                    {
                    case '1':
                        system("cls");
                        balance(f_acc_number, warn);
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

                        break;

                    case '2':

                        system("cls");
                        withdraw_inq(f_acc_number, warn);
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
                        break;

                    case '3':
                        system("cls");
                        setup_pin(f_acc_number, warn);
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
                        break;

                    case '4':
                        trans_ammount(f_acc_number);
                        getch();
                        break;

                    case '5':
                        warn = "?????";
                        f_acc_number = 0;
                        flow = true;
                        break;
                    }
                }
                flow = false;
                go = false;
            }
        }
    }

    return 0;
}