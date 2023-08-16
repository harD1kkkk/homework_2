#include "Bank.h"
#include <iostream>

Bank::Bank(string& name, int maxClients)
    : bankName(name), maxClients(maxClients), numClients(0)
{
    clients = new Client[maxClients];
}

void Bank::addNewClient(string& name, int account, double initialBalance)
{
    if (numClients < maxClients)
    {
        clients[numClients] = Client(name, account, initialBalance);
        numClients++;
        cout << "New client added: " << name << " (Account: " << account << ")" << endl;
    }
    else
    {
        cout << "Bank is full, cannot add more clients." << endl;
    }
}

void Bank::removeClient(int account)
{
    for (int i = 0; i < numClients; i++)
    {
        if (clients[i].getAccountNumber() == account)
        {
            cout << "Client removed: " << clients[i].getName() << " (Account: " << clients[i].getAccountNumber() << ")" << endl;
            for (int j = i; j < numClients - 1; j++)
            {
                clients[j] = clients[j + 1];
            }
            numClients--;
            return;
        }
    }
    cout << "Client with account number " << account << " not found." << endl;
}

void Bank::deposit(int account, double amount)
{
    for (int i = 0; i < numClients; i++)
    {
        if (clients[i].getAccountNumber() == account)
        {
            clients[i].deposit(amount);
            cout << "Deposited " << amount << " to account " << account << ". New balance: " << clients[i].getBalance() << endl;
            return;
        }
    }
    cout << "Client with account number " << account << " not found." << endl;
}

void Bank::withdraw(int account, double amount)
{
    for (int i = 0; i < numClients; i++)
    {
        if (clients[i].getAccountNumber() == account)
        {
            clients[i].withdraw(amount);  
            cout << "Withdrawn " << amount << " from account " << account << ". New balance: " << clients[i].getBalance() << endl;
            return;
        }
    }
    cout << "Client with account number " << account << " not found." << endl;
}


void Bank::printClients()
{
    cout << "Clients of " << bankName << " bank:" << endl;
    for (int i = 0; i < numClients; i++)
    {
        cout << "Name: " << clients[i].getName() << ", Account: " << clients[i].getAccountNumber() << ", Balance: " << clients[i].getBalance() << endl;
    }
}

double Bank::getTotalBalance()
{
    double totalBalance = 0.0;
    for (int i = 0; i < numClients; i++)
    {
        totalBalance += clients[i].getBalance();
    }
    return totalBalance;
}
