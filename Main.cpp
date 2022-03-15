#include <iostream>
#include "Customer.hpp"
#include "Product.hpp"
#include "Books.hpp"
#include "Games.hpp"
#include "Electronics.hpp"
#include "SearchProduct.hpp"
#include "ShoppingCart.hpp"
#include "Store.hpp"
#include <string>
#include <vector>

using namespace std;
int main()
{

    Customer customer;
    Store store;
    ShoppingCart cart;
    SearchProduct searchP;

    cout<<"Do you have a registration?"<<endl;
    cout<<"-> Enter yes or no: ";
    string answer = "";
    getline(cin, answer);
    cout<<endl;

    while(answer != "no" && answer != "yes")
    {
        cout<<"Incorrect input. Try again:"<<endl;
        cout<<"-> Enter yes or no: ";
        getline(cin, answer);
        cout<<endl;
    }

    if(answer == "no")
    {
        customer.custRegistration();
        int custSize = store.customersSize();
        //making sure that every username is unique
        for(int i=0; i<custSize; i++)
        {
            Customer newCust = store.getCustomer(i);
            if(newCust.getNickname() == customer.getNickname())
            {
                cout<<"The username is taken. Please registrate again"<<endl;
                delete &customer;
                customer.custRegistration();
            }
        }

        store.createCustomer(customer);
        store.custLogin(customer);
    }
    else if(answer == "yes")
    {
        store.custLogin(customer);
    }
    else
    {
        cout<<"Incorrect input. Try again:"<<endl;
    }

    Books book1("Divergent", "Author: Veronica Roth", 9.99, 5);
    Books book2("Allegiant", "Author: Veronica Roth", 12.99, 3);
    Games game1("Monopoly", "Playing time: 20-180 minutes", 24.99, 0);
    Games game2("Chess", "Playing time: 10-60 minutes", 45.99, 2);
    Electronics device1("Phone", "Color: white", 209.99, 4);
    Electronics device2("Camera", "Brand: Nikon", 539.99, 1);

    store.addProduct(book1);
    store.addProduct(book2);
    store.addProduct(game1);
    store.addProduct(game2);
    store.addProduct(device1);
    store.addProduct(device2);


LOOP4:
LOOP5:
    cout<<'\t'<<"Main menu"<<endl;
    cout<<"Do you want to:"<<endl;
    cout<<"1.View the products in the store"<<endl;
    cout<<"2.Buy a product directly"<<endl;
    cout<<"3.Add a product to your cart"<<endl;
    cout<<"4.Search for a product"<<endl;
    cout<<"5.Go to your cart"<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"Please choose 1, 2, 3, 4, 5 or 6: ";

    int answerToMainMenu;
    cin>>answerToMainMenu;
    cout<<endl;


    while(answerToMainMenu!=1 && answerToMainMenu!=2 && answerToMainMenu!=3 && answerToMainMenu!=4 && answerToMainMenu!=5 && answerToMainMenu!=6)
    {
        cout<<"Wrong input. Try again: ";
        cin>>answerToMainMenu;
    }

    if(answerToMainMenu == 1)
    {
        store.listProduct();
    }
    else if(answerToMainMenu == 2)
    {
        int answerForProduct;
        cout<<"Which product do you want to buy.";
        cout<<"Please choose 1";
        for(int i=2; i<=store.productsSize(); i++)
        {
            cout<<", "<<i;
        }
        cout<<" : ";

LOOP1:
        cin>>answerForProduct;

        Product* product = store.getProduct(answerForProduct);
        int stock = 0;

        int check = 0;
        for(int j=1; j<=store.productsSize(); j++)
        {
            if(answerForProduct == j)
            {
                store.buyProductFromStore(j);
                check++;
            }
        }

        if(check == 0)
        {
            cout<<"Wrong input.Try again: ";
            delete &product;
            goto LOOP1;
        }
        else {
            stock = product->getQuantity();
        }

        if(stock > 0)
        {
            customer.wayOfPayment();
            cout<<"Your order is completed"<<endl;
            cout<<"Delivery address: "<<customer.getAddress()<<endl<<endl;

        }

    }
    else if(answerToMainMenu == 3)
    {
        int answerForProduct;
        cout<<"Which product do you want to add to your cart.";
        cout<<"Please choose 1";
        for(int i=2; i<=store.productsSize(); i++)
        {
            cout<<", "<<i;
        }
        cout<<" : ";

LOOP2:
        cin>>answerForProduct;

        int check = 0;
        for(int j=1; j<=store.productsSize(); j++)
        {
            if(answerForProduct == j)
            {
                Product* product = store.getProduct(j);
                cart.addToCart(*product);
                check++;
            }
        }

        if(check == 0)
        {
            cout<<"Wrong input.Try again: ";
            goto LOOP2;
        }

    }
    else if(answerToMainMenu == 4)
    {
        cout<<endl;
        cout<<'\t'<<"Search bar"<<endl;
        store.helpSearch(searchP);


    }
    else if(answerToMainMenu == 5)
    {
        cout<<endl;
        cout<<'\t'<<"Your cart"<<endl;
        cout<<"Do you want to:"<<endl;
        cout<<"1.See the items in your cart"<<endl;
        cout<<"2.Finish your order"<<endl;
        cout<<"3.Remove a product from your cart"<<endl;
        cout<<"4.Return to main menu"<<endl;
        cout<<"Please choose 1, 2, 3 or 4: ";

        int answerForCart;
        cin>>answerForCart;

        while(answerForCart!=1 && answerForCart!=2 && answerForCart!=3 && answerForCart!=4)
        {
            cout<<"Wrong input. Try again: ";
            cin>>answerForCart;
        }

        cout<<endl;

        if(answerForCart == 1)
        {
            cout<<"Items in cart"<<endl;
            cart.productsInCart();
        }
        else if(answerForCart == 2)
        {
            cout<<"Your order"<<endl;
            cart.productsInCart();
            cart.totalPrice();

            if(cart.sizeOfProductsInCart() != 0)
            {
                customer.wayOfPayment();
                cout<<"Your order is completed"<<endl;
                cout<<"Delivery address: "<<customer.getAddress()<<endl<<endl;
            }

            cart.buyFromCart();

        }
        else if(answerForCart == 3)
        {
            int answerToRemove;
            if(cart.sizeOfProductsInCart() == 0)
            {
                cout<<"Your cart is empty. You can not remove any product."<<endl<<endl;
            }
            else
            {
                cout<<"Which product do you want to remove from your cart.";
                cout<<"Please choose 1";
                for(int i=2; i<=cart.sizeOfProductsInCart(); i++)
                {
                    cout<<", "<<i;
                }
                cout<<" : ";

LOOP3:
                cin>>answerToRemove;

                int check = 0;
                for(int j=1; j<=cart.sizeOfProductsInCart(); j++)
                {
                    if(answerToRemove == j)
                    {
                        Product* product = cart.getProductFromCart(j);
                        cart.removeFromCart(*product);
                        check++;
                    }
                }

                if(check == 0)
                {
                    cout<<"Wrong input.Try again: ";
                    goto LOOP3;
                }
            }
        }
        else if(answerForCart == 4)
        {
            goto LOOP4;
        }
    }
    else if(answerToMainMenu == 6)
    {
        cout<<"You have exited your profile"<<endl;
        return 1;

    }


    cout<<"================================================================================"<<endl<<endl;

    goto LOOP5;


    return 0;

}
