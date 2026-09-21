#include <algorithm>
#include <iostream>
#include <vector>

/**
    Performs a linear search on a vector
    @returns if item is found in the vector
*/
bool hasItem(const std::vector<int> &nums, int target) {
    for(int num : nums) {
        if(num == target) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<int> nums = {8, 5, 0, 3, 9, 7};
    int target = 5;

    std::cout << "Nums has " << target << "?" << std::endl;
    std::cout << (hasItem(nums, target) ? "true" : "false") << std::endl;

    bool stdHas = std::find(nums.begin(), nums.end(), target) != nums.end();

    return 0;
}