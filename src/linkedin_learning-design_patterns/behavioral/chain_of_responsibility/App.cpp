#include "include/BaseValidator.h"
#include "include/IStringValidator.h"
#include "include/NotEmptyValidator.h"
#include "include/RegexValidator.h"
#include <iostream>

int main() {
    StringValidator *emailValidator = new BaseValidator();

    emailValidator
        ->setNext(new NotEmptyValidator())
        ->setNext(new RegexValidator(
            "email address",
            "^\\w+([-.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$")
        );

    std::cout << "Checking Emails -----------------\n";
    std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
    std::cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
    std::cout << "Input: shuan@test.com\n" << emailValidator->validate("shuan@test.com");

    delete emailValidator;


    return 0;
}