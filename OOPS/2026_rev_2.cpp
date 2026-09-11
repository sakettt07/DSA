#include<bits/stdc++.h>
using namespace std;
// protected variables ko sirf inherited class k members hi access kar sakte h 
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
int main(){

return 0;
}