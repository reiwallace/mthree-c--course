#include <iostream>
#include <string>

// Abstract Animal class
class Animal {
protected:
	std::string hairColor;
	int hairLength, tail, weight, height, age;
	int intelligence, stubbornness, agressiveness;

public:
    virtual Animal *clone() = 0;

	void setHairLength(int length) {
		hairLength = length;
	}

	void setHairColor(const std::string &color) {
		hairColor = color;
	}

	void setTail(int length) {
		tail = length;
	}

	void setWeight(int kg) {
		weight = kg;
	}

	void setHeight(int m) {
		height = m;
	}

	void setAge(int age) {
		age = age;
	}
};

// Derived Sheep class
class Sheep : public Animal {
public:
	Sheep() {
		hairLength = 5;
		stubbornness = 3;
		agressiveness = 2;
		intelligence = 7;
	}

    Sheep* clone() {
        return new Sheep(*this);
    }

    void shearing() {
        hairLength -= 2;
    }
};

// Derived Cow class
class Cow : public Animal {
public:
	Cow() {
		stubbornness = 6;
		agressiveness = 5;
		intelligence = 8;
	}

    Cow *clone() {
        return new Cow(*this);
    }
};

int main()
{
	//create initial instance of a Sheep
    Sheep *sheep0 = new Sheep();
    sheep0->setHairColor("white");
    sheep0->setTail(5);
    sheep0->setWeight(90);
    sheep0->setHeight(1);
    sheep0->setAge(5);

	//create initial instance of a Cow
    Cow *cow0 = new Cow();
    cow0->setHairColor("brown");
    cow0->setTail(20);
    cow0->setWeight(790);
    cow0->setHeight(2);
    cow0->setAge(8);

	//use cloning to populate the farm
    Animal *farm[3];
    farm[0] = sheep0->clone();
    farm[1] = cow0->clone();

	//change a cow property
    farm[1]->setWeight(1000);

	//shear a Sheep and clone it
    sheep0->shearing();
    farm[2] = sheep0->clone();



    return 0;
}
