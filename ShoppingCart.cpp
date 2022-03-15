#include <iostream>
#include <string>
#include <vector>
#include "ShoppingCart.hpp"
#include "Product.hpp"
#include "Books.hpp"
#include "Games.hpp"
#include "Electronics.hpp"
#include "Store.hpp"

using namespace std;

ShoppingCart::ShoppingCart()
{
    itemsInCart = vector<Product*>();
    copiesOfProduct = vector<int>();
}


void ShoppingCart::productsInCart() const
{
    for(int i=0; i<itemsInCart.size(); i++)
    {
        cout<<'\t'<<i+1<<endl;

        if(itemsInCart[i]->getQuantity() == 0)
        {
            cout<<"This product is not in stock any more"<<endl;
        }
        if(itemsInCart[i]->getQuantity() < copiesOfProduct[i])
        {
            cout<<"There are not enough copies of the product in stock"<<endl;
        }

        cout<<"Product name: "<<itemsInCart[i]->getName()<<endl;
        cout<<"Copies: "<<copiesOfProduct[i]<<endl;
        cout<<"Total price for this product: "<<(itemsInCart[i]->getPrice())*(copiesOfProduct[i]);
        cout<<endl<<endl;
    }

    if(itemsInCart.size() == 0)
    {
        cout<<"The cart is empty"<<endl<<endl;
    }

}

void ShoppingCart::totalPrice() const
{
    double price = 0.0;
    double priceNotInStock = 0.0;
    for(int i=0; i<itemsInCart.size(); i++)
    {
        double pricePerOne = itemsInCart[i]->getPrice();
        int copies = copiesOfProduct[i];

        if(itemsInCart[i]->getQuantity() == 0 || itemsInCart[i]->getQuantity() < copies)
        {
            priceNotInStock += pricePerOne*copies;
        }
        else
        {
            price += pricePerOne*copies;
        }
    }

    cout<<"Total price for products in stock: "<<price<<endl;
    cout<<"Total price for products not in stock: "<<priceNotInStock<<endl;
}

void ShoppingCart::addToCart(Product& product)
{
    int check = 0;
    for(int i=0; i<itemsInCart.size(); i++)
    {
        if((itemsInCart[i]->getName() == product.getName()) && (itemsInCart[i]->getDescription() == product.getDescription()) && (itemsInCart[i]->getPrice() == product.getPrice())
                && (itemsInCart[i]->getQuantity() == product.getQuantity()) && (itemsInCart[i]->getCategory() == product.getCategory()))
        {

            check++;

            if(product.getQuantity() == 0)
            {
                cout<<"The product '"<<product.getName()<<"' is not in stock any more."<<endl<<endl;
                itemsInCart.erase(itemsInCart.begin() + i);
                copiesOfProduct.erase(copiesOfProduct.begin() + i);
            }
            else
            {
                int copies = 0;
                cout<<"How much copies from the product '"<<product.getName()<<"' do you want: ";
                cin>>copies;
                int newCopies = copies + copiesOfProduct[i];

                while(newCopies > product.getQuantity())
                {
                    cout<<"Not enough copies in stock. Choose again: ";
                    cin>>copies;
                    newCopies = copies + copiesOfProduct[i];
                }
                while(newCopies == 0)
                {
                    cout<<"Invalid input. You can not add 0 copies to your cart.Choose again: ";
                    cin>>copies;
                    newCopies = copies + copiesOfProduct[i];

                    while(newCopies > product.getQuantity())
                    {
                        cout<<"Not enough copies in stock. Choose again: ";
                        cin>>copies;
                        newCopies = copies + copiesOfProduct[i];
                    }
                }
                copiesOfProduct[i] = newCopies;
            }
        }
        else
        {
            continue;
        }
    }

    if(check != 0)
    {
        cout<<endl;
    }
    else
    {
        if(product.getQuantity() == 0)
        {
            cout<<"The product '"<<product.getName()<<"' is not in stock."<<endl<<endl;
        }
        else
        {
            int copies = 0;
            cout<<"How much copies from the product '"<<product.getName()<<"' do you want: ";
            cin>>copies;

            while(copies > product.getQuantity())
            {
                cout<<"Not enough copies in stock. Choose again: ";
                cin>>copies;
            }
            while(copies == 0)
            {
                cout<<"Invalid input. You can not add 0 copies to your cart.Choose again: ";
                cin>>copies;

                while(copies > product.getQuantity())
                {
                    cout<<"Not enough copies in stock. Choose again: ";
                    cin>>copies;
                }
            }
            itemsInCart.push_back(&product);
            copiesOfProduct.push_back(copies);
            cout<<endl;
        }

    }

}


void ShoppingCart::removeFromCart(Product& product)
{
    for(int i=0; i<itemsInCart.size(); i++)
    {
        if((itemsInCart[i]->getName() == product.getName()) && (itemsInCart[i]->getDescription() == product.getDescription()) && (itemsInCart[i]->getPrice() == product.getPrice())
                && (itemsInCart[i]->getQuantity() == product.getQuantity()) && (itemsInCart[i]->getCategory() == product.getCategory()))
        {

            itemsInCart.erase(itemsInCart.begin() + i);
            copiesOfProduct.erase(copiesOfProduct.begin() + i);

        }
    }
}

void ShoppingCart::buyFromCart()
{
//    cout<<"Here is your order: "<<endl;

    for(int i=0; i<itemsInCart.size(); i++)
    {
        if((itemsInCart[i]->getQuantity() != 0) && (itemsInCart[i]->getQuantity() >= copiesOfProduct[i]))
        {
            int previousQuantity = itemsInCart[i]->getQuantity();
            itemsInCart[i]->setQuantity(previousQuantity - copiesOfProduct[i]);
            itemsInCart.erase(itemsInCart.begin() + i);
            copiesOfProduct.erase(copiesOfProduct.begin() + i);
        }
        int previousQuantity = itemsInCart[i]->getQuantity();
        itemsInCart[i]->setQuantity(previousQuantity - copiesOfProduct[i]);
    }

}

int ShoppingCart::sizeOfProductsInCart() const
{
    return itemsInCart.size();
}

int ShoppingCart::copiesOfWantedProduct(int index) const
{
    return copiesOfProduct[index-1];
}

Product* ShoppingCart::getProductFromCart(int index) const
{
    return itemsInCart[index-1];
}
