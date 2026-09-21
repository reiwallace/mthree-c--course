#include <iostream>
#include <vector>

/**
    Gets the second smallest value from a list of numbers
    @param nums - List of numbers to check
    @returns The second smallest value found in the list
*/
int getSecondSmallest(const std::vector<int>& nums) {
    // Return 0 if nums is not a valid size
    if(nums.size() < 2) {
        return 0;
    }

    // Get the smallest and second smallest of the first two values
    int smallest;
    int secondSmallest;
    if(nums[0] > nums[1]) {
        smallest = nums[1];
        secondSmallest = nums[0];
    } else {
        smallest = nums[0];
        secondSmallest = nums[1];
    }

    // Loop through every element in nums after the second element
    for(int i = 2; i < nums.size(); i++) {
        int num = nums[i];

        // Compare to current smallest and second smallest values
        if(num < smallest) {
            secondSmallest = smallest;
            smallest = num;
        } else if(num < secondSmallest) {
            secondSmallest = num;
        }
    }

    return secondSmallest;
}

int main() {
    std::vector<int> nums = {3, 1 ,5 ,7 ,8 ,11 ,67, 34, 2};
    int secondSmallest = getSecondSmallest(nums);

    std::cout << "Second smallest: " << secondSmallest << std::endl;


    return 0;
}