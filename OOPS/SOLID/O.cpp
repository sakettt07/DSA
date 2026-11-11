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

// BREAKKk
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
class ShoppingCartStorage{
    private:
    ShoppingCart* cart;
    public:
    ShoppingCartStorage(ShoppingCart* cart){
        this->cart=cart;
    }   
    void saveToDB(){
        cout<<"Saving the shopping cart to database"<<endl;
    }
    void saveTosql(){
        cout<<"Saving the shopping cart to sql database"<<endl;
    }

};
int main(){
    return 0;
}