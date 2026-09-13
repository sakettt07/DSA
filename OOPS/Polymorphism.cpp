#include<bits/stdc++.h>
using namespace std;
// Studying two types of polymorphism Dynamic (Method Overriding) and Static Polymorphism (Method Overloading)
class Car {
    protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

    public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }
    void startEngine(){
        isEngineOn = true;
        cout << "Engine started." << endl;
    }
    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout << "Engine stopped." << endl;
    }
    virtual void accelerate();
    virtual void accelerate(int speed);
    virtual void brake()=0;
    virtual ~Car(){}
};

class ManualCar:public Car{
    private:
    int currentGear;

    public:
    ManualCar(string b, string m):Car(b,m){
        currentGear = 0;
    }
    void shiftGear(int gear){
        if(gear >= 0 && gear <= 6){
            currentGear = gear;
            cout << "Shifted to gear " << currentGear << "." << endl;
        } else {
            cout << "Invalid gear." << endl;
        }
    }
    void accelerate(){
        if(isEngineOn){
            currentSpeed += 10 * (currentGear + 1); // Speed increase depends on the gear
            cout << "Accelerated to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }
    void accelerate(int speed){
        if(isEngineOn){
            currentSpeed += speed * (currentGear + 1); // Speed increase depends on the gear
            cout << "Accelerated to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }
    void brake(){
        if(isEngineOn && currentSpeed > 0){
            currentSpeed -= 10; // Decrease speed by a fixed amount
            if(currentSpeed < 0) currentSpeed = 0;
            cout << "Slowed down to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Cannot brake. Engine is off or car is stationary." << endl;
        }
    }
};
class ElectricCar:public Car{
    private:
    int curretBatteryLevel;
    public:
    ElectricCar(string b, string m):Car(b,m){
        curretBatteryLevel = 100; // Battery level starts at 100%
    }
    void chargeBattery(){
        curretBatteryLevel = 100;
        cout << "Battery fully charged." << endl;
    }
    void accelerate(int speed){
        if(isEngineOn && curretBatteryLevel > 0){
            currentSpeed += speed; // Electric cars accelerate faster
            curretBatteryLevel -= 5; // Battery decreases with acceleration
            cout << "Accelerated to " << currentSpeed << " km/h. Battery level: " << curretBatteryLevel << "%" << endl;
        } else {
            cout << "Cannot accelerate. Engine is off or battery is empty." << endl;
        }

    }
    void accelerate(){
        if(isEngineOn && curretBatteryLevel > 0){
            currentSpeed += 20; // Electric cars accelerate faster
            curretBatteryLevel -= 5; // Battery decreases with acceleration
            cout << "Accelerated to " << currentSpeed << " km/h. Battery level: " << curretBatteryLevel << "%" << endl;
        } else {
            cout << "Cannot accelerate. Engine is off or battery is empty." << endl;
        }
    }
    void brake(){
        if(isEngineOn && currentSpeed > 0){
            currentSpeed -= 15; // Electric cars decelerate faster
            if(currentSpeed < 0) currentSpeed = 0;
            cout << "Slowed down to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Cannot brake. Engine is off or car is stationary." << endl;
        }
    }
};
class AutomaticCar:public Car{

};
int main(){

return 0;
}