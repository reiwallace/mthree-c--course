// Complete Guide to C++ Programming Foundations
// Exercise 04_10
// The String Class, by Eduardo Corpeño 

#include <iostream>
#include <string>

using std::string;

int main(){
    string racer1 = "Speedy";
    string racer2 = "";
    string raceResult = "";

    racer2 = "Lightning";

    std::cout << "Racer 1: " << racer1 << std::endl;
    std::cout << "Racer 2: " << racer2 << std::endl;

    raceResult = "And the winner is " + racer1;

    std::cout << raceResult << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
