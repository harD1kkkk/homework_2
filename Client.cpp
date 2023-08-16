#include "Client.h"

Client::Client()
    : name(""), accountNumber(0), balance(0.0)
{
}

Client::Client(string& clientName, int account, double initialBalance)
    : name(clientName), accountNumber(account), balance(initialBalance)
{
}

string Client::getName()
{
    return name;
}

int Client::getAccountNumber()
{
    return accountNumber;
}

double Client::getBalance()
{
    return balance;
}

void Client::deposit(double amount)
{
    balance += amount;
}

void Client::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
}
