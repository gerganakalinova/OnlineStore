#ifndef SHOPPINGCART_HPP_INCLUDED
#define SHOPPINGCART_HPP_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Product.hpp"
#include "Books.hpp"
#include "Games.hpp"
#include "Electronics.hpp"
#include "Store.hpp"
using namespace std;

class ShoppingCart {
private:
    vector<Product*> itemsInCart;
    vector<int> copiesOfProduct;

public:
    ShoppingCart();

    // we will need something to connect one cart with it's owner; different account - different cart
    void productsInCart() const; //print the products in the cart
    void totalPrice() const; // total price of the products in the cart - those in stock and not in stock
    void addToCart(Product& product);
    void removeFromCart(Product& product);
    void buyFromCart();
    int sizeOfProductsInCart() const; //returns the size of the products in cart vector
    int copiesOfWantedProduct(int index) const; //returns the copies of specific products which are added to the card
    Product* getProductFromCart(int index) const; //returns pointer to a specific product by index
};

#endif // SHOPPINGCART_HPP_INCLUDED
