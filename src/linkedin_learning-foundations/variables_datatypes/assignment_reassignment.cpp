// Complete Guide to C++ Programming Foundations
// Exercise 02_05
// Using Variables, by Eduardo Corpeño 

#include <iostream>

int a, b = 5;

int main(){
    bool my_flag;
    my_flag = false;
    a = 7;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "flag = " << my_flag << std::endl;

    my_flag = true;
    std::cout << "flag = " << my_flag << std::endl;
    std::cout << "b + a = " << b + a << std::endl;
    std::cout << "b - a = " << b - a << std::endl;
    
    unsigned int positive;
    positive = b - a;
    std::cout << "positive = " << positive << std::endl;
    
    std::cout << std::endl << std::endl;
    return 0;
}
