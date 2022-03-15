#ifndef GAMES_HPP_INCLUDED
#define GAMES_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Product.hpp"
using namespace std;

class Games: public Product {
private:
    string category;

public:
    Games();
    Games(const string, const string, const double&, const unsigned int&);

    void printProduct() const;
    string getCategory() const;
};

#endif // GAMES_HPP_INCLUDED
