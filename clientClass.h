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
    savingsAccount savingsAccount;
    bankAccount basicAccount;

public:
    client();
    client(string name, string address, string phone);

    void set_name(string name);
    void set_address(string address);
    void set_phone(string phone);
    void set_basic_balance(float balance);
    void set_savings_balance(float balance);
    void set_accountID();

    string get_name();
    string get_address();
    string get_phone();
    int get_accountID();
    bool get_saving_flag();

    void basic_deposit(float amount);
    void savings_deposit(float amount);
    void basic_withdraw(float amount);
    void savings_withdraw(float amount);

    void display_basic();
    void display_savings();
    void display();

    void is_savings_flag();
};


#endif // CLIENTCLASS_H_INCLUDED
