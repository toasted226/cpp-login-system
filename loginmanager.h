#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Account
{
    public:
        string username;
        string password;
        Account();
        Account(string _username, string _password);
};

//Implemented in accountcreator.cpp
vector<Account> readAccountsFromFile();
bool accountExists(string username, Account* account);
void create_account();
string getUsername(string account);
string getPassword(string account);

//Implemented in loginmanager.cpp
void startLoginManager();
