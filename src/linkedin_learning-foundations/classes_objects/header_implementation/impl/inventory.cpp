#include "../include/inventory.h"
#include <iostream>
#include <algorithm>

using std::string;

Inventory::Inventory(): capacity(10) {
    items = new std::vector<string>();
}

Inventory::Inventory(int capacity_i): capacity(capacity_i) {
    items = new std::vector<string>();
}

Inventory::~Inventory() {
    delete items;
}

void Inventory::addItem(const string& item) {
    if(items->size() < capacity) {
        items->push_back(item);
    } else {
        std::cout << "Inventory is full, cannot add " << item << std::endl;
    }
}

void Inventory::removeItem(const string& item) {
    auto it = std::find(items->begin(), items->end(), item);
    if(it != items->end()) {
        items->erase(it);
    } else {
        std::cout << "Item " << item << " not found in inventory" << std::endl;
    }
}

string Inventory::getItem(int index) const {
    if(index >= 0 && index < items->size()) {
        return items->at(index);
    } else {
        return "Index out of bounds.";
    }
}

int Inventory::getItemCount() const {
    return items->size();
}

void Inventory::displayInventory() {
    std::cout << "Inventory: [";
    for(const string& item : *items) {
        std::cout << item;
        if(&item != &items->back()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

