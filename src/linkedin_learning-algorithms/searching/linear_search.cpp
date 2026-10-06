#include <iostream>
#include <vector>
#define DEBUG

int findItem(const std::vector<int>& list, int item) {
    for(int i = 0; i < list.size(); i++) {
        if(list[i] == item) {
            #ifdef DEBUG
            std::cout << "\n[DEBUG] Steps taken " << i << "\n";
            #endif
            return i;
        }
    }

    #ifdef DEBUG
    std::cout << "\n[DEBUG] Steps taken " << list.size() << "\n";
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
    int idx = findItem(items, toFind);

    if(idx == -1) {
        std::cout << "not found.\n";
    } else {
        std::cout << "found at index " << idx << ".\n";
    }


    std::cout << std::endl;

    return 0;
}