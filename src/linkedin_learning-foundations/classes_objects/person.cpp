#include "person.h"

/**
    Reduces energy by an amount stopping at 0
    @param amount - Amount to reduce energy by
*/
void Person::reduceEnergy(float amount) {
    float newEnergy = energy - amount;
    if(newEnergy >= 0) {
        energy = newEnergy;
    } else {
        energy = 0;
        // NYI
    }
}

/**
    Reduces happiness by an amount stopping at 0
    @param amount - Amount to reduce happiness by
*/
void Person::reduceHappiness(float amount) {
    float newHappiness = happiness - amount;
    if(newHappiness >= 0) {
        happiness = newHappiness;
    } else {
        happiness = 0;
        // NYI
    }
}

/**
    Reduces health by an amount stopping at 0
    @param amount - Amount to reduce health by
*/
void Person::reduceHealth(float amount) {
    float newHealth = health - amount;
    if(newHealth >= 0) {
        health = newHealth;
    } else {
        health = 0;
        // NYI
    }
}

/**
    Adds to energy up to a maximum of the energy cap
    @param amount - Amount to increase energy by
*/
void Person::increaseEnergy(float amount) {
    float newEnergy = energy + amount;

    if(newEnergy <= MAX_ENERGY) {
        energy = newEnergy;
    } else {
        energy = MAX_ENERGY;
        // NYI
    }
}

/**
    Adds to happiness up to a maximum of the happiness cap
    @param amount - Amount to increase happiness by
*/
void Person::increaseHappiness(float amount) {
    float newHappiness = happiness + amount;
    
    if(newHappiness <= MAX_HAPPINESS) {
        happiness = newHappiness;
    } else {
        happiness = MAX_ENERGY;
        // NYI
    }
}

/**
    Adds to health up to a maximum of the health cap
    @param amount - Amount to increase health by
*/
void Person::increaseHealth(float amount) {
    float newHealth = health + amount;
    
    if(newHealth <= MAX_HEALTH) {
        health = newHealth;
    } else {
        health = MAX_ENERGY;
        // NYI
    }
}

/**
    Create a person capable of eating, playing and sleeping
    @param name - Person's full name
    @param energy - Person's current energy
    @param happiness - Person's current happiness
    @param health - Person's current health
*/
Person::Person(const std::string& name, float energy, float happiness, float health) {
    this->name = name;
    this->energy = energy;
    this->happiness = happiness;
    this->health = health;
}

/**
    Increases the Person's current energy based on the number of calories intaken
    @param calories - Number of calories to consume
*/
void Person::eat(float calories) {
    increaseEnergy(calories * 7.0f / 200.0f);
}

/**
    Increases the Person's happiness based on the time spent playing while decreasing energy
    @param minutes - Number of minutes to play for
*/
void Person::play(float minutes) {
    increaseHappiness(minutes / 2);
    reduceEnergy(minutes / 3);
}

/**
    Increases the Person's health and energy based on the hours of sleep
    @param hours - Number of hours to sleep for
*/
void Person::sleep(float hours) {
    increaseEnergy(hours * 3.75);
    increaseHealth(hours * 2.5);
}

// Gettters
std::string Person::getName() const {
    return name;
}
float Person::getEnergy() const {
    return energy;
}
float Person::getHappiness() const {
    return happiness;
}
float Person::getHealth() const {
    return health;
}