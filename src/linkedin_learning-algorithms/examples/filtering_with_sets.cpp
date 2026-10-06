#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    // Filter out duplicates in a list
    std::string items[] = {
    "apple", "pear", "orange", "banana", "apple",
    "orange", "apple", "pear", "banana", "orange",
    "apple", "kiwi", "pear", "apple", "orange", "grape"
    };

    // Print out list
    std::cout << "Before filtering\n";
    std::cout << "Items [";
    for(const std::string& item : items) {
        std::cout << item;
        if(&item != &items[14]) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    // Create a set and add all elements in the list to the set 
    std::unordered_set<std::string> filter(items, items + 16);
    /*for(const std::string& item : items) {
        filter.insert(item);
    }*/

    // 
    std::cout << "After filtering\n";
    std::cout << "Items [";
    for(const std::string& item : filter) {
        std::cout << item << ", ";
    }
    std::cout << "]\n";

    // Count unique letters in a sentence
    std::string sentence = "\nThe quick brown fox jumps over the lazy dog";

    // Define set and add all characters from the sentence to the set
    std::unordered_set<char> uniqueLetters;
    for(const char letter : sentence) {
        if(std::isalnum(letter)) {
            uniqueLetters.insert(std::tolower(letter));
        }
    }

    std::cout << sentence << "\n";
    std::cout << "Unique letters: " << uniqueLetters.size() << "\n";

    std::cout << std::endl;
    return 0;
}