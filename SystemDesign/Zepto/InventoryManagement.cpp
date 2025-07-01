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
    vector<DarkStore *> *stores;
    static DarkStoreManager *instance;
    DarkStoreManager()
    {
        stores = new vector<DarkStore *>();
    }

public:
    static DarkStoreManager *getInstance()
    {
        if (instance == NULL)
        {
            instance = new DarkStoreManager();
        }
        return instance;
    }
    void registerDarkStore(DarkStore *ds)
    {
        stores->push_back(ds);
    }
    vector<DarkStore *> getNearByDarkStores(double ux, double uy, double maxDistance)
    {
        vector<pair<double, DarkStore *>> distances;
        for (auto ds : *stores)
        {
            double dist = ds->distanceTo(ux, uy);
            if (dist <= maxDistance)
            {
                distances.push_back(make_pair(dist, ds));
            }
        }
        // from the above iteration all the stores nearby will appear for the selection
        sort(distances.begin(), distances.end(), [](auto &a, auto &b)
             { return a.first < b.first; });
        vector<DarkStore *> result;
        for (auto &p : distances)
        {
            result.push_back(p.second);
        }
        return result;
    }
    ~DarkStoreManager()
    {
        for (auto ds : *stores)
        {
            delete ds;
        }
        delete stores;
    }
};

DarkStoreManager *DarkStoreManager::instance = NULL;

// Our Cart and User classes

class Cart
{
public:
    vector<pair<Product *, int>> items;
    void addItem(int sku, int qty)
    {
        Product *prod = ProductFactory::createProduct(sku);
        items.push_back(make_pair(prod, qty));
        cout << "Added the product with sku " << sku << " with quantity " << qty << endl;
    }

    double getCartTotal()
    {
        double sum = 0;
        for (auto item : items)
        {
            sum += (item.first->getPrice() * item.second);
        }
        return sum;
    }
    vector<pair<Product *, int>> getItems()
    {
        return items;
    }
    ~Cart()
    {
        for (auto &item : items)
        {
            delete item.first;
        }
    }
};

class User
{
public:
    string name;
    double x, y;
    Cart *cart;
    User(string n, double xCoods, double yCoods)
    {
        name = n;
        x = xCoods;
        y = yCoods;
        cart = new Cart();
    }
    ~User()
    {
        delete cart;
    }
    Cart *getCart()
    {
        return cart;
    }
};

class DeliveryPartner
{
public:
    string name;
    DeliveryPartner(string n)
    {
        name = n;
    }
};

class Order
{
public:
    static int nextId;
    int id;
    User *user;
    vector<pair<Product *, int>> items;
    vector<DeliveryPartner *> deliveryPartners;
    double totalAmount;
    Order(User *u)
    {
        id = nextId++;
        user = u;
        totalAmount = 0.0;
    }
};
int Order::nextId = 1;

class OrderManager
{
private:
    vector<Order *> *orders;
    static OrderManager *instance;
    OrderManager()
    {
        orders = new vector<Order *>();
    }

public:
    static OrderManager *getInstance()
    {
        if (instance == NULL)
        {
            instance = new OrderManager();
        }
        return instance;
    }
    // the main driving function for the entire application.
    void placeOrder(User *user, Cart *cart)
    {

        cout << "\n Placing order for: " << user->name << endl;
        vector<pair<Product *, int>> requestedItems = cart->getItems();

        // 1. Find out all the nearest dark stores.
        double maxDist = 5.0;
        vector<DarkStore *> nearByDarkStores = DarkStoreManager::getInstance()->getNearByDarkStores(user->x, user->y, maxDist);

        if (nearByDarkStores.empty())
        {
            cout << "No dark stores nearby" << endl;
            return;
        }

        // 2. Find the best dark Store who owns most of the items.
        DarkStore *firstStore = nearByDarkStores.front();

        bool allInFirst = true;
        for (pair<Product *, int> &item : requestedItems)
        {
            int sku = item.first->getSku();
            int qty = item.second;
            if (firstStore->checkStock(sku) < qty)
            {
                allInFirst = false;
                break;
            }
        }
        Order *order = new Order(user);

        if (allInFirst)
        {
            cout << "All items are available in the first store" << firstStore->getName() << endl;
            for (pair<Product *, int> &item : requestedItems)
            {
                int sku = item.first->getSku();
                int qty = item.second;
                firstStore->removeStock(sku, qty);
                order->items.push_back(item);
            }
            order->totalAmount = cart->getCartTotal();
            order->deliveryPartners.push_back(new DeliveryPartner("DP1"));
            cout << "ASsigned delivery partner: Partner1\n";
        }
        // we need multiple delivery partners as we need to take items from different store.

        else
        {
            cout << "Splitting order across stores... \n";
            map<int, int> allItems; // sku-Qty
            for (pair<Product *, int> &item : requestedItems)
            {
                allItems[item.first->getSku()] += item.second;
            }
            int partnerId = 1;
            for (DarkStore *store : nearByDarkStores)
            {
                if (allItems.empty())
                {
                    break;
                }
                cout << "\nChecking store: " << store->getName() << endl;
                bool assigned = false;
                vector<int> toErase;

                for (auto &[sku,qty] : allItems)
                {
                    int available = store->checkStock(sku);
                    if (available <= 0)
                        continue;

                    int takenQty = min(available, qty);
                    store->removeStock(sku, takenQty);

                    cout << "Item: " << sku << " taken from store: " << store->getName() << " with quantity: " << takenQty << endl;
                    order->items.push_back({ProductFactory::createProduct(sku), takenQty});

                    if (qty > takenQty)
                    {
                        allItems[sku] -= takenQty;
                    }
                    else
                    {
                        toErase.push_back(sku);
                    }
                    assigned = true;
                }

                // after iterating all the items we erase
                for (int sku : toErase)
                    allItems.erase(sku);

                if (assigned)
                {
                    string name = "Partner" + to_string(partnerId++);
                    order->deliveryPartners.push_back(new DeliveryPartner(name));
                    cout << "Assigned delivery partner: " << name << endl;
                }
            }
            if (!allItems.empty())
            {
                cout << "Some items are not available in any of the stores" << endl;
                for (auto &[sku, qty] : allItems)
                {
                    cout << "Item: " << sku << " not available" << endl;
                }
            }

            double sum = 0;
            for (auto &item : order->items)
            {
                sum += item.first->getPrice() * item.second;
            }
            order->totalAmount = sum;
        }
        // printing the order summary
        cout << "Order Manager" << order->id << endl;
        cout << "User" << user->name << endl;
        for (auto &item : order->items)
        {
            cout << "SKU" << item.first->getSku() << "(" << item.first->getName() << ") x" << item.second << "@ Rs." << item.first->getPrice() << "\n";
        }
        cout << "Total Amount: " << order->totalAmount << endl;
        for (auto *dp : order->deliveryPartners)
        {
            cout << "Delivery Partner: " << dp->name << endl;
        }
        orders->push_back(order);
        cout << "Order placed successfully" << endl;
    }

