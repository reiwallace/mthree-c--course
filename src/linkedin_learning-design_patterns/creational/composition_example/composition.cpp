#include <iostream>
#include <string>
class Entree {
protected:
    std::string entree;

public:
    const std::string &getEntree() {
        return entree;
    }
};

class Side {
protected:
    std::string side;

public:
    const std::string &getSide() {
        return side;
    }
};

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

class ComboMeal {
private:
    Entree *entree = nullptr;
    Side *side = nullptr;
    Drink *drink = nullptr;
    std::string bag;

public:
    ComboMeal(const std::string &type): bag("\n" + type + " meal combo: ") {}

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
        //return bag + entree->getEntree() + side->getSide() + drink->getDrink();
    }
};