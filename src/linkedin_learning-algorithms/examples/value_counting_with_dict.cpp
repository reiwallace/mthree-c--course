#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int main() {
    std::vector<std::string> items = {
    "apple", "pear", "orange", "banana", "apple",
    "orange", "apple", "pear", "banana", "orange",
    "apple", "kiwi", "pear", "apple", "orange", "grape"
    };

    std::unordered_map<std::string, int> itemCount;

    for(const std::string& item : items) {
        if(itemCount.count(item)) {
            itemCount[item]++;
        } else {
            itemCount[item] = 1;
        }
    }

    std::cout << "Item counts:\n";
    for(const std::pair<std::string, int>& keyPair : itemCount) {
        std::cout << keyPair.first << ": " << keyPair.second << "\n";
    }

    

    return 0;
}