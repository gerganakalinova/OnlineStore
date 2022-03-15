#include <iostream>
#include <string>
#include "Games.hpp"

using namespace std;

Games::Games() : Product()
{
    category = "Games";
}

Games::Games(const string name, const string description, const double& price, const unsigned int& quantity) : Product(name, description, price, quantity)
{
    this->category = "Games";
}

void Games::printProduct() const
{
    Product::printProduct();
    cout<<"Category: "<<this->category<<endl<<endl;
}

string Games::getCategory() const
{
    return this->category;
}
