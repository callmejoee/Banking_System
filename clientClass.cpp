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

void client::set_balance(float amount){
    if(get_saving_flag() == true){
        savingsAccount.set_balance(amount);
    }
    else{
        basicAccount.set_balance(amount);
    }
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

void client::deposit(float amount){
    if(get_saving_flag()){
        savingsAccount.deposit(amount);
    }
    else{
        basicAccount.deposit(amount);
    }
}


void client::withdraw(float amount){
    if(get_saving_flag()){
        savingsAccount.withdraw(amount);
    }
    else{
        basicAccount.withdraw(amount);
    }
}

void client::displayAccount(){
    if(get_saving_flag()){
        savingsAccount.display();
    }
    else{
        basicAccount.display();
    }
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
