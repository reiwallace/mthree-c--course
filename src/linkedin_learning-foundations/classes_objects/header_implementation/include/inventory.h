#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
class Inventory {
private:
    std::vector<std::string> *items;
    int capacity;

public:
    /**
        Create an inventory with an input capacity
        @param capacity_i - Max items in inventory
    */
    Inventory(int capacity_i);

    /**
        Create an inventory with an max items of 10
    */
    Inventory();
    ~Inventory();

    /** 
        Add string name of item to inventory
        Gives a warning message if inventory is full
        @param item - Item name to add to inventory
    */
    void addItem(const std::string& item);

    /** 
        Removes string name of item to inventory
        Gives a warning message if item not in inventory
        @param item - Item name to remove from inventory
    */
    void removeItem(const std::string& item);

    /**
        Gets an item from an input index in the inventory
        @param index - Internal array index to retrieve
        @returns {std::string} Item if found
    */
    std::string getItem(int index) const;

    /**
        Returns the number of items currently in the inventory
        @returns number of items
    */
    int getItemCount() const;

    /**
        Prints out the current inventory contents to the console
    */
    void displayInventory();
};

#endif