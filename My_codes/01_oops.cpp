#include <bits/stdc++.h>
using namespace std;

// Abstraction hides unnecessary details from the client.

class Car {
public:
	virtual void startEngine() = 0;
	virtual void shiftGear(int gear) = 0;
	virtual void accelerate() = 0;
	virtual void brake() = 0;
	virtual void stopEngine() = 0;
	virtual ~Car() {};
};

class SportsCar : public Car {
private:
	string brand;
	string model;
	bool isEngineOn;
	int currentSpeed;
	int currentGear;
	string tyre;

public:
	SportsCar(string brand, string model) {
		this->brand = brand;
		this->model = model;
		isEngineOn = false;
		currentSpeed = 0;
		currentGear = 0;
		tyre = "CEAT";
 	}

 	string getTyre() {
 		return this->tyre;
 	}

 	void setTyre(string tyre) {
 		// validations : control using getters and setters
 		this->tyre = tyre;
 	}

	void startEngine() {
		isEngineOn = true;
		cout << brand << " " << model << " : Engine starts with a roar!" << endl;
	}

	void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

int main() {
	Car* myCar = new SportsCar("Ford", "Mustang");

	myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;
}
