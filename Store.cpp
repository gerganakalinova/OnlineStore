#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Product.hpp"
#include "Customer.hpp"
#include "Store.hpp"
#include "Books.hpp"
#include "Games.hpp"
#include "Electronics.hpp"
#include "SearchProduct.hpp"

using namespace std;

Store::Store()
{
    products = vector<Product*>();
    custArr = vector<Customer>();
}


void Store::addProduct(Product& product)
{
    products.push_back(&product);
}

void Store::removeProduct(Product& product)
{
    for(int i=0; i<products.size(); i++)
    {
        if((products[i]->getName() == product.getName()) && (products[i]->getDescription() == product.getDescription()) && (products[i]->getPrice() == product.getPrice()) && (products[i]->getQuantity() == product.getQuantity()) && (products[i]->getCategory() == product.getCategory()))
        {
            products.erase(products.begin() + i);
        }
    }
}

void Store::listProduct() const
{
    cout<<"Items in store:"<<endl;
    for(int i=0; i<products.size(); i++)
    {
        cout<<'\t'<<(i+1)<<endl;

        if(products[i]->isAvailable())
        {
            products[i]->printProduct();
        }
        else
        {
            cout<<"The product is not available"<<endl<<endl;
        }
    }

}

void Store::buyProductFromStore(Product& product)
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
            cout<<"Invalid input. You can not buy 0 copies from the product.Choose again: ";
            cin>>copies;

            while(copies > product.getQuantity())
            {
                cout<<"Not enough copies in stock. Choose again: ";
                cin>>copies;
            }
        }
        int previousQuantity = product.getQuantity();
        product.setQuantity(previousQuantity - copies);
        cout<<endl;

        cout<<"Your order"<<endl;
        cout<<"Product name: "<<product.getName()<<endl;
        cout<<"Copies: "<<copies<<endl;
        cout<<"Total price: "<<(copies*product.getPrice())<<endl<<endl;
    }

}

void Store::buyProductFromStore(int index)
{
    if(products[index - 1]->getQuantity() == 0)
    {
        cout<<"The product '"<<products[index-1]->getName()<<"' is not in stock."<<endl<<endl;
    }
    else
    {
        int copies = 0;
        cout<<"How much copies from the product '"<<products[index-1]->getName()<<"' do you want: ";
        cin>>copies;

        while(copies > products[index-1]->getQuantity())
        {
            cout<<"Not enough copies in stock. Choose again: ";
            cin>>copies;
        }
        while(copies == 0)
        {
            cout<<"Invalid input. You can not buy 0 copies from the product.Choose again: ";
            cin>>copies;

            while(copies > products[index-1]->getQuantity())
            {
                cout<<"Not enough copies in stock. Choose again: ";
                cin>>copies;
            }
        }
        int previousQuantity = products[index-1]->getQuantity();
        products[index-1]->setQuantity(previousQuantity - copies);
        cout<<endl;

        cout<<"Your order"<<endl;
        cout<<"Product name: "<<products[index-1]->getName()<<endl;
        cout<<"Copies: "<<copies<<endl;
        cout<<"Total price: "<<(copies*products[index-1]->getPrice())<<endl<<endl;
    }
}

void Store::createCustomer(const Customer& customer)
{
    Customer newCustomer(customer.getName(), customer.getAddress(), customer.getEmail(), customer.getNickname(), customer.getPassword());
    custArr.push_back(newCustomer);

}

void Store::listCustomer() const
{
    cout<<"Customers list: "<<endl;
    for(int i=0; i<custArr.size(); i++)
    {
        cout<<custArr[i]<<endl;
    }
    cout<<endl;
}

void Store::custLogin(Customer& customer) const
{
    bool nameCheck = false;
    bool passwordCheck = false;

    string nameAttempt;
    string passwordAttempt;

    cout<<"Enter your username: ";
    getline(cin, nameAttempt);
    cout<<"Enter your password: ";
    getline(cin, passwordAttempt);


    if(nameAttempt == customer.getNickname())
    {
        nameCheck = true;
    }
    else
    {
        nameCheck = false;
    }


    if(passwordAttempt == customer.getPassword())
    {
        passwordCheck = true;
    }
    else
    {
        passwordCheck = false;
    }


    if(nameCheck == true && passwordCheck == true)
    {
        cout<<"Successful login"<<endl<<endl;
        cout<<"You entered your profile."<<endl<<endl;
    }
    else
    {
        cout<<"Incorrect username or password! Try again"<<endl;
        custLogin(customer);
    }

}

int Store::productsSize() const
{
    int productsArrSize = products.size();
    return productsArrSize;
}

Product* Store::getProduct(int index) const
{
    return products[index-1];
}

void Store::helpSearch(SearchProduct& searching)
{

    int choice = 0;

    cout<<"Choose your method of searching"<<endl;
    cout<<"1.Search by name"<<endl;
    cout<<"2.Search by category"<<endl;
    cout<<"3.Search by price"<<endl;
    cout<<"Please choose 1, 2 or 3: ";

    cin>>choice;

    while(choice != 1 && choice != 2 && choice != 3)
    {
        cout<<"Wrong input. Try again: ";
        cin>>choice;
    }

    if(choice == 1)
    {
        int check = 0;
        string searchBar = searching.searchByName();
        cout<<"Searched product/products:"<<endl;
        for(int i=0; i<products.size(); i++)
        {
            if(searchBar == products[i]->getName())
            {
                products[i]->printProduct();
                check++;
            }
        }
        if(check == 0)
        {
            cout<<"Product not found"<<endl;
        }
    }
    if(choice == 2)
    {
        int check = 0;
        string searchBar = searching.searchByCategory();
        cout<<"Searched product/products:"<<endl;
        for(int i=0; i<products.size(); i++)
        {
            if(searchBar == products[i]->getCategory())
            {
                products[i]->printProduct();
                check++;
            }
        }
        if(check == 0)
        {
            cout<<"Product not found"<<endl;
        }
    }

    if(choice == 3)
    {
        int check = 0;
        double searchBarPrice = searching.searchByPrice();
        cout<<"Searched product/products:"<<endl;
        for(int i=0; i<products.size(); i++)
        {
            if(searchBarPrice == products[i]->getPrice())
            {
                products[i]->printProduct();
                check++;
            }
        }
        if(check == 0)
        {
            cout<<"Product not found"<<endl;
        }
    }
}


int Store::customersSize() const {
    return custArr.size();
}

Customer Store::getCustomer(int index) const {
    return custArr[index];
}
