#include "include/RegexValidator.h"
#include <iostream>
#include <regex>

RegexValidator::RegexValidator(
    const std::string& patternName,
    const std::string& regexString
)
    : PATTERN_NAME(patternName),
      REGEX_STRING(regexString) {
}

std::string RegexValidator::validate(const std::string& testString) {
    std::cout << "Checking regex match...\n";

    if (!std::regex_match(testString, std::regex(REGEX_STRING))) {
        return "The value entered does not match the proper format for a "
             + PATTERN_NAME;
    }

    return BaseValidator::validate(testString);
}