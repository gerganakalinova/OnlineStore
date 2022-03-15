#ifndef ELECTRONICS_HPP_INCLUDED
#define ELECTRONICS_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Product.hpp"
using namespace std;

class Electronics: public Product {
private:
    string category;

public:
    Electronics();
    Electronics(const string, const string, const double&, const unsigned int&);

    void printProduct() const;
    string getCategory() const;
};

#endif // ELECTRONICS_HPP_INCLUDED
