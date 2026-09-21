#ifndef PRINT_SET
#define PRINT_SET
#include <iostream>
#include <set>

/**
    Prints out the contents of a set
    @param set - Set to print
*/
template <typename T>
void printSet(const std::set<T> &set) {
    for(auto item : set) {
        std::cout << item << " ";
    }
}

#endif 
