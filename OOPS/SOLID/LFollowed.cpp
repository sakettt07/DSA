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


class DepositableProcess{
    public:
    virtual void deposit(double amt)=0;
};
class WithdrawableProcess:public DepositableProcess{
    public:
    
    virtual void withdraw(double amt)=0;
};
class SavingsAccount:public WithdrawableProcess{
    private:
    double balance;
    public:
    SavingsAccount(){
        balance=0;
    }
    void deposit(double amt){
        balance+=amt;
        cout<<"Money Deposited"<<endl;
    }
    void withdraw(double amt){
        if(balance>=amt){
            balance-=amt;
            cout<<"Money Withdrawn"<<endl;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    };
};
class CurrentAccount:public WithdrawableProcess{
    private:
    double balance;
    public:
    CurrentAccount(){
        balance=0;
    }
    void deposit(double amt){
        balance+=amt;
        cout<<"Money Deposited"<<endl;
    }
    void withdraw(double amt){
        if(balance>=amt){
            balance-=amt;
            cout<<"Money Withdrawn"<<endl;
        }
        else{
            cout<<"Insufficient balance"<<endl;
        }
    };
};
class FixedTermAccount:public DepositableProcess{
    private:
    double balance;
    public:
    FixedTermAccount(){
        balance=0;
    }
    void deposit(double amt){
        balance+=amt;
        cout<<"Money Deposited"<<endl;
    }
};
// Solution -1 Where we are tightly coupling the BankClient on the basis of type of account.
class BankClient{
    private:
    vector<WithdrawableProcess*>accounts;
    vector<DepositableProcess*>deposits;
    public:
    BankClient(vector<WithdrawableProcess*>accs,vector<DepositableProcess*>deposits){
        this->accounts=accs;
        this->deposits=deposits;
    }
    void processTransaction(){
        for(WithdrawableProcess* acc:accounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(DepositableProcess* dep:deposits){
            dep->deposit(1000);
        }
    }
};
class BankClient1{
    vector<Account*>accounts;
    public:
    BankClient1(vector<Account*>accs){
        this->accounts=accs;
    }
    void processTransaction(){
        for(Account* acc:accounts){
            acc->deposit(1000);
            
                if(typeid(*acc)==typeid(FixedTermAccount)){
                    cout<<"Withdrawals are not allowed from Fixed Term Account"<<endl;
                }
                else{
                    try{
                        acc->withdraw(500);
                    }
                    catch(logic_error& e){
                        cout<<e.what()<<endl;
                    }
                }
        }
    }
};
int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    // accounts.push_back(new CurrentAccount());
    // accounts.push_back(new FixedTermAccount());
    // BankClient* client=new BankClient(accounts);
    // client->processTransaction();
    vector<WithdrawableProcess*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    vector<DepositableProcess*> depositableAccounts;
    depositableAccounts.push_back(new FixedTermAccount());
    BankClient* client=new BankClient(withdrawableAccounts,depositableAccounts);
    client->processTransaction();
    
return 0;
}