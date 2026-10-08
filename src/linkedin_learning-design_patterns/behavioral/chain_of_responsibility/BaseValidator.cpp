#include "include/BaseValidator.h"

BaseValidator::~BaseValidator() {
    delete next;
}

StringValidator* BaseValidator::setNext(StringValidator* nextValidator) {
    next = nextValidator;
    return nextValidator;
}

std::string BaseValidator::validate(const std::string& testString) {
    if (this->next) {
        return this->next->validate(testString);
    }

    return "Success!";
}