// Complete Guide to C++ Programming Foundations
// Challenge 02_13
// Data Types, by Eduardo Corpeño 

#include <iostream>
#include <cstdint>

int add_int(float a, double b, long double c){
    int result = 0;
    
    result += static_cast<int>(a);
    result += static_cast<int>(b);
    result += static_cast<int>(c);

    return result;
}

int main(){
    float a = -2.0f;
    double b = -3.9;
    long double c = 4.6;

    int learnerResult = add_int(a, b, c);
    
    std::cout << "Your code returned: " << learnerResult << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
