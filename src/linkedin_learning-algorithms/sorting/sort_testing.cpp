//#define DEBUG_ITTERATIONS
#include <chrono>
#define DEBUG_STEPS

#include "bubble_sort.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"
#include "optimised_quick_sort.cpp"
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

    for(int i = 0; i < 5000; i++) {
        arr.push_back(1);
    }

    std::vector<int> arr2 = arr;
    std::vector<int> arr3 = arr;
    std::vector<int> arr4 = arr;
    
    
    /*std::cout << "Before sorting\n";
    printIntVector(arr);
    OpQuickSort::quickSort(&arr.front(), &arr.back());
    //QuickSort::quickSort(&arr.front(), &arr.back());
    //mergeSortOptimised::sort(arr);
    //mergeSort::sort(arr);
    //bubbleSort(arr);

    std::cout << "\nAfter sorting:\n";
    printIntVector(arr);*/
    
    
    // Bubble sort
    auto startTime = std::chrono::system_clock::now();
    std::cout << "Bubble sort\n";
    bubbleSort(arr);
    std::chrono::duration<double> duration = std::chrono::system_clock::now() - startTime;
    std::cout << "Time taken: " << duration.count() << "s\n";

    // Merge Sort
    startTime = std::chrono::system_clock::now();
    std::cout << "\nMerge sort:\n";
    mergeSortOptimised::sort(arr2);
    duration = std::chrono::system_clock::now() - startTime;
    std::cout << "Time taken: " << duration.count() << "s\n";
    
    // Quick Sort
    startTime = std::chrono::system_clock::now();
    std::cout << "\nQuick Sort\n";
    QuickSort::quickSort(&arr3.front(), &arr3.back());
    duration = std::chrono::system_clock::now() - startTime;
    std::cout << "Time taken: " << duration.count() << "s\n";

    // Quick Sort
    startTime = std::chrono::system_clock::now();
    std::cout << "\nOptimised Quick Sort\n";
    OpQuickSort::quickSort(&arr4.front(), &arr4.back());
    duration = std::chrono::system_clock::now() - startTime;
    std::cout << "Time taken: " << duration.count() << "s\n";

    std::cout << std::endl;
    return 0;
}