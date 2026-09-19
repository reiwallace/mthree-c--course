// C++ implementation​​​​​‌​​​​​‌​​‌‌‌​​‌​​​​‌​‌‌‌‌​ below
#include <iostream>
#include <cstdint>
#include <vector>
#include <deque>
#include <string>
#include <utility>

// Uncomment these macros to control whether you see
// the expected result and/or hints.
//#define showExpectedResult
//#define showHints

template <typename T> using deque = std::deque<T>;
template <typename T> using vector = std::vector<T>;
template <typename T1, typename T2> using pair = std::pair<T1, T2>;
using string = std::string;

// Enum class for operations
enum class Operation{
    ADD_FRONT,
    ADD_BACK,
    REMOVE_FRONT,
    REMOVE_BACK
};

deque<pair<string, int>> ManagePetSchedule(const deque<pair<string, int>>& initialActivities, const vector<pair<Operation, pair<string, int>>>& operations){
    deque<pair<string, int>> schedule = initialActivities;

    // Write your code here.
    for(const pair<Operation, pair<string, int>> &operation : operations) {
        switch(operation.first) {
            case Operation::ADD_FRONT:
                schedule.push_front(operation.second);
            break;

            case Operation::ADD_BACK:
                schedule.push_back(operation.second);
            break;

            case Operation::REMOVE_FRONT:
                if(!schedule.empty()) {
                    schedule.pop_front();
                }
            break;

            case Operation::REMOVE_BACK:
                if(!schedule.empty()) {
                    schedule.pop_back();
                }
            break;
        }
    }
    

    return schedule;
}
