#ifndef SEARCHPRODUCT_HPP_INCLUDED
#define SEARCHPRODUCT_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SearchProduct {
private:
    string searchBar;
    double searchBarPrice;

public:
    SearchProduct();

    string searchByName();
    string searchByCategory();
    double searchByPrice();
};

#endif // SEARCHPRODUCT_HPP_INCLUDED
