#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
    virtual void startEngine()=0;
    virtual void shiftGear(int gear)=0;
    virtual void accelerate()=0;
    virtual void brake()=0;
    virtual void stopEngine()=0;
    virtual ~Car(){}
};
class SportCar:public Car{
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    SportCar(string b,string m){
        this->brand=b;
        this->model=m;
        isEngineOn=false;
        currentSpeed=0;
        currentGear=0;
    }
    void startEngine(){
        isEngineOn=true;
        cout<<"Engine started for "<<brand<<" "<<model<<endl;
    }
    void shiftGear(int gear){
        if(isEngineOn){
            currentGear=gear;
            cout<<"Gear shifted to "<<currentGear<<" for "<<brand<<" "<<model<<endl;
        }else{
            cout<<"Cannot shift gear. Engine is off for "<<brand<<" "<<model<<endl;
        }
    }
    void accelerate(){
        if(isEngineOn){
            currentSpeed+=10;
            cout<<"Accelerating. Current speed: "<<currentSpeed<<" km/h for "<<brand<<" "<<model<<endl;
        }else{
            cout<<"Cannot accelerate. Engine is off for "<<brand<<" "<<model<<endl;
        }
    }
    void brake(){
        if(isEngineOn && currentSpeed>0){
            currentSpeed-=10;
            cout<<"Braking. Current speed: "<<currentSpeed<<" km/h for "<<brand<<" "<<model<<endl;
        }else{
            cout<<"Cannot brake. Either engine is off or speed is zero for "<<brand<<" "<<model<<endl;
        }
    }
    void stopEngine(){
        if(isEngineOn){
            isEngineOn=false;
            currentSpeed=0;
            currentGear=0;
            cout<<"Engine stopped for "<<brand<<" "<<model<<endl;
        }else{
            cout<<"Engine is already off for "<<brand<<" "<<model<<endl;
        }
    }
};
int main(){
    Car* myCar=new SportCar("Ferrari","488");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
    delete myCar;

return 0;
}