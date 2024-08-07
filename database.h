#ifndef data_h
#define data_h

#include "deposit.h"
#include "balance.h"
#include "removeaccount.h"
#include "transac.h"

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

    class acc_managament
    {
    public:
        string full_name, email, address;
        int age;
        char gender;
        int acc_number;
        string cellphone_num;
        string pin_number = "none";
        int balance = 0;
    };

    void add_account(const string &full_name, const string &age, const char &gender, const string &cellphone_num, const string &email, const string &address, const int &acc_number, const int &balance, const string &pin_number)
    {
        ofstream outFile("data.txt", ios::app);
        if (outFile.is_open())
        {
            outFile << acc_number << endl
                    << " " << full_name << endl
                    << age << " " << gender << " " << cellphone_num << " " << email << " " << balance << " " << pin_number << endl
                    << address << endl;
            outFile.close();
        }
        else
        {
            cout << "Error: Unable to open data file." << endl;
        }
    }

    void deposit(const int &acc_number, const int &depo_money)
    {
        ifstream inFile("data.txt");
        if (inFile.is_open())
        {
            int storedAcc_number, storedBalance;
            string storedFull_name, storedCellphone_num, storedEmail, storedAddress, storedPin_number, storedAge;
            char storedGender;
            ofstream tempFile("temp.txt");
            if (tempFile.is_open())
            {
                while (inFile >> storedAcc_number)
                {
                    getline(inFile >> ws, storedFull_name);
                    inFile >> storedAge >> storedGender >> storedCellphone_num >> storedEmail >> storedBalance >> storedPin_number;
                    getline(inFile >> ws, storedAddress);
                    if (storedAcc_number == acc_number)
                    {
                        storedBalance += depo_money;
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                        cout << setw(50) << "== Deposit of " << depo_money << " has been successfully added ==" << endl;
                    }
                    else
                    {
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                remove("data.txt");
                rename("temp.txt", "data.txt");
            }
        }
        else
        {
            cout << "Error!" << endl;
            getch();
        }
    }

    void balance(const int &acc_number, const string &warn)
    {
        system("cls");
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
                    cout << setw(59) << "|\t\t\t      == BALANCE ==      \t\t\t|\n";
                    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                    cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(25 - 10) << warn << setw(23 - warn.size()) << "|" << endl;
                    cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                    int num_size;
                    if (storedBalance >= 10)
                    {
                        num_size = 2;
                    }
                    if (storedBalance >= 100)
                    {
                        num_size = 3;
                    }
                    if (storedBalance >= 1000)
                    {
                        num_size = 4;
                    }
                    if (storedBalance >= 10000)
                    {
                        num_size = 5;
                    }
                    if (storedBalance < 10)
                    {
                        num_size = 1;
                    }

                    cout << setw(37) << "|\t BALANCE: " << storedBalance << setw(55 - num_size) << "|" << endl;

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
            }
            inFile.close();
        }
        else
        {
            cout << "Error!" << endl;
            getch();
        }
    }

    bool balance_checker(const int &f_acc_number, const int &withdraw_money)
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

                if (storedAcc_number == f_acc_number)
                {
                    if (storedBalance == 0)
                    {
                        return true;
                    }
                    else if (storedBalance < withdraw_money)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
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

    void all_acc()
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

        cout << setw(72) << "|\t\t          == ALL ACOUNT HOLDER ==      \t\t\t|\n";
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
        cout << setw(27);
        for (int i = 0; i < 70; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

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

                int num_size;

                if (storedBalance >= 10)
                {
                    num_size = 2;
                }
                if (storedBalance >= 100)
                {
                    num_size = 3;
                }
                if (storedBalance >= 1000)
                {
                    num_size = 4;
                }
                if (storedBalance >= 10000)
                {
                    num_size = 5;
                }
                if (storedBalance < 10)
                {
                    num_size = 1;
                }

                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                cout << setw(48) << "|      ACCOUNT NUMBER: " << storedAcc_number << setw(49 - 10) << "|" << endl;
                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                cout << setw(60) << "|      Name of the Account Holder: " << storedFull_name << setw(37 - storedFull_name.size()) << "|" << endl;

                cout << setw(59) << "|      Age of The Account Holder: " << storedAge << setw(38 - storedAge.size()) << "|" << endl;

                cout << setw(68) << "|      Gender of The Account Holder (M/F): " << storedGender << setw(29 - 1) << "|" << endl;

                cout << setw(69) << "|      Mobile Number of The Account Holder: " << storedCellphone_num << setw(28 - 11) << "|" << endl;

                cout << setw(61) << "|      Email of the Account Holder: " << storedEmail << setw(36 - storedEmail.size()) << "|" << endl;

                cout << setw(63) << "|      Address of the Account Holder: " << storedAddress << setw(34 - storedAddress.size()) << "|" << endl;

                cout << setw(63) << "|      Balance of the Account Holder: " << storedBalance << setw(34 - num_size) << "|" << endl;

                cout << setw(66) << "|      Pin Number of the Account Holder: " << storedPin_number << setw(31 - 4) << "|" << endl;

                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                cout << setw(27);
                for (int i = 0; i < 70; i++)
                {
                    cout << "=";
                }
                cout << endl;
            }
            inFile.close();
        }
        else
        {
            cerr << "Error: Unable to open data file." << endl;
        }
    }

    void remove_account(const int &acc_number)
    {

        ifstream inFile("data.txt");
        if (inFile.is_open())
        {
            int storedAcc_number, storedBalance;
            string storedFull_name, storedCellphone_num, storedEmail, storedAddress, storedPin_number, storedAge;
            char storedGender;

            ofstream tempFile("temp.txt");
            if (tempFile.is_open())
            {

                while (inFile >> storedAcc_number)
                {
                    getline(inFile >> ws, storedFull_name);
                    inFile >> storedAge >> storedGender >> storedCellphone_num >> storedEmail >> storedBalance >> storedPin_number;
                    getline(inFile >> ws, storedAddress);

                    if (storedAcc_number == acc_number)
                    {

                        continue;
                    }

                    else
                    {
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                remove("data.txt");
                rename("temp.txt", "data.txt");
            }
        }
    }

    void edit_account(const int &acc_number, const string &warn)
    {

        ifstream inFile("data.txt");
        if (inFile.is_open())
        {
            int storedAcc_number, storedBalance;
            string storedFull_name, storedCellphone_num, storedEmail, storedAddress, storedPin_number, storedAge;
            char storedGender, opt;

            string new_storedFull_name;
            string new_storedAge;
            char new_storedGender;
            string new_cellphone_num;
            string new_storedEmail;
            string new_storedAddress;

            ofstream tempFile("temp.txt");
            if (tempFile.is_open())
            {

                while (inFile >> storedAcc_number)
                {
                    getline(inFile >> ws, storedFull_name);
                    inFile >> storedAge >> storedGender >> storedCellphone_num >> storedEmail >> storedBalance >> storedPin_number;
                    getline(inFile >> ws, storedAddress);
                    if (storedAcc_number == acc_number)
                    {
                        bool valid = false;

                        while (!valid)
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

                            if (acc_number == 0)
                            {
                                cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
                            }

                            if (acc_number != 0)
                            {
                                cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(17 - log10(acc_number) + 1) << "|" << endl;
                            }

                            cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                            cout << setw(60) << "|  [1] Name of the Account Holder: " << storedFull_name << setw(37 - storedFull_name.size()) << "|" << endl;

                            cout << setw(59) << "|  [2] Age of The Account Holder: " << storedAge << setw(38 - storedAge.size()) << "|" << endl;

                            cout << setw(68) << "|  [3] Gender of The Account Holder (M/F): " << storedGender << setw(29 - 1) << "|" << endl;

                            cout << setw(69) << "|  [4] Mobile Number of The Account Holder: " << storedCellphone_num << setw(28 - 11) << "|" << endl;

                            cout << setw(61) << "|  [5] Email of the Account Holder: " << storedEmail << setw(36 - storedEmail.size()) << "|" << endl;

                            cout << setw(63) << "|  [6] Address of the Account Holder: " << storedAddress << setw(34 - storedAddress.size()) << "|" << endl;

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

                            cout << "\t\t\t\tPlease select the option you want to change (1-6): ";
                            cin >> opt;

                            if (opt != '1' && opt != '2' && opt != '3' && opt != '4' && opt != '5' && opt != '6')
                            {
                                cout << "\t\t\t\tInvalid option. Please enter a number between 1 and 6." << endl;
                                cout << "\t\t\t\tPress any key to try again...";
                                getch();
                            }

                            else
                            {

                                if (opt == '1')
                                {
                                    cout << "\t\t\t\t[1] Name: ";
                                    cin.ignore();
                                    getline(cin, new_storedFull_name);

                                    storedFull_name = new_storedFull_name;
                                    tempFile << storedAcc_number << endl
                                            << " " << storedFull_name << endl
                                            << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                            << storedAddress << endl;
                                    valid = true;
                                }

                                else if (opt == '2')
                                {

                                    cout << "\t\t\t\t[2] Age: ";
                                    cin >> new_storedAge;

                                    storedAge = new_storedAge;
                                    tempFile << storedAcc_number << endl
                                            << " " << storedFull_name << endl
                                            << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                            << storedAddress << endl;
                                    valid = true;
                                }

                                else if (opt == '3')
                                {

                                    cout << "\t\t\t\t[3] Gender: ";
                                    cin >> new_storedGender;

                                    storedGender = new_storedGender;
                                    tempFile << storedAcc_number << endl
                                            << " " << storedFull_name << endl
                                            << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                            << storedAddress << endl;
                                    valid = true;
                                }

                                else if (opt == '4')
                                {

                                    cout << "\t\t\t\t[4] Cellphone Number: ";
                                    cin >> new_cellphone_num;

                                    storedCellphone_num = new_cellphone_num;
                                    tempFile << storedAcc_number << endl
                                            << " " << storedFull_name << endl
                                            << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                            << storedAddress << endl;
                                    valid = true;
                                }

                                else if (opt == '5')
                                {

                                    cout << "\t\t\t\t[5] Email: ";
                                    cin >> new_storedEmail;

                                    storedEmail = new_storedEmail;
                                    tempFile << storedAcc_number << endl
                                            << " " << storedFull_name << endl
                                            << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                            << storedAddress << endl;
                                    valid = true;
                                }

                                else if (opt == '6')
                                {

                                    cout << "\t\t\t\t[6]Address: ";
                                    cin.ignore();
                                    getline(cin, new_storedAddress);

                                    storedAddress = new_storedAddress;
                                    tempFile << storedAcc_number << endl
                                            << " " << storedFull_name << endl
                                            << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                            << storedAddress << endl;
                                    valid = true;
                                }

                                else
                                {

                                    tempFile << storedAcc_number << endl
                                            << " " << storedFull_name << endl
                                            << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                            << storedAddress << endl;
                                }
                            }
                        }
                    }
                    else
                    {
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                remove("data.txt");
                rename("temp.txt", "data.txt");
            }
        }
    }

    // user

    bool acc_checker(int &acc_number)
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
                    return true;
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

    void setup_pin(const int &acc_number, const string &warn)
    {

        ifstream inFile("data.txt");
        if (inFile.is_open())
        {
            int storedAcc_number, storedBalance;
            string storedFull_name, storedCellphone_num, storedEmail, storedAddress, storedPin_number, storedAge;
            char storedGender;

            string new_pin;

            ofstream tempFile("temp.txt");
            if (tempFile.is_open())
            {

                while (inFile >> storedAcc_number)
                {
                    getline(inFile >> ws, storedFull_name);
                    inFile >> storedAge >> storedGender >> storedCellphone_num >> storedEmail >> storedBalance >> storedPin_number;
                    getline(inFile >> ws, storedAddress);

                    if (storedAcc_number == acc_number)
                    {
                        while (true)
                        {
                            system("cls");
                            bool digit_check = false;
                            bool size_check = false;

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
                            cout << setw(63) << "|\t\t\t    == ATM PIN SETUP ==      \t\t\t|\n";

                            cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                            cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                            if (acc_number == 0)
                            {
                                cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
                            }

                            if (acc_number != 0)
                            {
                                if (warn == "Invalid")
                                {
                                    cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(19 - log10(acc_number) + 1) << "|" << endl;
                                }
                                if (warn == "Valid")
                                {
                                    cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(17 - log10(acc_number) + 1) << "|" << endl;
                                }
                            }
                            cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                            cout << setw(75) << "|\t\t Please choose a 4-digit PIN for your account: " << setw(10) << "|" << endl;
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

                            cin.ignore();
                            cout << "\t\t\t\t\t\tEnter Your Pin: ";
                            cin >> new_pin;

                            for (int i = 0; i < 4; i++)
                            {
                                if (!isdigit(new_pin[i]))
                                {
                                    digit_check = true;
                                    break;
                                }
                            }

                            if (new_pin.size() != 4)
                            {
                                size_check = true;
                            }

                            if (digit_check)
                            {
                                cout << "\t\t\tError Please Try Again Numbers Only!" << endl;
                                getch();
                            }
                            if (size_check)
                            {
                                cout << "\t\t\tWarning! Your PIN should consist of exactly 4 digits." << endl;
                                getch();
                            }

                            else
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
                                cout << setw(63) << "|\t\t\t    == ATM PIN SETUP ==      \t\t\t|\n";

                                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                                if (acc_number == 0)
                                {
                                    cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(17) << "|" << endl;
                                }

                                if (acc_number != 0)
                                {
                                    if (warn == "Invalid")
                                    {
                                        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(19 - log10(acc_number) + 1) << "|" << endl;
                                    }
                                    if (warn == "Valid")
                                    {
                                        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << acc_number << setw(30 - warn.size()) << warn << setw(17 - log10(acc_number) + 1) << "|" << endl;
                                    }
                                }
                                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                                cout << setw(51) << "|\t\t\t      Congratulations!" << setw(10) << "\t\t\t|" << endl;
                                cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                                cout << setw(85) << "|\t  Your PIN has been successfully set up for your account. " << setw(7) << "|" << endl;

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

                                storedPin_number = new_pin;
                                tempFile << storedAcc_number << endl
                                        << " " << storedFull_name << endl
                                        << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                        << storedAddress << endl;

                                break;
                            }
                        }
                    }
                    else
                    {
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                remove("data.txt");
                rename("temp.txt", "data.txt");
            }
        }
    }

    bool pin_pass(string &pin, const int &f_acc_number)
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

                if (storedAcc_number == f_acc_number && storedPin_number == pin)
                {
                    inFile.close();
                    return true;
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

    void withdraw(const int &withdraw_money, const int &f_acc_number, const string &warn)
    {
        ifstream inFile("data.txt");
        if (inFile.is_open())
        {
            int storedAcc_number, storedBalance;
            string storedFull_name, storedCellphone_num, storedEmail, storedAddress, storedPin_number, storedAge;
            char storedGender;
            ofstream tempFile("temp.txt");
            if (tempFile.is_open())
            {
                while (inFile >> storedAcc_number)
                {
                    getline(inFile >> ws, storedFull_name);
                    inFile >> storedAge >> storedGender >> storedCellphone_num >> storedEmail >> storedBalance >> storedPin_number;
                    getline(inFile >> ws, storedAddress);
                    if (storedAcc_number == f_acc_number)
                    {
                        storedBalance -= withdraw_money;
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;

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

                        cout << setw(60) << "|\t\t\t      == WITHDRAW ==      \t\t\t|\n";
                        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;

                        cout << setw(49) << "|\t USER ACCOUNT NUMBER: " << f_acc_number << setw(30 - 7) << warn << setw(19 - log10(f_acc_number) + 1) << "|" << endl;
                        cout << "                         |\t\t\t\t\t\t\t\t\t|" << endl;
                        int num_size;

                        if (withdraw_money < 10)
                        {
                            num_size = 1;
                            cout << setw(38) << "|\t WITHDRAW: " << withdraw_money << setw(54 - num_size) << "|" << endl;
                        }

                        else
                        {
                            cout << setw(38) << "|\t WITHDRAW: " << withdraw_money << setw(60 - log10(f_acc_number) + 1) << "|" << endl;
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
                    else
                    {
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                remove("data.txt");
                rename("temp.txt", "data.txt");
            }
        }
        else
        {
            cout << "Error!" << endl;
            getch();
        }
    }

    void transfer_money(const int &f_account_number, const int &depo_money)
    {
        ifstream inFile("data.txt");
        if (inFile.is_open())
        {

            int storedAcc_number, storedBalance;
            string storedFull_name, storedCellphone_num, storedEmail, storedAddress, storedPin_number, storedAge;
            char storedGender;

            ofstream tempFile("temp.txt");
            if (tempFile.is_open())
            {
                while (inFile >> storedAcc_number)
                {
                    getline(inFile >> ws, storedFull_name);
                    inFile >> storedAge >> storedGender >> storedCellphone_num >> storedEmail >> storedBalance >> storedPin_number;
                    getline(inFile >> ws, storedAddress);
                    if (storedAcc_number == f_account_number)
                    {

                        storedBalance -= depo_money;
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                    }
                    else
                    {
                        tempFile << storedAcc_number << endl
                                << " " << storedFull_name << endl
                                << storedAge << " " << storedGender << " " << storedCellphone_num << " " << storedEmail << " " << storedBalance << " " << storedPin_number << endl
                                << storedAddress << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                remove("data.txt");
                rename("temp.txt", "data.txt");
            }
        }
        else
        {
            cout << "Error!" << endl;
            getch();
        }
    }

#endif