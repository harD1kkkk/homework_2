#pragma once

#include <string>
#include "Client.h"
using namespace std;

class Bank
{
private:
    string bankName;
    int maxClients;
    int numClients;

    Client* clients;

public:
    Bank(string& name, int maxClients);

    void addNewClient(string& name, int account, double initialBalance);
    void removeClient(int account);
    void deposit(int account, double amount);
    void withdraw(int account, double amount);
    void printClients();
    double getTotalBalance();
};
