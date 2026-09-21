#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
#include "include/printset.h"

int main() {
    std::set<int> setA = {10, 20, 30 ,40, 50};
    std::set<int> setB = {30, 40, 50, 60, 70};

    // Combine set A and set B
    setA.insert(setB.begin(), setB.end());
    printSet(setA);
    std::cout << std::endl << std::endl;

    // Intersection of set A and B
    setA = {10, 20, 30 ,40, 50};
    std::vector<int> intersection;
    std::set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), std::back_inserter(intersection));
    
    for(int num : intersection) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    // Difference of set A and B
    std::vector<int> difference;
    std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), std::back_inserter(difference));
    
    for(int num : difference) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    // Symmetric Difference of set A and B
    std::vector<int> symDifference;
    std::set_symmetric_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), std::back_inserter(symDifference));
    
    for(int num : symDifference) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;


    return 0;
}