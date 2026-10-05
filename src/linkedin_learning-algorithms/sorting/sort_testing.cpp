//#define DEBUG_ITTERATIONS
#define DEBUG_STEPS

#include "bubble_sort.cpp"
#include "merge_sort.cpp"
#include <iostream>

/**
    Prints the contents of an int vector
    @param arr - Reference to a vector to print
*/
void printIntVector(const std::vector<int>& arr) {
    std::cout << "Arr: [";
    for(const int& num : arr) {
        std::cout << num;
        if(&num != &arr.back()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

int main() {
    std::srand(42);

    std::vector<int> arr;

    for(int i = 0; i < 10000; i++) {
        arr.push_back(std::rand() % 10000);
    }

    std::vector<int> arr2 = arr;
    
    /*
    std::cout << "Before sorting\n";
    printIntVector(arr);
    mergeSortOptimised::sort(arr);
    //mergeSort::sort(arr);
    //bubbleSort(arr);

    std::cout << "\nAfter sorting:\n";
    printIntVector(arr);
    */
    

    
    std::cout << "Bubble sort\n";
    bubbleSort(arr);

    std::cout << "\nMerge sort:\n";
    mergeSortOptimised::sort(arr2);
    

    std::cout << std::endl;
    return 0;
}