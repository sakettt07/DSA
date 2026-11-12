#include<bits/stdc++.h>
using namespace std;

class Account{
    public: 
    virtual void withdraw(double amt)=0;
    virtual void deposit(double amt)=0;
};
class SavingAccount:public Account{
    private:
    double balance;
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
    SavingAccount(){
        balance=0;
    }
    void deposit(double amt){
        balance+=amt;
        cout<<"Deposited: "<<amt<<endl;
    }
    void withdraw(double amt){
        throw runtime_error("Withdrawals are not allowed from Fixed Term Account");
    };
};
int main(){

return 0;
}