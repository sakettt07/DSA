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
class Persistence{
    private:
    ShoppingCart* cart;
    public:
    virtual void save(ShoppingCart *cart)=0;
};
class SQLPersistence:public Persistence{
    public:
    void save(ShoppingCart *cart) override{
            cout<<"Saving the shopping cart to sql database"<<endl;
        }
};
int main(){

return 0;
}