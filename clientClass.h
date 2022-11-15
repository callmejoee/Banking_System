#ifndef CLIENTCLASS_H_INCLUDED
#define CLIENTCLASS_H_INCLUDED

#include "basicAccount.h"
#include "savingsAccountClass.h"
#include <iostream>
using namespace std;

class client
{
private:
    bool is_saving;
    string name;
    string address;
    string phone;
    savingsAccount savingAccount;
    bankAccount basicAccount;

    bankAccount* pBasicAccount{&basicAccount};
    bankAccount* pSavingAccount{&savingAccount};


public:

    client();
    client(string&, string&, string&);

    void set_name(string&);
    void set_address(string&);
    void set_phone(string&);
    void set_balance(float);
    void set_accountID();

    string get_name() const;
    string get_address() const;
    string get_phone() const;
    int get_accountID() const;
    bool get_saving_flag() const;

    void deposit(float amount);
    void withdraw(float amount);

    void displayAccount() const;
    void display() const;

    void is_savings_flag();
};


#endif // CLIENTCLASS_H_INCLUDED
