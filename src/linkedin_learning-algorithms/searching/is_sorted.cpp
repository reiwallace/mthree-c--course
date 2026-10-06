#include <iostream>
#include <vector>
bool isSorted(std::vector<int> list) {

    for(auto it = list.begin() + 1; it != list.end(); it++) {
        if(*it < *(it - 1)) {
            return false;
        }
    }

    return true;
}

int main() {
    //std::vector<int> items = {6 ,20 , 8, 19, 56, 23, 87, 41, 49, 53};
    std::vector<int> items;
    
    for(int i = 0; i < 100; i++) {
        items.push_back(i);
    }

    std::cout << "List is sorted? " << (isSorted(items) ? "Yes" : "No") << "\n";

    std::cout << std::endl;

    return 0;
}