#include <bits/stdc++.h>
using namespace std;

class Product
{
private:
    int sku;
    string name;
    double price;

public:
    Product(int id, string name, double price)
    {
        this->sku = id;
        this->name = name;
        this->price = price;
    }
    int getSku()
    {
        return this->sku;
    }
    string getName()
    {
        return this->name;
    }
    double getPrice()
    {
        return this->price;
    }
};

class ProductFactory
{
public:
    static Product *createProduct(int sku)
    {
        string name;
        double price;
        if (sku == 101)
        {
            name = "Laptop";
            price = 10000;
        }
        else if (sku == 102)
        {
            name = "Banana";
            price = 100;
        }
        else if (sku == 103)
        {
            name = "Apple",
            price = 130;
        }
        else if (sku == 104)
        {
            name = "Milk";
        price:
            130;
        }
        else
        {
            name = "Item" + to_string(sku);
            price = 500;
        }
        return new Product(sku, name, price);
    }
};

class InventoryStore
{
public:
    virtual ~InventoryStore() {};
    virtual void addProduct(Product *product, int qty) = 0;
    virtual void removeProduct(int sku, int qty) = 0;
    virtual int checkStock(int sku) = 0;
    virtual vector<Product *> listAvailableProducts() = 0;
};

class DbInventoryStore : public InventoryStore
{
private:
    map<int, int> *stock;          // stock map which denotes the id,quantity
    map<int, Product *> *products; // find the product using id

public:
    DbInventoryStore()
    {
        stock = new map<int, int>();
        products = new map<int, Product *>();
    }
    ~DbInventoryStore()
    {
        for (auto it : *products)
        {
            delete it.second;
        }
        delete stock;
        delete products;
    }

    void addProduct(Product *prod, int qty) override
    {
        // find the product in the map
        // if not present then add it
        // else update the quantity
        int sku = prod->getSku();
        if (products->count(sku) == 0)
        {
            (*products)[sku] = prod;
        }
        else
        {
            delete prod;
        }
        (*stock)[sku] += qty;
    }
    void removeProduct(int sku, int qty) override
    {
        if (stock->count(sku) == 0)
        {
            return;
        }
        int currQty = (*stock)[sku];
        int remainingQty = currQty - qty;
        if (remainingQty > 0)
        {
            (*stock)[sku] = remainingQty;
        }
        else
        {
            stock->erase(sku);
        }
    }

    int checkStock(int sku) override
    {
        if (stock->count(sku) == 0)
        {
            return 0;
        }
        return (*stock)[sku];
    }

    vector<Product *> listAvailableProducts() override
    {
        vector<Product *> available;
        for (auto it : *stock)
        {
            int sku = it.first;
            int qty = it.second;
            if (qty > 0 && products->count(sku))
            {
                available.push_back((*products)[sku]);
            }
        }
    }
};

class InventoryManager
{
    InventoryStore *store;

public:
    InventoryManager(InventoryStore *store)
    {
        this->store = store;
    }
    // methods which manager can perform (Defining the delegates)
    void addStock(int sku, int qty)
    {
        Product *prod = ProductFactory::createProduct(sku);
        store->addProduct(prod, qty);
        cout << "Inventory manager added stock of the sku " << sku << " with quantity " << qty << endl;
    }
    void removeStock(int sku, int qty)
    {
        store->removeProduct(sku, qty);
        cout << "Inventory manager removed the stock" << endl;
    }
    int checkStock(int sku)
    {
        return store->checkStock(sku);
    }

    vector<Product *> listAvailableProducts()
    {
        return store->listAvailableProducts();
    }
};

// Replenish Strategies

class ReplenishStrategy
{
public:
    virtual void replenish(InventoryManager *manager, map<int, int> itemsToReplenish) = 0; // map represents the sku & quantity
    virtual ~ReplenishStrategy() {};
};

// like we have discussed two replenish strategies (Threshold,Weekly)

class ThresholdReplenishStrategy : public ReplenishStrategy
{
private:
    int threshold;

public:
    ThresholdReplenishStrategy(int threshold)
    {
        this->threshold = threshold;
    }
    void replenish(InventoryManager *manager, map<int, int> itemsToReplenish) override
    {
        cout << "ThresholdReplenish Checking the threshold..." << endl;
        for (auto it : itemsToReplenish)
        {
            int sku = it.first;
            int qtyToAdd = it.second;
            int currentStock = manager->checkStock(sku);
            if (currentStock < threshold)
            {
                manager->addStock(sku, qtyToAdd);
                cout << "The current stock of the Sku was " << current_exception << " and replenished with" << qtyToAdd << " and now the updated stock is " << currentStock + qtyToAdd << endl;
            }
        }
    }
};
// 2nd replenish strategy

class WeeklyReplenishStrategy : public ReplenishStrategy
{
public:
    WeeklyReplenishStrategy() {}
    void replenish(InventoryManager *manager, map<int, int> itemsToReplenish) override
    {
        cout << "WeeklyReplenish Checking the threshold..." << endl;
    }
};

// DARK STORE

class DarkStore
{
    string name;
    double x, y;
    InventoryManager *manager;
    ReplenishStrategy *replenishStrategy;

public:
    DarkStore(string n, double xCoods, double yCoods)
    {
        name = n;
        x = xCoods;
        y = yCoods;
        manager = new InventoryManager(new DbInventoryStore);
    }
    ~DarkStore()
    {
        delete manager;
        if (replenishStrategy)
            delete replenishStrategy;
    }
    double distanceTo(double ux, double uy)
    {
        return sqrt((x - ux) * (x - ux) + (y - uy) * (y - uy));
    }
    void runReplenishment(map<int, int> itemsToReplenish)
    {
        replenishStrategy->replenish(manager, itemsToReplenish);
    }

    // some delegate methods
    vector<Product *> getAllProducts()
    {
        return manager->listAvailableProducts();
    }

    // to take care of the principle of least priviledge
    void addStock(int sku, int qty)
    {
        Product *prod = ProductFactory::createProduct(sku);
        manager->addStock(sku, qty);
    }
    int checkStock(int sku)
    {
        return manager->checkStock(sku);
    }
    void removeStock(int sku, int qty)
    {
        manager->removeStock(sku, qty);
    }

    // getter/setter
    void setReplenishStrategy(ReplenishStrategy *strategy)
    {
        this->replenishStrategy = strategy;
    }
    string getName()
    {
        return this->name;
    }
    double getXCoods()
    {
        return this->x;
    }
    double getYCoods()
    {
        return this->y;
    }
    InventoryManager *getManager()
    {
        return this->manager;
    }
};

class DarkStoreManager
{
private:
    vector<DarkStore *>* stores;
    static DarkStoreManager *instance;
    DarkStoreManager()
    {
        stores = new vector<DarkStore *>();
    }

    public:
    static DarkStoreManager *getInstance(){
        if(instance == NULL){
            instance = new DarkStoreManager();
        }
        return instance;
    }
    void registerDarkStore(DarkStore* ds){
        stores->push_back(ds);
    }
    vector<DarkStore*> getNearByDarkStores(double ux,double uy,double maxDistance){
        
    }
};