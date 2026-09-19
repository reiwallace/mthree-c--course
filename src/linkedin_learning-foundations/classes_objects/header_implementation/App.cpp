#include "include/inventory.h"
#include <iostream>

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