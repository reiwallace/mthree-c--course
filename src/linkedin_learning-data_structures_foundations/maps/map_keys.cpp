#include <iostream>
#include <string>
#include <unordered_map>

using stringMap = std::unordered_map<std::string, std::string>;

int main() {
    stringMap bookAuthors = {
        {"1984", "George Orwell"},
        {"Pride and Prejudice", "Jane Austen"},
        {"Moby Dick", "Herman Melville"}
    };

    // Print out all keys
    for(stringMap::iterator it = bookAuthors.begin(); it != bookAuthors.end(); it++) {
        std::cout << "Book name: " << it->first << std::endl;
    }
    std::cout << std::endl;

    // Print out all values
    for(stringMap::iterator it = bookAuthors.begin(); it != bookAuthors.end(); it++) {
        std::cout << "Author name: " << it->second << std::endl;
    }
    std::cout << std::endl;

    // Print out keys and values
    for(stringMap::iterator it = bookAuthors.begin(); it != bookAuthors.end(); it++) {
        std::cout << it->first << " by " << it->second << std::endl;
    }
    std::cout << std::endl;

    return 0;
}