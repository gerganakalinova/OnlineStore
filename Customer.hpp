#ifndef CUSTOMER_HPP_INCLUDED
#define CUSTOMER_HPP_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string custName;
    string address;
    string email;
    string nickname;
    string password;

public:
    Customer();
    Customer(const string custName, const string address, const string email, const string nickname, const string password);

    //get and set methods
    void setName(string custName);
    void setAddress(string address);
    void setEmail(string email);
    void setNickname(string nickname);
    void setPassword(string password);

    string getName() const;
    string getAddress() const;
    string getEmail() const;
    string getNickname() const;
    string getPassword() const;

    void custRegistration();
    void printCustomer() const;
    void wayOfPayment();


    friend ostream &operator<<(ostream& output, const Customer& to_print ) {
         output << "-> Name: " << to_print.getName()<<endl;
         output << "-> Address: " << to_print.getAddress()<<endl;
         output << "-> Email: " << to_print.getEmail()<<endl;
         output << "-> Nickname: " << to_print.getNickname()<<endl;
         output << "-> Password: " << to_print.getPassword()<<endl;
         return output;
      }

};

#endif // CUSTOMER_HPP_INCLUDED
