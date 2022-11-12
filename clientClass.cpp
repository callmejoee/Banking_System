#include "clientClass.h"


client::client()
{
    name = "";
    address = "";
    phone = "";
    is_saving = false;
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

void client::set_basic_balance(float balance)
{
    basicAccount.set_balance(balance);
}

void client::set_savings_balance(float balance)
{
    savingsAccount.set_balance(balance);
}

void client::set_accountID()
{
    static long int newID = 2021000;
    if(get_saving_flag()){
        savingsAccount.set_accountID(newID++);
    }
    else{
        basicAccount.set_accountID(newID++);
    }
}

string client::get_name()
{
    return name;
}

string client::get_address()
{
    return address;
}

string client::get_phone()
{
    return phone;
}

int client::get_accountID()
{
    if(get_saving_flag() == true){
        return savingsAccount.get_accountID();
    }
    else{
        return basicAccount.get_accountID();
    }
}

bool client::get_saving_flag()
{
    return is_saving;
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

void client::display_basic()
{
    basicAccount.display();
}

void client::display_savings()
{
    savingsAccount.display();
}

void client::display()
{
    cout << "Name: " << get_name() << endl;
    cout << "Address: " << get_address() << endl;
    cout << "Phone: " << get_phone() << endl;
}

void client::is_savings_flag()
{
    is_saving = true;
}
