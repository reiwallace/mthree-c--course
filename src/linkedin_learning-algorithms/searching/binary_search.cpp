#include <iostream>
#include <vector>
#define DEBUG

int binarySearch(std::vector<int> sortedList, int item) {
    int lower = 0;
    int upper = sortedList.size() - 1;
    int mid;
    #ifdef DEBUG
    int steps = 0;
    #endif


    while(lower < upper) {
        #ifdef DEBUG
        steps += 1;
        #endif

        mid = (upper - lower) / 2 + lower;
        if(sortedList[mid] == item) {
            #ifdef DEBUG
            std::cout << "\n[DEBUG] Steps taken " << steps << "\n";
            #endif
            return mid;
        } else if(sortedList[mid] > item) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }

    #ifdef DEBUG
    std::cout << "[DEBUG] Steps taken " << steps << "\n";
    #endif
    return -1;
}


int main() {
    //std::vector<int> items = {6 ,20 , 8, 19, 56, 23, 87, 41, 49, 53};
    std::vector<int> items;
    
    for(int i = 0; i < 100000; i++) {
        items.push_back(i);
    }

    int toFind = 76890;


    std::cout << "Item " << toFind << " ";
    int idx = binarySearch(items, toFind);

    if(idx == -1) {
        std::cout << "not found.\n";
    } else {
        std::cout << "found at index " << idx << ".\n";
    }


    std::cout << std::endl;

    return 0;
}