#include <iostream>
#include <tuple>
#include <vector>

// Alias for a vector of tuples 
using tupleList = std::vector<std::tuple<int, int>>;

/**
    Gets the square values for every number in an input list
    @param nums - Input list of numbers to get the squares of
    @returns A vector list of tuples containing the original number and its square value
*/
tupleList* getSquares(const std::vector<int>& nums) {
    // Assign memory to a new list
    tupleList* list = new tupleList;

    // Loop through every number making a tuple for each number and its square
    for(int num : nums) {
        list->emplace_back(num, num * num);
    }

    return list;
}

int main() {
    std::vector<int> nums = {5, 20, 2, 4, 7, 111, 93};

    auto squares = getSquares(nums);

    // Print each number and its square
    for(const auto& square : *squares) {
        std::cout << "Num: " << std::get<0>(square);
        std::cout << ", Square: " << std::get<1>(square);
        std::cout << std::endl;
    }

    // Free allocated memory
    delete squares;
    return 0;
}