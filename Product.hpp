#ifndef PRODUCT_HPP_INCLUDED
#define PRODUCT_HPP_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    string description;
    double price;
    unsigned int quantity;
    bool stock;

public:
    Product(); //default constructor
    Product(const string, const string, const double&, const unsigned int&); //constructor with parameters

    //get and set methods
    void setName(string name);
    void setDescription(string description);
    void setPrice(double price);
    void setQuantity(unsigned int quantity);

    string getName() const;
    string getDescription() const;
    double getPrice() const;
    unsigned int getQuantity() const;

    bool isAvailable(); //checking if the product is available
    virtual void printProduct() const;
    virtual string getCategory() const {;}

};

#endif // PRODUCT_HPP_INCLUDED
