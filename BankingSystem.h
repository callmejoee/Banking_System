//
// Created by Youssef on 11/10/2022.
//

#ifndef BANKING_SYSTEM_BANKINGSYSTEM_H
#define BANKING_SYSTEM_BANKINGSYSTEM_H
#include <iostream>
#include <vector>

using namespace std;

class bankAccount {
private:
    int accountID;
    float balance;
public:
    bankAccount();
    bankAccount(int accountID, float balance);
    void set_accountID(int accountID);
    void set_balance(float balance);
    int get_accountID();
    float get_balance();
    void deposit(float amount);
    void withdraw(float amount);
    void display();
};

class savingsAccount : public bankAccount {
private:
    float minimumBalance = 1000;
public:
    savingsAccount();
    savingsAccount(int accountID, float balance, float minimumBalance);
    void set_minimumBalance(float minimumBalance);
    float get_minimumBalance();
    void withdraw(float amount);
    void deposit(float amount);
    void display();
};

class client{
private:
    string name;
    string address;
    string phone;

public:
    client();
    client(string name, string address, string phone);
    void set_name(string name);
    void set_address(string address);
    void set_phone(string phone);
    string get_name();
    string get_address();
    string get_phone();
    void display();
};

class Bank_Application {
private:
    int choice;
    vector<client> clients;
    vector<savingsAccount> savings_accounts;
    vector<bankAccount> accounts;
    public:
    Bank_Application(){
    }
    void displayMenu();


};

#endif //BANKING_SYSTEM_BANKINGSYSTEM_H
