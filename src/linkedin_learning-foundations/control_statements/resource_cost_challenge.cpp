// C++ implementation​​​​​‌​​​​​‌​​‌​‌‌‌​​​‌​‌‌​‌‌​​ below
#include <iostream>
#include <cstdint>
#include <vector>

// Uncomment these macros to control whether you see
// the expected result and/or hints.
//#define showExpectedResult
//#define showHints

struct Resource{
    std::string name;
    double baseCost;
    char type; // 'B' for Basic, 'L' for Luxury, 'E' for Essential
};

enum class ResourceType {
    BASIC = 'B',
    LUXURY = 'L',
    ESSENTIAL = 'E'
};

double CalculateTotalCost(std::vector<Resource> resources){
    double result = 0.0;

    // Write your code here
    for(Resource &resource : resources) {
        // No change in price by default
        double tax = 1.0;

        // Update tax based on resource type
        switch(resource.type) {
            case static_cast<char>(ResourceType::BASIC):
                tax = 1.05;
            break;

            case static_cast<char>(ResourceType::LUXURY):
                tax = 1.15;
            break;
        }
        
        // Add multiplied cost to total
        result += resource.baseCost * tax;
    }
    
    return result;
}
