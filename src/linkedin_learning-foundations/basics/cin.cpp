// Complete Guide to C++ Programming Foundations
// Challenge 01_09
// Terminal Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

using std::string;

int main(){
    string name;
    std::cout << "Hi There!" << std::flush;
    std::cin >> name;
    std::cout << "Nice to meet you " << name << "!" << std::endl;



    std::cout << std::endl << std::endl;
    return 0;
}