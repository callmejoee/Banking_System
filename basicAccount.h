#ifndef BASICACCOUNT_H_INCLUDED
#define BASICACCOUNT_H_INCLUDED
//#include"clientClass.h"
#include <iostream>

using namespace std;


class bankAccount
{
private:
    int accountID;
    float balance;

public:
    bankAccount();
    void set_accountID(int);
    virtual void set_balance(float = 0.0);

    int get_accountID() const;
    float get_balance() const;

    virtual void deposit(float);
    virtual void withdraw(float);

    virtual void display() const;
};


#endif // BASICACCOUNT_H_INCLUDED
