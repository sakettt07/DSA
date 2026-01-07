#include<bits/stdc++.h>
using namespace std;

class vehicle{
    public:
    int speed;
    int wheels;
    string company;
    string mode;
    vehicle(){
        cout<<"Default constructor called"<<endl;
    }
    vehicle(int s,int w,string c,string m){
        cout<<"Constructor called"<<endl;
        speed=s;
        wheels=w;
        company=c;
        mode=m;
    }
    int run(){
        cout<<"Vehicle is running"<<endl;
    }
};

int main(){
    vehicle v1;
    v1.speed=100;
    v1.wheels=4;    
    v1.company="BMW";
    v1.mode="Petrol";

return 0;
}