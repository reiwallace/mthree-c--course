#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::string> statesToCapitals = {
        {"Alabama", "Mongomery"},
        {"Alaska", "Juneau"},
        {"Arizona", "Little Rock"}
    };
    std::string targetState = "Alaska";

    std::cout << "Capital of " << targetState << ": " << statesToCapitals.at(targetState) << std::endl; 

    // Using emplace as a getOrDefault
    std::cout << "Capital of Texas: " << statesToCapitals.emplace("Texas", "N/A").first->second << std::endl;

    return 0;
}