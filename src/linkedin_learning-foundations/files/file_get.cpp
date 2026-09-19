#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ifstream inFile;
    std::vector<std::string> strs;
    int number;
    char letter;

    inFile.open("example.txt");
    if(inFile.fail()) {
        std::cout << "File not found!!" << std::endl;
        return 1;
    } 

    while(!inFile.eof()) {
        char buffer[50];
        inFile.get(buffer, ':');
        std::string fresh(buffer);
        strs.push_back(fresh);
    }
    inFile.close();

    for(std::string str : strs) {
        std::cout << str << " ";
    }

    std::cout << std::endl;
    return 0;
}