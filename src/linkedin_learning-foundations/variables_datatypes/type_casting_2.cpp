// Complete Guide to C++ Programming Foundations
// Exercise 02_11
// Type Casting Examples, by Eduardo Corpeño 

#include <cmath>
#include <iostream>
#include <cstdint>

int main(){
    int fahrenheit = 100;
    int celsius;

    celsius = (fahrenheit - 32) * (static_cast<float>(5) / 9.0);

    std::cout << std::endl;
    std::cout << "Fahrenheit: " << fahrenheit << std::endl;
    std::cout << "Celsius   : " << celsius << std::endl;

    float weight = 10.99;
    
    std::cout << std::endl;
    std::cout << "Float          : " << weight << std::endl;
    std::cout << "Integer part   : " << static_cast<int32_t>(weight) << std::endl;
    std::cout << "Fractional part: " << static_cast<int>((weight - static_cast<int32_t>(weight))* 10000) << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}
