//
// Created by Youssef on 11/10/2022.
//
#include "BankingSystem.h"
#include <iostream>
using namespace std;

void Bank_Application::displayMenu()
{
    while(choice != 5){
        cout << "**************************************************" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. list Clients and accounts" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            listClients();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void Bank_Application::createAccount()
{
    client newClient;
    newClient.setAccount();
    clients.push_back(newClient);
    cout << "**************************************************\n";
    cout << "An account has been created with the following details: \n\n";
    newClient.displayAccount();
}

void Bank_Application::listClients()
{
    for (int i = 0; i < (int)clients.size(); i++)
    {
        cout << "*********************";
        cout << "Client " << i + 1;
        cout << "*********************\n\n";
        clients[i].displayAccount();
    }
}

void Bank_Application::deposit()
{
    cout << "Enter account ID: ";
    int accountID;
    cin >> accountID;

    cout << "Enter amount: ";
    float amount;
    cin >> amount;

    for (int i = 0; i < (int)clients.size(); i++)
    {
        if (clients[i].getAccountID() == accountID)
        {
            clients[i].deposit(amount);
            return;
        }
    }
    cout << "No Matching ID\n";
}

void Bank_Application::withdraw()
{
    cout << "Enter account ID: ";
    int accountID;
    cin >> accountID;

    cout << "Enter amount: ";
    float amount;
    cin >> amount;

    for (int i = 0; i < (int)clients.size(); i++)
    {
        if (clients[i].getAccountID() == accountID)
        {
            clients[i].withdraw(amount);
            return;
        }
    }
    cout << "No matching ID\n";
}
