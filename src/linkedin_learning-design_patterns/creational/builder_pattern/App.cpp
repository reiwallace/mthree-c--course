#include <iostream>
#include <string>

#pragma region Entrees
// Base Entree class
class Entree {
protected:
	std::string entree;
public:
	const std::string &getEntree() {
		return entree;
	}
};

// Derived Buger class
class Burger : public Entree {
public:
	Burger() {
		std::cout << "\n Grill burger patty, add tomatoes and place them in a bun";
		entree = "hamburger";
	}
};

// Derived Hotdog class
class Hotdog : public Entree {
public:
	Hotdog() {
		std::cout << "\n Cook sausage and place it in a bun";
		entree = "hotdog";
	}
};
#pragma endregion Entrees

#pragma region Sides
// Base Side class
class Side {
protected:
	std::string side;
public:
	const std::string &getSide() {
		return side;
	}
};

//Derived Fries class
class Fries : public Side {
public:
	Fries() {
		std::cout << "\n Fry and season potatoes";
		side = "fries";
	}
};

//Derived Salad class
class Salad : public Side {
public:
	Salad() {
		std::cout << "\n Toss greens and dressing together";
		side = "salad";
	}
};
#pragma endregion Sides

class Drink {
protected:
	std::string drink;
public:
	Drink() {
		std::cout << "\n Fill cup with soda\n";
		drink = "soda";
	}

	const std::string &getDrink() {
		return drink;
	}
};

// Complex MealCombo object that contains an Entree, a Side and a Drink object
class MealCombo {
private:
	Entree * entree;
	Side *side;
	Drink *drink;
	std::string bag;

public:
	MealCombo(const std::string &type) {
		bag = "\n" + type + " meal combo:";
	}

	void setEntree(Entree *e) {
		entree = e;
	}

	void setSide(Side *s) {
		side = s;
	}

	void setDrink(Drink *d) {
		drink = d;
	}

	const std::string &openMealBag() {
		bag = bag + entree->getEntree() + ", " + side->getSide() + ", " + drink->getDrink();
		return bag;
	}
};

#pragma region Builders
// Base Builder
class MealBuilder {
protected:
    MealCombo *meal;

public:
    virtual void cookEntree() = 0;
    virtual void cookSide() = 0;
    virtual void fillDrink() = 0;
    virtual MealCombo* getMeal() {
        return meal;   
    }
};

//Concrete Builder for a Burger Meal which has a burger, fries and a drink
class BurgerMeal: public MealBuilder {
public:
    BurgerMeal() {
        meal = new MealCombo("Burger");
    }

    void cookEntree() override {
        Burger *burger = new Burger;
        meal->setEntree(burger);
    }

    void cookSide() override {
        Fries *fries = new Fries;
        meal->setSide(fries);
    }

    void fillDrink() override {
        Drink *drink = new Drink;
        meal->setDrink(drink);
    }
};


//Concrete Builder for a Hotdog Meal which has a hotdog, salad and a drink
class HotdogMeal : public MealBuilder {
public:
	HotdogMeal() {
		meal = new MealCombo("Hotdog");
	}

	void cookEntree() {
		Hotdog *hotdog = new Hotdog;
		meal->setEntree(hotdog);
	}

	void cookSide() {
		Salad *caesar = new Salad;
		meal->setSide(caesar);
	}

	void fillDrink() {
		Drink *drink = new Drink;
		meal->setDrink(drink);
	}
};
#pragma endregion Builders

int main() {
	MealBuilder *cook;
    MealCombo *meal;
    int choice;

	// Prompt user for their meal choice
	std::cout << "Select a meal: \n";
	std::cout << "1: Hamburger Meal\n";
	std::cout << "2: Hotdog Meal\n";
	std::cout << "Selection: \n";
	std::cin >> choice;
    std::cout << std::endl;
    
	// Instantiate the apporpriate builder based on user input
	switch(choice) {
        case 1:
            cook = new BurgerMeal;
        break;

        case 2:
            cook = new HotdogMeal;
        break;

        default:
            std::cout << "Invalid Selection\n";
            cook = nullptr;
        break;
    }

	std::cout << "Making selected meal" << std::endl; 

	// Build the complex object
    cook->cookEntree();
    cook->cookSide();
    cook->fillDrink();

    meal = cook->getMeal();

    std::cout << meal->openMealBag() << std::endl;
    std::cout << meal->openMealBag() << std::endl;

    return 0;
}
