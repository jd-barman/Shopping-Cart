#include<iostream>
#include<vector>
#include<cstring>
#include"data.h"
using namespace std;

//Available products
vector<Product> products = {
    Product(2,"apple", 120),
    Product(5,"mango", 120),
    Product(8,"guava", 40),
    Product(12,"banana", 60),
    Product(4,"pineapple", 70),
    Product(3,"strawberry", 200)
};

//Choosing Product item
Product *chooseProd(){
    string productList;
    cout<<"Available Products : "<<endl;

    for(auto product: products){
        productList.append(product.getName());
    }
    cout<<productList<<endl;
    cout<<"------------------------------"<<endl;


    string choice;
    cin>>choice;


    for(auto i=0;i<products.size();i++){
        if(products[i].getTheChar()==choice){
            return &products[i];
        }
    }

    cout<<"Product Not Found!"<<endl;
    return NULL;
}

//Checkout Functionality
bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int pay = cart.getTotal();
    cout<<"Pay in Cash! : ";

    int paid;
    cin>>paid;

    if(paid>=pay){
        cout<<"Change : "<<paid-pay<<endl;
        cout<<"Thank You For Shopping!"<<endl;
        return true;
    }
    else{
        cout<<"Not Enough Cash!";
        return false;
    }
}

int main(){
    char action;

    Cart cart;

    //Loop continues until payment is not completed
    while(true){
        cout<<"Choose an option - (A)dd Items, (V)iew Cart, (C)heckout"<<endl;
        cin>>action;

        if(action=='a' || action=='A'){
            Product* product = chooseProd();
            if(product!=NULL){
                cout<<"Added to Cart! "<<product->getName()<<endl;

                cart.addProduct(*product);
            }
        }
        else if(action=='v' || action=='V'){
            cout<<"------------------------------"<<endl;
            cout<<cart.viewCart();
            cout<<"------------------------------"<<endl;
        }
        else if(action=='c' || action=='C'){
            cout<<"------------------------------"<<endl;
            cout<<cart.viewCart()<<endl;
            if(checkout(cart)){
                break;
            }
            cout<<"------------------------------"<<endl;
        }
    }
    
    return 0;
}
