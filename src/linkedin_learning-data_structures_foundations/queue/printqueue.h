#ifndef PRINT_QUEUE
#define PRINT_QUEUE

#include <iostream>
#include <queue>

/**
    Prints out all elements in a queue
    @param q - Queue to print out
*/
template<typename T>
void printQueue(std::queue<T> q) {
    for(auto element : q) {
        std::cout << element << " ";
    }
}

#endif