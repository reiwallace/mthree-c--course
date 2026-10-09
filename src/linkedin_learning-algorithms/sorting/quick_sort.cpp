#if defined DEBUG_STEPS || defined DEBUG_ITTERATIONS
#include <iostream>
#endif

class QuickSort {
private:
    #ifdef DEBUG_STEPS
    inline static long int steps;
    #endif
    /**
        Helper function to swap array elements using pointers
        @param element1 - Pointer to the first element
        @param element2 - Pointer to the second element to swap
    */
    static void swapElements(int* element1, int* element2) {
        int temp = *element1;
        *element1 = *element2;
        *element2 = temp;
    }

    /**
        Paritions and sorts an integer array using quick sort
        @param front - Pointer to the value at the front of the array
        @param back - Pointer to the value at the back of the array
    */
    static void partition(int* front, int* back) {
        // Don't sort partitions with less than or 1 element
        if(front > back || front == back) return;

        // Initialise i and j pointers to first element and out of bounds
        int* j = front;
        int* i = front - 1;
        
        // Pivot around the final element
        while(j < back) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            // value at j less than the pivot
            if(*j < *back) {
                // Increment i, swap elements then increment j
                swapElements(++i, j++);
            } else {
                j++;
            }
        }

        // Increment i then swap i with the pivot
        swapElements(++i, back);

        // Sort the resulting two partitions
        partition(front, i - 1);
        partition(i + 1, back);
    }

public:
    /**
        Sorts an array using the quick sort algorithm 
        @param front - Pointer to the value at the front of the array
        @param back - Pointer to the value at the back of the array
    */
    static void quickSort(int* front, int* back) {
        #ifdef DEBUG_STEPS
        steps = 0;
        #endif

        partition(front, back);

        #ifdef DEBUG_STEPS
        std::cout << "[DEBUG] Total steps to sort: " << steps << "\n";
        #endif
    }
};
