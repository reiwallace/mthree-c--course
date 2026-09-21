#include <iostream>

/**
    Swaps items in array from two indexes
    @param arr - Original array to be modified
    @param idx1 - Index of the first element to swap
    @param idx2 - Index of the second element to swap
*/
void swapItems(int* arr, int idx1, int idx2);

int main() {
    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    swapItems(nums, 2, 7);

    std::cout << "Numbers: [";
    for(int num : nums) {
        std::cout << num;
        if(num != nums[(sizeof(nums) / sizeof(*nums)) - 1]) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;


}

void swapItems(int* arr, int idx1, int idx2) {
    // Save val at index1 to a temp variable
    int temp = arr[idx1];

    // Swap the values at the two indexes
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

/*
void swapItems(int* arr, int idx1, int idx2) {
    // Save val at index1 to a temp variable
    int temp = *(arr + idx1);

    // Swap the values at the two indexes
    *(arr + idx1) = *(arr + idx2);
    *(arr + idx2) = temp;
}

void swapItems(int* arr, int idx1, int idx2) {
    // Save references to the target values
    int& val1 = *(arr + idx1);
    int& val2 = *(arr + idx2);

    // Save val1 to a temp variable
    int temp = val1;

    // Swap the two values
    val1 = val2;
    val2 = temp;
}

void swapItems(int* arr, int idx1, int idx2) {
    // Save references to the target values
    int& val1 = arr[idx1];
    int& val2 = arr[idx2];

    // Save val1 to a temp variable
    int temp = val1;

    // Swap the two values
    val1 = val2;
    val2 = temp;
}*/