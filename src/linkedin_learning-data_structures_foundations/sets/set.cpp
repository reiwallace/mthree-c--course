#include <iostream>
#include <set>
#include <string>

int main() {
    std::set<std::string> primary_colours= {"red", "blue", "yellow"};
    std::string colour = "pink";

    if(primary_colours.find(colour) != primary_colours.end()) {
        std::cout << colour << " is a primary colour!" << std::endl;
    } else {
        std::cout << colour << " is not a primary colour!" << std::endl;
    }


    return 0;
}