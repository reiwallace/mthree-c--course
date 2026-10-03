
#include <iostream>
void countdown(int num) {
    if(num == 0) {
        std::cout << "done!" << std::endl;
    } else {
        std::cout << num << "...\n";
        countdown(--num);
    }   
}

int main() {

    countdown(10);

    return 0;
}