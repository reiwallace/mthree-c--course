#include <iostream>
#include <queue>
#include <vector>

/**
    Gets a list of all binary numbers up to the N in base 10
    @param n - Base 10 number to count up to in binary
*/
std::vector<int> getFirstNBinary(int n) {
    std::vector<int> ans;
    
    // Initialise queue to track binary numbers and push 1 onto the queue
    std::queue<int> binaryQueue;
    binaryQueue.push(1);

    // Loop up to n times
    for(int i = 0; i < n; i++) {
        // Pop the next number at the front of the queue and push into the ans vector
        int binary = binaryQueue.front();
        binaryQueue.pop();
        ans.push_back(binary);

        // Add the next two binary numbers to the queue from the current number
        binaryQueue.push(binary * 10);
        binaryQueue.push(binary * 10 + 1);
    }

    return ans;
}


int main() {

    std::vector<int> nums = getFirstNBinary(6);

    for(int num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}