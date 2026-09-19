#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>

int main() {
    std::ofstream outFile;
    float a = 1.2f;
    float b = 3.0f;


    outFile.open("example.txt", std::ios_base::app);
    if(outFile.fail()) {
        std::cout << "File not found!!" << std::endl;
        return 1;
    } 

    outFile << "a = " << a << std::endl;
    outFile << "b = " << b << std::endl;
    outFile << "a + b = " << a + b << std::endl;
    outFile << "a * b = " << a * b << std::endl;
    outFile.close();

    std::cout << "Successfully written to file!" << std::endl;

    std::cout << std::endl;
    return 0;
}