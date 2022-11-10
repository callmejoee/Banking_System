//
// Created by Youssef on 11/10/2022.
//

#include "BankingSystem.h"
#include <iostream>

using namespace std;


bankAccount::bankAccount() {
    accountID = 0;
    balance = 0;
}

bankAccount::bankAccount(int accountID, float balance) {
    this->accountID = accountID;
    this->balance = balance;
}

void bankAccount::deposit(float amount) {
    balance += amount;
}

void bankAccount::withdraw(float amount) {
    balance -= amount;
}

void bankAccount::display() {
    cout << "Account ID: " << accountID << endl;
    cout << "Balance: " << balance << endl;
}

void bankAccount::set_accountID(int accountID) {
    this->accountID = accountID;
}

void bankAccount::set_balance(float balance) {
    this->balance = balance;
}
int bankAccount::get_accountID() {
    return accountID;
}
float bankAccount::get_balance() {
    return balance;
}

savingsAccount::savingsAccount() : bankAccount() {
    set_accountID(0);
    set_balance(0);
    minimumBalance = 1000;
}
void savingsAccount:: set_minimumBalance(float minimumBalance) {
    if (minimumBalance < 1000) {
        cout << "Minimum balance must be greater than 1000" << endl;
    } else {
        set_minimumBalance(minimumBalance);
    }
}

float savingsAccount::get_minimumBalance() {
    return minimumBalance;
}

void savingsAccount::withdraw(float amount) {
    if (get_balance() - amount < minimumBalance) {
        cout << "Cannot withdraw more than minimum balance" << endl;
    } else {
        set_balance(get_balance() - amount);
    }
}

void savingsAccount::deposit(float amount) {
    if (amount >= 100){
        set_balance(get_balance() + amount);
    }
    else {
        cout << "Cannot deposit less than 100" << endl;
    }
}

void savingsAccount::display() {
    cout << "Account ID: " << get_accountID() << endl;
    cout << "Balance: " << get_balance() << endl;
}

savingsAccount::savingsAccount(int accountID, float balance, float minimumBalance) : bankAccount(accountID, balance) {
    set_minimumBalance(minimumBalance);
}

client::client() {
    name = "";
    address = "";
    phone = "";
}

client::client(string name, string address, string phone) {
    this->name = name;
    this->address = address;
    this->phone = phone;
}

void client::set_name(string name) {
    this->name = name;
}

void client::set_address(string address) {
    this->address = address;
}

void client::set_phone(string phone) {
    this->phone = phone;
}

string client::get_name() {
    return name;
}

string client::get_address() {
    return address;
}

string client::get_phone() {
    return phone;
}

void client::display() {
    cout << "Name: " << get_name() << endl;
    cout << "Address: " << get_address() << endl;
    cout << "Phone: " << get_phone() << endl;
}

void Bank_Application::displayMenu() {
    cout << "1. Create a new account" << endl;
    cout << "2. list Clients and accounts" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
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
            if (accountType == 1){
                savingsAccount newAccount;
                cout << "Enter starting balance: ";
                float balance;
                cin >> balance;
                newAccount.set_minimumBalance(balance);
                cout << "An account has been created with the following details: " << endl;
                newAccount.display();
                savings_accounts.push_back(newAccount);

            }
            else if (accountType == 2){
                bankAccount newAccount;
                cout << "Enter starting balance: ";
                float balance;
                cin >> balance;
                newAccount.set_balance(balance);
                cout << "An account has been created with the following details: " << endl;
                newAccount.display();
                accounts.push_back(newAccount);
            }
            else {
                cout << "Invalid choice" << endl;
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < clients.size(); i++){
                cout << "Client " << i + 1 << endl;
                clients[i].display();
                cout << "Accounts: " << endl;
                for (int j = 0; j < accounts.size(); j++){
                    accounts[j].display();
                }
                for (int j = 0; j < savings_accounts.size(); j++){
                    savings_accounts[j].display();
                }
            }
            break;
        }
        case 3:
        {
            cout << "Enter account ID: ";
            int accountID;
            cin >> accountID;
            cout << "Enter amount: ";
            float amount;
            cin >> amount;
            for (int i = 0; i < accounts.size(); i++){
                if (accounts[i].get_accountID() == accountID){
                    accounts[i].deposit(amount);
                }
            }
            for (int i = 0; i < savings_accounts.size(); i++){
                if (savings_accounts[i].get_accountID() == accountID){
                    savings_accounts[i].deposit(amount);
                }
            }
            break;
        }
        case 4:
        {
            cout << "Enter account ID: ";
            int accountID;
            cin >> accountID;
            cout << "Enter amount: ";
            float amount;
            cin >> amount;
            for (int i = 0; i < accounts.size(); i++){
                if (accounts[i].get_accountID() == accountID){
                    accounts[i].withdraw(amount);
                }
            }
            for (int i = 0; i < savings_accounts.size(); i++){
                if (savings_accounts[i].get_accountID() == accountID){
                    savings_accounts[i].withdraw(amount);
                }
            }
            break;
        }
        default:
            cout << "Invalid choice" << endl;
            break;

    }
}
