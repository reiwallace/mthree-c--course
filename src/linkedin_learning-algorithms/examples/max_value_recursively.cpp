/**
    I don't know why the course asked us to do this. I'm just following the course.
*/

#include <iostream>
int max_val(int* front, int* back) {
    if(front - back == 0) {
        return *front;
    }

    int val2 = max_val(front + 1, back);
    if(*front > val2) {
        return *front;
    } else {
        return val2;
    }

}

int main() {
    int numbers[] = {
    42, 17, 89, 3, 56,
    71, 24, 95, 38, 62,
    11, 77, 29, 84, 5,
    68, 33, 91, 46, 13, 200
    };

    int max = max_val(numbers, numbers + 20);

    std::cout << "Max val: " << max << std::endl;
}