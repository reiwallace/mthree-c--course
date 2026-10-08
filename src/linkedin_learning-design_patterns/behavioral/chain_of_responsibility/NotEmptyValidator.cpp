#include "include/NotEmptyValidator.h"
#include <iostream>

std::string NotEmptyValidator::validate(const std::string& testString) {
    std::cout << "Checking if empty...\n";

    if (testString.empty()) {
        return "Input is empty!";
    }

    return BaseValidator::validate(testString);
}