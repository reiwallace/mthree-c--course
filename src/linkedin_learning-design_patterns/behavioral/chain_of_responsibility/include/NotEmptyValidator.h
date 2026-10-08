#pragma once

#include "BaseValidator.h"

class NotEmptyValidator : public BaseValidator {
public:
    std::string validate(const std::string& testString) override;
};