#include <iostream>
#include <string>
#include "Books.hpp"

using namespace std;

Books::Books() : Product()
{
    category = "Books";
}

Books::Books(const string name, const string description, const double& price, const unsigned int& quantity) : Product(name, description, price, quantity)
{
    this->category = "Books";
}

void Books::printProduct() const
{
    Product::printProduct();
    cout<<"Category: "<<this->category<<endl<<endl;
}

string Books::getCategory() const
{
    return this->category;
}
