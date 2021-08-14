#include <iostream>
#include <vector>
#include "loginmanager.h"
#include "security.h"

using namespace std;

void login();

void startLoginManager()
{
    int choice;
    cout << "Welcome to Keagan's login system!" << endl;
    cout << "1) Create an account\n";
    cout << "2) Log in\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    if(choice == 1)
    {
        create_account();
    }
    else if(choice == 2)
    {
        login();
    }
    else
    {
        cout << "Quitting." << endl;
    }
}

void login()
{
    vector<Account> accounts = readAccountsFromFile();
    Account matchingAccount;
    string username, password;

    cout << "Enter your username: ";
    getline(cin, username);

    if(accountExists(username, &matchingAccount))
    {
        cout << "Enter your password: ";
        getline(cin, password);
        string hashedPassword;
        computeHash(password, hashedPassword);

        if(hashedPassword == matchingAccount.password)
        {
            cout << "Login successful." << endl;
        }
        else 
        {
            cout << "-- The password you have entered is incorrect." << endl;
            login();
        }
    }
    else
    {
        cout << "The account with the username '" << username << "' does not exist." << endl;
        login();
    }
}
