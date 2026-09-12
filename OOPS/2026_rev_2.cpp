#include<bits/stdc++.h>
using namespace std;
// protected variables ko sirf inherited class k members hi access kar sakte h 
// if we had made a method in a class as virtual then it can be overridden in the derived class and the derived class's method will be called instead of the base class's method when called through a base class pointer or reference.
class Car{
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
    void accelerate(int speed){
        if(isEngineOn){
            currentSpeed += speed;
            cout << "Accelerated to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Cannot accelerate. Engine is off." << endl;
        }
    }
    void brake(int speed){
        if(isEngineOn && currentSpeed > 0){
            currentSpeed -= speed;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << "Slowed down to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Cannot brake. Engine is off or car is stationary." << endl;
        }
    }
    virtual ~Car(){
        cout << "Car object destroyed." << endl;
    }
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
};
class ElectricCar:public Car{
    private:
    int batteryLevel;
    public:
    ElectricCar(string b, string m):Car(b,m){
        batteryLevel = 100; // Battery level in percentage
    }
    void chargeBattery(int amount){
        if(amount > 0 && batteryLevel < 100){
            batteryLevel += amount;
            if(batteryLevel > 100) batteryLevel = 100;
            cout << "Battery charged to " << batteryLevel << "%." << endl;
        } else {
            cout << "Invalid charge amount or battery already full." << endl;
        }
    }
};
int main(){
    ManualCar* myManualCar = new ManualCar("Toyota", "Corolla");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate(30);
    myManualCar->brake(10);
    myManualCar->stopEngine();
    delete myManualCar;
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery(20);
    myElectricCar->startEngine();
    myElectricCar->accelerate(50);  
    myElectricCar->brake(20);
    myElectricCar->stopEngine();
    delete myElectricCar;
return 0;
}