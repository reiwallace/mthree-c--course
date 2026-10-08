#pragma once

#include <string>

class StringValidator {
public:
    virtual ~StringValidator() = default;

    virtual StringValidator* setNext(StringValidator* next) = 0;
    virtual std::string validate(const std::string& testString) = 0;
};