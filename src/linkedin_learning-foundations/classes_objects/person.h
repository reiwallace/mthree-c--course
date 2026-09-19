#ifndef PERSON_H
#define PERSON_H

#include <string>
class Person {
private:
    const float MAX_ENERGY = 100.0f;
    const float MAX_HAPPINESS = 100.0f;
    const float MAX_HEALTH = 100.0f;

    std::string name;
    float energy;
    float happiness;
    float health;

    /**
        Reduces energy by an amount stopping at 0
        @param amount - Amount to reduce energy by
    */
    void reduceEnergy(float amount);

    /**
        Reduces happiness by an amount stopping at 0
        @param amount - Amount to reduce happiness by
    */
    void reduceHappiness(float amount);

    /**
        Reduces health by an amount stopping at 0
        @param amount - Amount to reduce health by
    */
    void reduceHealth(float amount);


    /**
        Adds to energy up to a maximum of the energy cap
        @param amount - Amount to increase energy by
    */
    void increaseEnergy(float amount);

    /**
        Adds to happiness up to a maximum of the happiness cap
        @param amount - Amount to increase happiness by
    */
    void increaseHappiness(float amount);

    /**
        Adds to health up to a maximum of the health cap
        @param amount - Amount to increase health by
    */
    void increaseHealth(float amount);

public:
    /**
        Create a person capable of eating, playing and sleeping
        @param name - Person's full name
        @param energy - Person's current energy
        @param happiness - Person's current happiness
        @param health - Person's current health
    */
    Person(const std::string&, float, float, float);

    /**
        Increases the Person's current energy based on the number of calories intaken
        @param calories - Number of calories to consume
    */
    void eat(float);

    /**
        Increases the Person's happiness based on the time spent playing while decreasing energy
        @param minutes - Number of minutes to play for
    */
    void play(float);

    /**
        Increases the Person's health and energy based on the hours of sleep
        @param hours - Number of hours to sleep for
    */
    void sleep(float);

    // Gettters
    std::string getName() const;
    float getEnergy() const;
    float getHappiness() const;
    float getHealth() const;
};

#endif