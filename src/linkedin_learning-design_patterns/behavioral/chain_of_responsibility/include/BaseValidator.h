#pragma once

#include "IStringValidator.h"

class BaseValidator : public StringValidator {
protected:
    StringValidator* next = nullptr;

public:
    virtual ~BaseValidator();

    StringValidator* setNext(StringValidator* nextValidator) override;

    std::string validate(const std::string& testString) override;
};