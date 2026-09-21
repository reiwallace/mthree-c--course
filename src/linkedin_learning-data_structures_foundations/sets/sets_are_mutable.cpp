#include <iostream>
#include <set>
#include <string>

void printSet(const std::set<std::string> &set) {
    for(std::string item : set) {
        std::cout << item << " ";
    }
}

int main() {
    std::set<std::string> fruits = {"apple", "banana", "cherry"};

    printSet(fruits);
    std::cout << std::endl << std::endl;


    // Add a new item
    fruits.emplace("orange");
    printSet(fruits);
    std::cout << std::endl << std::endl;


    // Add the same item again
    fruits.emplace("orange");
    printSet(fruits);
    std::cout << std::endl << std::endl;

    // Add multiple items
    fruits.insert({"pineapple", "lime", "peach", "orange"});
    printSet(fruits);
    std::cout << std::endl << std::endl;

    // Remove item
    fruits.erase("orange");
    printSet(fruits);
    std::cout << std::endl << std::endl;

    return 0;
}