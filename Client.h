#pragma once

#include <string>
using namespace std;

class Client
{
private:
    string name;
    int accountNumber;
    double balance;

public:
    Client();
    Client(string& clientName, int account, double initialBalance);

    string getName();
    int getAccountNumber();
    double getBalance();
    void deposit(double amount);
    void withdraw(double amount);  
};
