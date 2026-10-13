#include <iostream>
#include <string>

class Door {
public:
	Door() {}
	virtual void Open() = 0;
};

class GasCarDoor : public Door {
public:
	GasCarDoor() {
		std::cout << "Making a door for a gas car.\n";
	}
	void Open() {
		std::cout << "click\n";
	}
};

class ElectricCarDoor : public Door {
public:
	ElectricCarDoor() {
		std::cout << "Making a door for an electric car\n";
	}
	void Open() {
		std::cout << "shhhhh\n";
	}
};


class Engine {
protected:
	std::string sound = "";
public:
	Engine() {}
	virtual void Run() = 0;
};

class GasEngine : public Engine {
public:
	GasEngine() {
		sound = "vroom";
		std::cout << "Making a gas engine.\n";
	}

	void Run() {
		std::cout << sound << "\n";
	}
};

class ElectricEngine : public Engine {
public:
	ElectricEngine() {
		sound = "SHHHH";
		std::cout << "Making an electric engine.\n";
	}

	void Run() {
		std::cout << sound << "\n";
	}
};

class CarFactory {
public:
    virtual Door *buildDoor() = 0;
    virtual Engine *buildEngine() = 0;
};

class GasCarFactory: public CarFactory {
public:
    Door * buildDoor() override {
        return new GasCarDoor();
    }

    Engine * buildEngine() override {
        return new GasEngine();
    }
};

class ElectricCarFactory: public CarFactory {
public:
    Door * buildDoor() override {
        return new ElectricCarDoor();
    }

    Engine * buildEngine() override {
        return new ElectricEngine();
    }
};

int main() {
    CarFactory *carPlant;

    int choice;

	std::cout << "Select a car type: \n";
	std::cout << "1: Gasoline\n";
	std::cout << "2: Electric\n";
	std::cout << "Selection: ";
	std::cin >> choice;

    switch(choice) {
        case(1):
            carPlant = new GasCarFactory();
        break;

        case(2):
            carPlant = new ElectricCarFactory();
        break;

        default:
            std::cout << "Invalid Selection\n";
            carPlant = nullptr;
        break;
    }

    if(!carPlant) return 1;

    Door *myDoor = carPlant->buildDoor();
    Engine *myEngine = carPlant->buildEngine();

    myDoor->Open();
    myEngine->Run();
    
	std::cout << std::endl;
    return 0;
}
