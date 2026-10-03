#include <cstdint>
#include <iostream>

uint64_t factorial(uint64_t num) {
    if(num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}

int main() {
    uint64_t num = 5;

    std::cout << "The factorial of " << num << " is " << factorial(num) << std::endl;

    return 0;
}