#include "clientClass.h"


client::client()
{
    name = "";
    address = "";
    phone = "";
    is_saving = false;
}

client::client(string& newName, string& newAddress, string& newPhone)
    : name(newName), address(newAddress), phone(newPhone){}

void client::set_name(string& newName)
{
    name = newName;
}

void client::set_address(string& newAddress)
{
    address = newAddress;
}

void client::set_phone(string& newPhone)
{
    phone = newPhone;
}

void client::set_balance(float amount){
    if(get_saving_flag() == true){
        pSavingAccount->set_balance(amount);
    }
    else{
        pBasicAccount->set_balance(amount);
    }
}


void client::set_accountID()
{
    static long int newID = 2021000;
    if(get_saving_flag()){
        pSavingAccount->set_accountID(newID++);
    }
    else{
        pBasicAccount->set_accountID(newID++);
    }
}

string client::get_name() const
{
    return name;
}

string client::get_address() const
{
    return address;
}

string client::get_phone() const
{
    return phone;
}

int client::get_accountID() const
{
    if(get_saving_flag()){
        return savingAccount.get_accountID();
    }
    else{
        return basicAccount.get_accountID();
    }
}

bool client::get_saving_flag() const
{
    return is_saving;
}

void client::deposit(float amount){
    if(get_saving_flag()){
        savingAccount.deposit(amount);
    }
    else{
        basicAccount.deposit(amount);
    }
}


void client::withdraw(float amount){
    if(get_saving_flag()){
        savingAccount.withdraw(amount);
    }
    else{
        basicAccount.withdraw(amount);
    }
}

void client::displayAccount() const{
    if(get_saving_flag()){
        savingAccount.display();
    }
    else{
        basicAccount.display();
    }
}

void client::display() const
{
    cout << "Name: " << get_name() << endl;
    cout << "Address: " << get_address() << endl;
    cout << "Phone: " << get_phone() << endl;
}

void client::is_savings_flag()
{
    is_saving = true;
}
