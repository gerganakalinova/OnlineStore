#include <iostream>
#include <string>
#include "Product.hpp"

using namespace std;

Product::Product()
    : price(0.0)
    , quantity(0)
{
    name = "";
    description = "";
}


Product::Product(const string name, const string description, const double& price, const unsigned int& quantity)
{
    this->name = name;
    this->description = description;
    this->price = price;
    this->quantity = quantity;
}


void Product::setName(string name)
{
    this->name = name;
}

void Product::setDescription(string description)
{
    this->description = description;
}

void Product::setPrice(double price)
{
    this->price = price;
}

void Product::setQuantity(unsigned int quantity)
{
    this->quantity = quantity;
}


string Product::getName() const
{
    return this->name;
}

string Product::getDescription() const
{
    return this->description;
}

double Product::getPrice() const
{
    return this->price;
}

unsigned int Product::getQuantity() const
{
    return this->quantity;
}


bool Product::isAvailable()
{
    if(this->quantity > 0)
    {
        return stock = true;
    }
    else
    {
        return stock = false;
    }
}

void Product::printProduct() const
{
    cout<<"Product name: "<<this->name<<endl;
    cout<<"Description: "<<this->description<<endl;
    cout<<"Price: "<<this->price<<endl;
    cout<<"Quantity: "<<this->quantity<<endl;
}
