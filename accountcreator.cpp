#include <iostream>
#include <vector>
#include "loginmanager.h"
#include "fileio.h"
#include "security.h"

using namespace std;

Account::Account()
{
    username = "";
    password = "";
}

Account::Account(string _username, string _password)
{
    username = _username;
    password = _password;
}

string getUsername(string account)
{
    return account.substr(0, account.find(' '));
}

string getPassword(string account)
{
    return account.substr(account.find(' ') + 1, account.length());
}

vector<Account> readAccountsFromFile()
{
    vector<string> accountsList;
    vector<Account> accounts;
    FileIO file("accounts.txt");
    accountsList = file.ReadFile();

    for(int i = 0; i < accountsList.size(); i++)
    {
        string username = getUsername(accountsList[i]);
        string password = getPassword(accountsList[i]);
        accounts.push_back(Account(username, password));
    }

    return accounts;
}

bool accountExists(string username, Account* pAccount)
{
    vector<Account> accounts = readAccountsFromFile();

    for(int i = 0; i < accounts.size(); i++)
    {
        if(username == accounts[i].username)
        {
            if(pAccount != 0)
            {
                *pAccount = accounts[i];
            }
            return true;
        }
    }

    return false;
}

void create_account()
{
    string username, password, passRetry;

    cout << "Create username: ";
    getline(cin, username);
    Account temp;

    if(username.length() < 1)
    {
        cout << "-- Please enter a username." << endl;
        create_account();
    }
    else if (accountExists(username, &temp))
    {
        cout << "-- The account with the username '" << username << "' already exists." << endl;
        create_account();
    }

    cout << "Create password: ";
    getline(cin, password);

    if(password.length() < 8)
    {
        cout << "-- Password must have a minimum of 8 characters!" << endl;
        create_account();
    }

    cout << "Re-enter password: ";
    getline(cin, passRetry);

    if(password != passRetry)
    {
        cout << "-- Passwords must match!" << endl;
        create_account();
    }

    string hashedPassword;
    computeHash(password, hashedPassword);

    FileIO writer("accounts.txt");
    writer.WriteFile(username + " " + hashedPassword);

    cout << "Account created successfully!" << endl;
    startLoginManager();
}
