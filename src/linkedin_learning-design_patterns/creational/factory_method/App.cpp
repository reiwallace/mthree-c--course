#include <iostream>
#include <string>

class Coffee {
protected:
	std::string type;

public:
	Coffee() {}

	std::string getType() {
		return type;
	}
};

class Espresso : public Coffee {
public:
	Espresso() : Coffee() {
		type = "Espresso";
		std::cout << "\nMaking a cup of espresso\n";
		std::cout << "Grind and brew one scoop of espresso beans.\n";
	}
};

class Cappuccino : public Coffee {
public:
	Cappuccino() : Coffee() {
		type = "Cappuccino";
		std::cout << "\nMaking a cup of cappuccino\n";
		std::cout << "Grind and brew one scoop of espresso beans.\n";
		std::cout << "Heat and foam milk.\n";
	}
};

class EmptyCup: public Coffee {
public:
    EmptyCup(): Coffee() {
        type = "Empty Cup";
    }
};

class CoffeeMakerFactory {
private:
    Coffee *coffee;

public:
    Coffee *getCoffee() {
        int choice;
        std::cout << "Select type of coffee to make: \n";
        std::cout << "1: Espresso\n";
        std::cout << "2: Cappuccino\n";
        std::cout << "Selection: " << std::endl;

        std::cin >> choice;

        switch(choice) {
            case 1:
                return new Espresso();

            case 2:
                return new Cappuccino();

            default:
                std::cout << "Invalid selection\n";
                return new EmptyCup();
        }
    }
};

int main() {
    CoffeeMakerFactory coffeeMachine;
    Coffee *cup;

    cup = coffeeMachine.getCoffee();

    std::cout << "\nYou have asked for a(n) " << cup->getType() << "\n";

    delete cup;

    std::cout << std::endl;
    return 0;
}