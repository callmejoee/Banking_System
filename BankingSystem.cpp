//
// Created by Youssef on 11/10/2022.
//
#include "BankingSystem.h"
#include <iostream>

using namespace std;

bankAccount::bankAccount()
{
    accountID = 0;
    balance = 0;
}

bankAccount::bankAccount(int accountID, float balance)
{
    this->accountID = accountID;
    this->balance = balance;
}

void bankAccount::deposit(float amount)
{
    balance += amount;
}

void bankAccount::withdraw(float amount)
{
    balance -= amount;
}

void bankAccount::display()
{
    cout << "Account ID: " << accountID << endl;
    cout << "Balance: " << balance << endl;
}

void bankAccount::set_accountID(int accountID)
{
    this->accountID = accountID;
}

void bankAccount::set_balance(float balance)
{
    this->balance = balance;
}
int bankAccount::get_accountID()
{
    return accountID;
}
float bankAccount::get_balance()
{
    return balance;
}

savingsAccount::savingsAccount() : bankAccount()
{
    set_accountID(0);
    set_balance(1000);
}
void savingsAccount::set_balance(float balance)
{
    if (balance >= 1000)
    {
        bankAccount::set_balance(balance);
    }
    while (balance < 1000)
    {
        cout << "Balance must be greater than 1000" << endl;
        cin >> balance;
        bankAccount::set_balance(balance);
    }
}

void savingsAccount::withdraw(float amount)
{
    if (bankAccount::get_balance() - amount < 1000)
    {
        cout << "Cannot withdraw more than minimum balance" << endl;
    }
    else
    {
        bankAccount::set_balance(get_balance() - amount);
    }
}

void savingsAccount::deposit(float amount)
{
    if (amount >= 100)
    {
        bankAccount::set_balance(get_balance() + amount);
    }
    else
    {
        cout << "Cannot deposit less than 100" << endl;
    }
}

void savingsAccount::display()
{
    cout << "Account ID: " << get_accountID() << endl;
    cout << "Balance: " << get_balance() << endl;
}

savingsAccount::savingsAccount(int accountID, float balance) : bankAccount(accountID, balance)
{
    set_balance(balance);
}

client::client()
{
    name = "";
    address = "";
    phone = "";
}

client::client(string name, string address, string phone)
{
    this->name = name;
    this->address = address;
    this->phone = phone;
}

void client::set_name(string name)
{
    this->name = name;
}

void client::set_address(string address)
{
    this->address = address;
}

void client::set_phone(string phone)
{
    this->phone = phone;
}

string client::get_name()
{
    return name;
}

string client::get_address()
{
    return address;
}
void client::set_basic_balance(float balance)
{
    basicAccount.set_balance(balance);
}
void client::set_savings_balance(float balance)
{
    savingsAccount.set_balance(balance);
}
void client::display_basic()
{
    basicAccount.display();
}
void client::display_savings()
{
    savingsAccount.display();
}
void client::basic_deposit(float amount)
{
    basicAccount.deposit(amount);
}
void client::savings_deposit(float amount)
{
    savingsAccount.deposit(amount);
}
void client::basic_withdraw(float amount)
{
    basicAccount.withdraw(amount);
}
void client::savings_withdraw(float amount)
{
    savingsAccount.withdraw(amount);
}
string client::get_phone()
{
    return phone;
}

void client::set_accountID(int accountID)
{
    this->basicAccount.set_accountID(accountID);
}

int client::get_accountID()
{
    return basicAccount.get_accountID();
}

void client::display()
{
    cout << "Name: " << get_name() << endl;
    cout << "Address: " << get_address() << endl;
    cout << "Phone: " << get_phone() << endl;
}

void Bank_Application::displayMenu()
{
    cout << "1. Create a new account" << endl;
    cout << "2. list Clients and accounts" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    while (choice != 5)
    {
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
        displayMenu();
    }
}

void Bank_Application::createAccount()
{
    client newClient;
    cout << "Enter client name: ";
    string client_name;
    cin >> client_name;
    newClient.set_name(client_name);

    cout << "Enter client address: ";
    string client_address;
    cin >> client_address;
    newClient.set_address(client_address);

    cout << "Enter client phone: ";
    string client_phone;
    cin >> client_phone;
    newClient.set_phone(client_phone);
    clients.push_back(newClient);

    cout << "What type of account do you want to create?" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Basic Account" << endl;
    int accountType;
    cin >> accountType;
    if (accountType == 1)
    {
        is_saving = true;
        cout << "Enter starting balance: ";
        float balance;
        cin >> balance;
        newClient.set_savings_balance(balance);
        cout << "An account has been created with the following details: " << endl;
        newClient.display_savings();
    }
    else if (accountType == 2)
    {
        // bankAccount newAccount;
        is_saving = false;
        cout << "Enter starting balance: ";
        float balance;
        cin >> balance;
        newClient.set_basic_balance(balance);
        cout << "An account has been created with the following details: " << endl;
        newClient.display_basic();
        // accounts.push_back(newAccount);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}
void Bank_Application::listClients()
{
    for (int i = 0; i < clients.size(); i++)
    {
        cout << "Client " << i + 1 << endl;
        clients[i].display();
        cout << "Accounts: " << endl;
        if(is_saving = true){
            clients[i].display_savings();
        }
        else{
            clients[i].display_basic();
        }
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
    for (int i = 0; i < clients.size(); i++){
        if (clients[i].get_accountID() == accountID){
            if(is_saving = true){
                clients[i].savings_deposit(amount);
            }
            else{
                clients[i].basic_deposit(amount);
            }
        }
    }
}

void Bank_Application::withdraw(){
    cout << "Enter account ID: ";
    int accountID;
    cin >> accountID;
    cout << "Enter amount: ";
    float amount;
    cin >> amount;
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i].get_accountID() == accountID)
        {
            if(is_saving = true){
                clients[i].savings_withdraw(amount);
            }
            else{
            clients[i].basic_withdraw(amount);
            }
        }
    }
}
