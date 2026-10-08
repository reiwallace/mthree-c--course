#pragma once

#include "BaseValidator.h"

class LengthValidator : public BaseValidator {
private:
    const int MIN_LENGTH;
    const int MAX_LENGTH;

public:
    LengthValidator(int minLength, int maxLength);

    std::string validate(const std::string& testString) override;
};