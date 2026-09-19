#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::string;

class Inventory {
private:
    std::vector<string> *items;
    int capacity;

public:
    Inventory(): capacity(10) {
        items = new std::vector<string>();
    }

    Inventory(int capacity_i): capacity(capacity_i) {
        items = new std::vector<string>();
    }

    ~Inventory() {
        delete items;
    }

    void addItem(const string& item) {
        if(items->size() < capacity) {
            items->push_back(item);
        } else {
            std::cout << "Inventory is full, cannot add " << item << std::endl;
        }
    }

    void removeItem(const string& item) {
        auto it = std::find(items->begin(), items->end(), item);
        if(it != items->end()) {
            items->erase(it);
        } else {
            std::cout << "Item " << item << " not found in inventory" << std::endl;
        }
    }

    string getItem(int index) const {
        if(index >= 0 && index < items->size()) {
            return items->at(index);
        } else {
            return "Index out of bounds.";
        }
    }

    int getItemCount() const {
        return items->size();
    }

    void displayInventory() {
        std::cout << "Inventory: [";
        for(const string& item : *items) {
            std::cout << item;
            if(&item != &items->back()) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    // Init new inv and allocate memory
    Inventory *inv = new Inventory(5);

    // Add items up to capacity
    inv->addItem("tool");
    inv->addItem("weapon");
    inv->addItem("potion");
    inv->addItem("shield");
    inv->addItem("bow");

    // Display added items
    inv->displayInventory();

    // Attempt to add an item over capacity
    inv->addItem("artifact");

    // Remove an item
    inv->removeItem("tool");

    // Display inventory size
    std::cout << "Inventory contains: " << inv->getItemCount() << " items." << std::endl;

    // Free up used memory
    delete inv;
    return 0;
}