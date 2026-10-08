#include "include/HistoryValidator.h"

#include <algorithm>
#include <iostream>

HistoryValidator::HistoryValidator(std::vector<std::string> historyItems)
    : HISTORY_ITEMS(historyItems) {
}

bool HistoryValidator::inHistory(const std::string& item) {
    return std::find(
        HISTORY_ITEMS.begin(),
        HISTORY_ITEMS.end(),
        item
    ) != HISTORY_ITEMS.end();
}

std::string HistoryValidator::validate(const std::string& testString) {
    std::cout << "Checking if string has been used before...\n";

    if (inHistory(testString)) {
        return "Please enter a value here that you haven't entered before";
    }

    return BaseValidator::validate(testString);
}