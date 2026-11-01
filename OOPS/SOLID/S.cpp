#include<bits/stdc++.h>
using namespace std;

// below is the example of S of SOLID violating the principle of single responsibility principle
class Product{
    public:
    int price;
    string name;

    Product(int price,string name){
        this->price=price;
        this->name=name;
    }
};

class ShoppingCart{
    private:
    vector<Product*> products;
    public:
        void addProduct(Product* p){
            products.push_back(p);
        }
        const vector<Product*>& getProducts(){
            return products;
        }
        double calculateTotalPrice(){
            double total=0;
            for(auto p:products){
                total+=p->price;
            }
            return total;
        }
        void printInvoice(){
            cout<<"Saket Cart Invoice::---"<<endl;
            for(auto p:products){
                cout<< p->name<<":"<<p->price<<endl;
            }
            cout<<"Total Price:"<<calculateTotalPrice()<<endl;
        }
        void saveToDB(){
            cout<<"Saving the shopping cart to database"<<endl;
        }

        // below is the xample for solid
    
};

int main(){
    ShoppingCart* cart=new ShoppingCart();
    cart->addProduct(new Product(150,"TShirt"));
    cart->addProduct(new Product(150,"cable"));

    cart->printInvoice();
    cart->saveToDB();
return 0;
}