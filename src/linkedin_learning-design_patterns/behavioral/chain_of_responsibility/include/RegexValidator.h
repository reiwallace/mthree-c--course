#pragma once

#include "BaseValidator.h"

#include <string>

class RegexValidator : public BaseValidator {
private:
    const std::string PATTERN_NAME;
    const std::string REGEX_STRING;

public:
    RegexValidator(
        const std::string& patternName,
        const std::string& regexString
    );

    std::string validate(const std::string& testString) override;
};