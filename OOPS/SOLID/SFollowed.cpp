#include<bits/stdc++.h>
using namespace std;

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
};
class ShoppingCartPrinter{
    ShoppingCart* cart;
    public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }
    void printInvoice(){
        cout<<"E Mart Invoice ::-- "<<endl;
        for(auto p:cart->getProducts()){
            cout<<p->name<<":"<<p->price<<endl;
        }
    }
};
class ShoppingCartDB{
    ShoppingCart* cart;
    public:
    ShoppingCartDB(ShoppingCart* cart){
        this->cart=cart;
    }
    void saveToDB(){
        cout<<"Saving the shopping cart to database"<<endl;
    }
};
int main(){

return 0;
}