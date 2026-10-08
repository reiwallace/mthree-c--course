#include "include/LengthValidator.h"

#include <iostream>

LengthValidator::LengthValidator(int minLength, int maxLength)
    : MIN_LENGTH(minLength), MAX_LENGTH(maxLength) {
}

std::string LengthValidator::validate(const std::string& testString) {
    std::cout << "Checking if too small...\n";

    if (testString.length() < MIN_LENGTH) {
        return "String too small.";
    }

    std::cout << "Checking if too large...\n";

    if (testString.length() > MAX_LENGTH) {
        return "String too large.";
    }

    return BaseValidator::validate(testString);
}