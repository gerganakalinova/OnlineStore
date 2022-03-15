#include <iostream>
#include <string>
#include "Customer.hpp"

using namespace std;

Customer::Customer()
{
    custName = "";
    address = "";
    email = "";
    nickname = "";
    password = "";
}

Customer::Customer(const string custName, const string address, const string email, const string nickname, const string password)
{
    this->custName = custName;
    this->address = address;
    this->email = email;
    this->nickname = nickname;
    this->password = password;
}

void Customer::setName(string custName)
{
    this->custName = custName;
}

void Customer::setAddress(string address)
{
    this->address = address;
}

void Customer::setEmail(string email)
{
    this->email = email;
}

void Customer::setNickname(string nickname)
{
    this->nickname = nickname;
}

void Customer::setPassword(string password)
{
    this->password = password;
}


string Customer::getName() const
{
    return this->custName;
}

string Customer::getAddress() const
{
    return this->address;
}

string Customer::getEmail() const
{
    return this->email;
}

string Customer::getNickname() const
{
    return this->nickname;
}

string Customer::getPassword() const
{
    return this->password;
}


void Customer::custRegistration()
{
    cout<<"Create your registration:"<<endl;

    cout<<"-> Insert your name: ";
    getline(cin, this->custName);
    while(this->custName == "")
    {
        cout<<"Incorrect name. Try again: ";
        getline(cin, this->custName);
    }

    cout<<"-> Insert your address: ";
    getline(cin, this->address);
    while(this->address == "")
    {
        cout<<"Incorrect address. Try again: ";
        getline(cin, this->address);
    }

    cout<<"-> Insert your email: ";
    getline(cin, this->email);
    while(this->email == "")
    {
        cout<<"Incorrect email. Try again: ";
        getline(cin, this->email);
    }

    cout<<"-> Insert your username: ";
    getline(cin, this->nickname);
    while(this->nickname == "")
    {
        cout<<"Incorrect username. Try again: ";
        getline(cin, this->nickname);
    }

    cout<<"-> Insert your password: ";
    getline(cin, this->password);
    while(this->password == "")
    {
        cout<<"Incorrect password. Try again: ";
        getline(cin, this->password);
    }

    cout<<endl;
}


void Customer::printCustomer() const
{
    cout<<"Name: "<<this->custName<<endl;
    cout<<"Address: "<<this->address<<endl;
    cout<<"Email: "<<this->email<<endl;
    cout<<endl;
}

void Customer::wayOfPayment()
{
    int choice = 0;

    cout<<"Choose your way of payment: "<<endl;
    cout<<"1.Credit/debit card"<<endl;
    cout<<"2.Paypal"<<endl;
    cout<<"3.Cash on delivery"<<endl;
    cout<<"Please choose 1, 2 or 3: ";

    cin>>choice;

    while(choice!=1 && choice!=2 && choice!=3)
    {
        cout<<"Wrong input. Try again: ";
        cin>>choice;
    }
    cout<<endl;
    string info;

    if(choice == 1)
    {
        cout<<"Insert your credit/debit card information: ";
        cin>>info;
        cout<<endl;
    }
    else if(choice == 2)
    {
        cout<<"Insert your paypal information: ";
        cin>>info;
        cout<<endl;
    }
    else if(choice == 3)
    {

    }
}
