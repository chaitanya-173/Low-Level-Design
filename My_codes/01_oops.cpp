#include <bits/stdc++.h>
using namespace std;

// Abstraction hides unnecessary details from the client.

// Encapsulation says 2 things:
// 1. An Object's Characteristics and its behaviour are encapsulated together
// within that Object.
// 2. All the characteristics or behaviours are not for everyone to access.
// Object should provide data security.

// Dynamic polymorphism -> function overriding -> run-time polymorphism
// we can have a virtual function in our abstract class Car named accelerate
// but their children i.e. manual car and electric car will define them differently
// late binding (dynamic binding)

// Static polymorphism -> function overloading -> compile-time polymorphism

// no further inheritance -> class A final {}; 
// no further function overloading -> virtual void show() final;
// explicit override -> void show() override {}

class Car {
protected:
	string brand;
	string model;
	bool isEngineOn;
	int currentSpeed;

public:
	Car(string brand, string model) {
		this->brand = brand;
		this->model = model;
		this->isEngineOn = false;
		this->currentSpeed = 0;
	}

	// common methods for all cars
	void startEngine() {
		isEngineOn = true;
		cout << brand << " " << model << " : Engine started!" << endl;
	}

	void stopEngine() {
		isEngineOn = false;
		currentSpeed = 0;
		cout << brand << " " << model << " : Engine turned off!" << endl;
	}

	virtual void accelerate() = 0; // abstract method for dynamic polymorphism
	virtual void accelerate(int speed) = 0; // abstract method for dynamic polymorphism
	virtual void brake() = 0; // abstract method for dynamic polymorphism
	virtual ~Car() {}; // virtual destructor
};

class ManualCar : public Car {
private:
	int currentGear;

public:
	ManualCar(string brand, string model) : Car(brand, model) {
		this->currentGear = 0;
	}

	// specialized method for manual car
	void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
	}

	// overriding accelerate -> dynamic polymorphism
	void accelerate() {
		if(!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
	}

	// overloading and overloading accelerate
	void accelerate(int speed) {
		if(!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += speed;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
	}

	// overriding brake
	void brake() {
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
};

class ElectricCar : public Car {
private:
	int batteryLevel;

public:
	ElectricCar(string brand, string model) : Car(brand, model) {
		this->batteryLevel = 100;
	}

	// specialized method for electric car
	void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged!" << endl;
	}

	// overriding accelerate -> dynamic ploymorphism
	void accelerate() {
		if(!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        if(batteryLevel <= 0) {
        	cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
        }
        batteryLevel -= 10;
        currentSpeed += 15;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
	}

	// overloading and overloading accelerate
	void accelerate(int speed) {
		if(!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        if(batteryLevel <= 0) {
        	cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
        }
        batteryLevel -= 10 + speed;
        currentSpeed += speed;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
	}

	// overriding brake
	void brake() {
        currentSpeed -= 15;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
};

int main() {
	Car* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->accelerate();
    myManualCar->accelerate(); // function overloading
    myManualCar->accelerate(50); // function overloading
    myManualCar->brake();
    myManualCar->stopEngine();

    cout << "----------------------" << endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->accelerate(); // function overloading
    myElectricCar->accelerate(40); // function overloading
    myElectricCar->brake();
    myElectricCar->stopEngine();

    // Cleanup
    delete myManualCar;
    delete myElectricCar;
}
