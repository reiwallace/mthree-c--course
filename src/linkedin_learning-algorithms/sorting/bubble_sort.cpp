#include <vector>
#if defined DEBUG_STEPS || defined DEBUG_ITTERATIONS
#include <iostream>
#endif

/**
    Swaps two elements in a vector of any type
    @param arr - Reference vector of items to swap
    @param idx1 - Index of first item to swap
    @param idx2 - Index of second item to swap
*/
template <typename T>
void swap(std::vector<T>& arr, const int idx1, const int idx2) {
    T temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp; 
}
/**
    Sorts an integer array into ascending order using bubble sort
    @param arr - Reference to vector to sort
*/
void bubbleSort(std::vector<int>& arr) {
    bool swapped = false;

    #ifdef DEBUG_ITTERATIONS
    int iterations = 0;
    #endif
    #ifdef DEBUG_STEPS
    int steps = 0;
    #endif


    do {
        swapped = false;
        for(int i = 1; i < arr.size(); i++) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            if(arr[i - 1] > arr[i]) {
                swap(arr, i-1, i);
                swapped = true;
            }
        }

        #ifdef DEBUG_ITTERATIONS
        iterations++;
        #endif

    } while(swapped);

    #ifdef DEBUG_STEPS
    std::cout << "[DEBUG] Total steps to sort: " << steps << "\n";
    #endif

    #ifdef DEBUG_ITTERATIONS
    std::cout << "[DEBUG] Total iterations to sort: " << iterations << "\n";
    #endif
}