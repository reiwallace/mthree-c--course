#include <vector>
#if defined DEBUG_STEPS || defined DEBUG_ITTERATIONS
#include <iostream>
#endif

class mergeSort {
private:
    #ifdef DEBUG_ITTERATIONS
    inline static long int iterations = 0;
    #endif
    
        
    #ifdef DEBUG_STEPS
    inline static long int steps = 0;
    #endif

    static std::vector<int> split(const std::vector<int>& arr) {
        int size = arr.size();
        int lower = 0;
        int upper = 0;
        if(size == 1) {
            return arr;
        } else if(size % 2 == 1) {
            lower = size / 2;
            upper = lower + 1;
        } else {
            lower = upper = size / 2;
        }

        std::vector<int> part1;
        for(int i = 0; i < upper; i++) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            part1.push_back(arr[i]);
        }

        std::vector<int> part2;
        for(int i = upper; i < arr.size(); i++) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            part2.push_back(arr[i]);
        }

        part1 = split(part1);
        part2 = split(part2);

        return merge(part1, part2);
    }

    static std::vector<int> merge(const std::vector<int>& arr1, const std::vector<int>& arr2) {
        const int* pointer1 = &arr1.front();
        const int* pointer2 = &arr2.front();

        const int* back1 = &arr1.back() + 1;
        const int* back2 = &arr2.back() + 1;

        std::vector<int> merged;
        while(pointer1 != back1 && pointer2 != back2) {        
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            if(*pointer1 < *pointer2) {
                merged.push_back(*pointer1++);
            } else {
                merged.push_back(*pointer2++);
            }
        }

        while(pointer1 != back1) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            merged.push_back(*pointer1++);
        }

        while(pointer2 != back2) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            merged.push_back(*pointer2++);
        }

        #ifdef DEBUG_ITTERATIONS
        iterations++;
        #endif

        return merged;
    }

public:
    static void sort(std::vector<int>& arr) {
        #ifdef DEBUG_ITTERATIONS
        iterations = 0;
        #endif
        
        #ifdef DEBUG_STEPS
        steps = 0;
        #endif

        arr = split(arr);

        #ifdef DEBUG_STEPS
        std::cout << "[DEBUG] Total steps to sort: " << steps << "\n";
        #endif

        #ifdef DEBUG_ITTERATIONS
        std::cout << "[DEBUG] Total iterations to sort: " << iterations << "\n";
        #endif
    }
};
 
struct arrBounds {
    int* front;
    int* back;
};

class mergeSortOptimised {
private:
    #ifdef DEBUG_STEPS
    inline static long int steps = 0;
    #endif

    static arrBounds split(arrBounds bounds) {
        // Calculate size of array
        int size = (bounds.back + 1 - bounds.front);

        // If size is already 1 return bounds
        if(size <= 1) {
            return bounds;
        }

        arrBounds lower;
        arrBounds upper;

        lower.front = bounds.front;
        lower.back = bounds.front + size / 2 - 1;
        
        upper.front = lower.back + 1;
        upper.back = bounds.back;

        lower = split(lower);
        upper = split(upper);

        return merge(lower, upper);
    }

    static arrBounds merge(arrBounds first, arrBounds second) {
        int size = (first.back + 1 - first.front) + (second.back + 1 - second.front); 
        int temp[size];

        int* pointer1 = first.front;
        int* pointer2 = second.front;

        int* end1 = first.back + 1;
        int* end2 = second.back + 1;

        int idx = 0;

        while(pointer1 != end1 && pointer2 != end2) {        
            if(*pointer1 < *pointer2) {
                temp[idx] = *pointer1++;
            } else {
                temp[idx] = *pointer2++;
            }
            
            idx++;
            #ifdef DEBUG_STEPS
            steps++;
            #endif
        }

        while(pointer1 != end1) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            temp[idx] = *pointer1++;
            idx++;
        }

        while(pointer2 != end2) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            temp[idx] = *pointer2++;
            idx++;
        }

        for(int i = 0; i < size; i++) {
            #ifdef DEBUG_STEPS
            steps++;
            #endif
            *(first.front + i) = temp[i]; 
        }

        arrBounds newBounds;
        newBounds.front = first.front;
        newBounds.back = second.back;

        return newBounds;
    }

public:
    static void sort(std::vector<int>& arr) {        
        #ifdef DEBUG_STEPS
        steps = 0;
        #endif

        arrBounds bounds;
        bounds.front = &arr.front();
        bounds.back = &arr.back();

        split(bounds);

        #ifdef DEBUG_STEPS
        std::cout << "[DEBUG] Total steps to sort: " << steps << "\n";
        #endif
    }
};


