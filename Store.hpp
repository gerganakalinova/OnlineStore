#ifndef STORE_HPP_INCLUDED
#define STORE_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Product.hpp"
#include "Customer.hpp"
#include "Books.hpp"
#include "Games.hpp"
#include "Electronics.hpp"
#include "SearchProduct.hpp"
using namespace std;


class Store {
private:
    vector<Customer> custArr;
    vector<Product*> products;

public:
    Store();

    void addProduct(Product& product);
    void removeProduct(Product& product);
    void listProduct() const; //showing the products
    void buyProductFromStore(Product& product); //buying the product directly
    void buyProductFromStore(int index); //buying the product directly by index
    int productsSize() const; //returns the length of the products vector
    Product* getProduct(int index) const; //returns pointer to a specific product by index

    void createCustomer(const Customer& customer); //add customer to the customers vector
    void listCustomer() const;
    void custLogin(Customer& customer) const;
    int customersSize() const;
    Customer getCustomer(int index) const;

    void helpSearch(SearchProduct& searching); //helps with the searching of the products


};

#endif // STORE_HPP_INCLUDED
