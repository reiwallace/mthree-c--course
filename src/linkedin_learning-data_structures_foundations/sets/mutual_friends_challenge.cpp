#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using std::string;

std::vector<string> getMutualFriends(const std::set<string> &set1, const std::set<string> &set2) {
    std::vector<string> mutuals;

    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(mutuals));

    return mutuals;
}

int main() {
    const std::set<string> set1 = {"John", "Alice", "Bob"};
    const std::set<string> set2 = {"Alice", "Bob", "Charlie"};

    std::vector<string> mutuals = getMutualFriends(set1, set2);

    std::cout << "Mutuals: ";
    for(string person : mutuals) {
        std::cout << person << " ";
    }
    std::cout << std::endl;

    return 0;
}