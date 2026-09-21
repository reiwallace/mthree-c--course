#include <set>
int main() {
    const std::set<int> nums = {10, 20, 30, 40};
    
    // Doesn't work
    //nums.emplace(100);

    // Doesn't work
    // nums.insert({100, 200, 300});

    // Can read
    bool has10 = nums.find(10) != nums.end();

    return 0;
}