// Complete Guide to C++ Programming Foundations
// Exercise 04_06
// The Vector Class, by Eduardo Corpeño 

#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> checkpoints = {"Start", "Forest", "Castle"};

    checkpoints.push_back("Cave");
    checkpoints.push_back("Finish");

    std::cout << "The game has " << checkpoints.size() << " locations." << std::endl;

    std::cout << "Element 3: " << checkpoints[2] << std::endl; 
    checkpoints[2] = "Dark Castle";
    std::cout << "Updated element 3: " << checkpoints.at(2) << std::endl; 

    std::cout << std::endl << std::endl;
    return 0;
}
