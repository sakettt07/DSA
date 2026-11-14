#include<bits/stdc++.h>
using namespace std;

// L - Liskov substitutio principle is not followed here.
class Account{
    public: 
    virtual void withdraw(double amt)=0;
    virtual void deposit(double amt)=0;
};
class SavingAccount:public Account{
    private:
    double balance;
    public:
    SavingAccount(){
        balance=0;
    }
    void deposit(double amt){
        balance+=amt;
        cout<<"Deposited: "<<amt<<endl;
    }
    void withdraw(double amt){
        if(balance>=amt){
            balance-=amt;
            cout<<"Withdrawn: "<<amt<<endl;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    };
};
class CurrentAccount:public Account{
    private:
    double balance;
    public:
    CurrentAccount(){
        balance=0;
    }
    void deposit(double amt){
        balance+=amt;
        cout<<"Deposited: "<<amt<<endl;
    }
    void withdraw(double amt){
        if(balance>=amt){
            balance-=amt;
            cout<<"Withdrawn: "<<amt<<endl;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    };
};
class FixedTermAccount:public Account{
    private:
    double balance;
    public:
    FixedTermAccount(){
        balance=0;
    }
    void deposit(double amt){
        balance+=amt;
        cout<<"Deposited: "<<amt<<endl;
    }
    void withdraw(double amt){
        throw logic_error("Withdrawals are not allowed from Fixed Term Account");
    };
};
class BankClient{
    vector<Account*>accounts;
    public:
    BankClient(vector<Account*>accs){
        this->accounts=accs;
    }
    void processTransaction(){
        for(Account* acc:accounts){
            acc->deposit(1000);
            try{
                acc->withdraw(500);
            }
            catch( const logic_error& e){
                cout<<e.what()<<endl;
            }
        }
    }
};
int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());
    BankClient* client=new BankClient(accounts);
    client->processTransaction();
return 0;
}