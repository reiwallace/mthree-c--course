// C++ implementation​​​​​‌​​​​​‌​​‌​‌‌‌‌​‌​‌‌‌‌‌​‌​ below
#include <iostream>
#include <cstdint>
#include <vector>

// Uncomment these macros to control whether you see
// the expected result and/or hints.
//#define showExpectedResult
//#define showHints

// Function to calculate score based on milliseconds difference 
// You still need to make the bonus multiplier optional with a default value
double CalculateScore(int millisecondsDiff, double bonusMultiplier = 1.0) {
    double score = 0.0;

    // Write your code here
    if(millisecondsDiff <= 50) {
        score = 100.0;
    } else if(millisecondsDiff <= 100) {
        score = 75.0;
    } else if(millisecondsDiff <= 200) {
        score = 50.0;
    }

    return score * bonusMultiplier;
}

// Overloaded function to calculate score based on seconds difference 
// You still need to make the bonus multiplier optional with a default value
double CalculateScore(double secondsDiff, double bonusMultiplier = 1.5) {
    return CalculateScore(static_cast<int>(secondsDiff / 100), bonusMultiplier);
}

// Function to call both overloaded functions and return a vector of results
std::vector<double> GetScores(int millisecondsDiff, double secondsDiff, double bonusMultiplier1, double bonusMultiplier2) {
    std::vector<double> results;
    results.push_back(CalculateScore(millisecondsDiff));                   // Call the function using milliseconds with the default multiplier
    results.push_back(CalculateScore(millisecondsDiff, bonusMultiplier1));  // Call the function using milliseconds with a custom multiplier
    results.push_back(CalculateScore(secondsDiff));                        // Call the function using seconds with the default multiplier
    results.push_back(CalculateScore(secondsDiff, bonusMultiplier2));       // Call the function using seconds with a custom multiplier
    
    return results;
}
