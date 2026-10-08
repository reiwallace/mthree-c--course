#pragma once

#include "BaseValidator.h"

#include <string>
#include <vector>

class HistoryValidator : public BaseValidator {
private:
    const std::vector<std::string> HISTORY_ITEMS;

    bool inHistory(const std::string& item);

public:
    HistoryValidator(std::vector<std::string> historyItems);

    std::string validate(const std::string& testString) override;
};