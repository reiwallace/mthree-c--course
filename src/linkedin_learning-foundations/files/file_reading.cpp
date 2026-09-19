#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream inFile;
    std::string str;
    int number;
    char letter;

    inFile.open("example.txt");
    if(inFile.fail()) {
        std::cout << "File not found!!" << std::endl;
        return 1;
    } 

    while(!inFile.eof()) {
        // Read string
        getline(inFile, str);
        std::cout << "Input string: " << str << std::endl;

        // Read int
        getline(inFile, str);
        number = std::stoi(str);
        std::cout << "Input int: " << number << std::endl;

        // Read char
        getline(inFile, str);
        letter = str[0];
        std::cout << "Input char: " << letter << std::endl;
    }
    inFile.close();

    std::cout << std::endl;
    return 0;
}