    vector<Order *> getAllOrders()
    {
        return *orders;
    }
    ~OrderManager()
    {
        for (auto order : *orders)
        {
            delete order;
        }
        delete orders;
    }
};
OrderManager *OrderManager::instance = nullptr;

// MAIN High Level Design

class Zepto
{
public:
    static void showAllItems(User *user)
    {
        cout << "Zepto all available products within the 5KM range" << endl;
        DarkStoreManager *dsManager = DarkStoreManager::getInstance();
        vector<DarkStore *> stores = dsManager->getNearByDarkStores(user->x, user->y, 5.0);

        map<int, double> skuPrice;
        map<int, string> skuName;
        for (DarkStore *darkstore : stores)
        {
            vector<Product *> products = darkstore->getAllProducts();
            for (Product *product : products)
            {
                int sku = product->getSku();
                if (skuPrice.count(sku) == 0)
                {
                    skuPrice[sku] = product->getPrice();
                    skuName[sku] = product->getName();
                }
            }
        }

        for (auto &entry : skuPrice)
        {
            cout << "SKU: " << entry.first << " Name: " << skuName[entry.first] << " Price: " << entry.second << endl;
        }
    }
    static void initialize()
    {
        auto dsManager = DarkStoreManager::getInstance();
        DarkStore *darkstoreA = new DarkStore("DarkStoreA", 0.0, 0.0);
        darkstoreA->setReplenishStrategy(new ThresholdReplenishStrategy(3));

        cout << "Adding stocks in darkstore A" << endl;
        darkstoreA->addStock(1, 10);
        darkstoreA->addStock(2, 20);

        DarkStore *darkstoreB = new DarkStore("DarkStoreB", 0.0, 0.0);
        darkstoreB->setReplenishStrategy(new ThresholdReplenishStrategy(3));
        cout << "Adding stocks in darkstore B" << endl;
        darkstoreB->addStock(1, 10);
        darkstoreB->addStock(2, 20);

        DarkStore *darkstoreC = new DarkStore("DarkStoreC", 0.0, 0.0);
        darkstoreC->setReplenishStrategy(new ThresholdReplenishStrategy(3));
        cout << "Adding stocks in darkstore C" << endl;
        darkstoreC->addStock(1, 10);
        darkstoreC->addStock(2, 20);

        dsManager->registerDarkStore(darkstoreA);
        dsManager->registerDarkStore(darkstoreB);
        dsManager->registerDarkStore(darkstoreC);
    }
};

int main(){
    Zepto::initialize();

    User* user=new User("Saket", 1.0, 1.0);
    cout<<"User with the name"<<user->name<<"is created"<<endl;

    Zepto::showAllItems(user);


    cout<<"Userr Adds item to the cart"<<endl;
    Cart* cart=user->getCart();
    cart->addItem(1,2);
    cart->addItem(2,3);
    cart->addItem(3,4);

    // now the order will b eplaced
    OrderManager::getInstance()->placeOrder(user,user->cart);

    delete user;
    delete DarkStoreManager::getInstance();

    return 0;

}