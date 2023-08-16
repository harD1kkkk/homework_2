// zavd_68.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Bank.h"
#include <iostream>

using namespace std;

int main()
{
    string bankName;
    cout << "Enter bank name: ";
    cin >> bankName;

    int maxClients;
    cout << "Enter maximum number of clients: ";
    cin >> maxClients;

    Bank bank(bankName, maxClients);

    string clientName;
    int accountNumber;
    double initialBalance;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Add Client\n";
        cout << "2. Delete Client\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Print Clients\n";
        cout << "6. Print Total Balance\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting...";
            return 0;
        case 1:
            cout << "Enter client name: ";
            cin >> clientName;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            bank.addNewClient(clientName, accountNumber, initialBalance);
            break;
        case 2:
            cout << "Enter account number of client to delete: ";
            cin >> accountNumber;
            bank.removeClient(accountNumber);
            break;
        case 3:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter deposit amount: ";
            double depositAmount;
            cin >> depositAmount;
            bank.deposit(accountNumber, depositAmount);
            break;
        case 4:
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter withdrawal amount: ";
            double withdrawalAmount;
            cin >> withdrawalAmount;
            bank.withdraw(accountNumber, withdrawalAmount);
            break;
        case 5:
            bank.printClients();
            break;
        case 6:
            cout << "Total Balance: " << bank.getTotalBalance() << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    }
}
