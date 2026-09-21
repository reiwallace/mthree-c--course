#include <algorithm>
#include <functional>
#include <iostream>

int main() {
    int nums[] = {1, 7, 3};
    std::sort(nums, nums + sizeof(nums) / sizeof(*nums), std::greater<int>());

    for(int num : nums) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
    return 0;
}