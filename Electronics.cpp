#include <iostream>
#include <string>
#include "Electronics.hpp"

using namespace std;

Electronics::Electronics() : Product()
{
    category = "Electronics";
}

Electronics::Electronics(const string name, const string description, const double& price, const unsigned int& quantity) : Product(name, description, price, quantity)
{
    this->category = "Electronics";
}

void Electronics::printProduct() const
{
    Product::printProduct();
    cout<<"Category: "<<this->category<<endl<<endl;
}

string Electronics::getCategory() const
{
    return this->category;
}
