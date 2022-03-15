#ifndef BOOKS_HPP_INCLUDED
#define BOOKS_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Product.hpp"
using namespace std;

class Books: public Product
{
private:
    string category;

public:
    Books();
    Books(const string, const string, const double&, const unsigned int&);

    void printProduct() const;
    string getCategory() const;
};

#endif // BOOKS_HPP_INCLUDED
