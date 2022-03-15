#include <iostream>
#include <string>
#include <vector>
#include "SearchProduct.hpp"

using namespace std;

SearchProduct::SearchProduct()
{
    searchBar = "";
    searchBarPrice = 0.0;
}

string SearchProduct::searchByName()
{
    cout<<"Enter the name of the product you are searching for: ";
    cin>>this->searchBar;
    cout<<endl;

    return this->searchBar;
}

string SearchProduct::searchByCategory()
{
    cout<<"Enter the category of the product you are searching for: ";
    cin>>this->searchBar;
    cout<<endl;

    return this->searchBar;
}

double SearchProduct::searchByPrice()
{
    cout<<"Enter the price of the product you are searching for: ";
    cin>>this->searchBarPrice;
    cout<<endl;

    return this->searchBarPrice;
}
