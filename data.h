#include<string>
#include<unordered_map>
using namespace std;

class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;

    public:
        Product(){}

        Product(int id, string name, int price){
            this->id = id;
            this->price = price;
            this->name = name;
        }

        //Gettinh Item name and price
        string getName(){
            return name+" : Rs. " + to_string(price) +"\n";
        }

        //Getting first character from item name
        string getTheChar(){
            return name.substr(0,1);
        }

        friend class Item;
        friend class Cart;
};

class Item{
    Product product;
    int quantity;

    public:
    Item(){}
    //Constructor using Initialisation list
    Item(Product p, int q):product(p), quantity(q){}

    // price = quantity * item price
    int getPrice(){
        return quantity * product.price;
    }

    // quantity * item = price
    string getInfo(){
        return to_string(quantity) + " * " + product.name + " Rs. " + to_string(quantity * product.price)+"\n";
    }

    friend class Cart;
};

class Cart{
    unordered_map<int,Item> items;

    public:
        //Adding New Item
        void addProduct(Product product){
            if(items.count(product.id)==0){
                Item newItem(product,1);
                items[product.id] = newItem;
            }
            else{
                items[product.id].quantity +=1;
            }
        }

        //Getting Total Price
        int getTotal(){
            int total = 0;
            for(auto itemPair: items){
                auto item = itemPair.second;
                total += item.getPrice();
            }
            return total;
        }

        // View Cart
        string viewCart(){
            if(items.empty()){
                return "Cart is Empty!";
            }

            string inList;
            int totalCart = getTotal();

            for(auto itemPair: items){
                auto item = itemPair.second;

                inList.append(item.getInfo());
            }

            return inList + "\nTotal Amount : Rs. "+ to_string(totalCart)+"\n";
        }

        //Check if Cart is Empty or not
        bool isEmpty(){
            return items.empty();
        }
};