#include <cstdlib>
#include <iostream>

double power(double num, int pwr) {
    if(pwr == 0) {
        return 1;
    } if(pwr > 0) {
        return num * power(num, --pwr);
    } else {
        return 1 / power(num, std::abs(pwr));
    }
}

int main() {
    double num = 5;
    int pwr = -3;

    std::cout << num << " to the power of " << pwr << " is " << power(num, pwr) << std::endl;

    return 0;
}