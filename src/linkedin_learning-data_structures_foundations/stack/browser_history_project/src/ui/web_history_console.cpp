#include "../../include/ui/web_history_ui.h"
#include <iostream>
#include <string>

void WebHistoryUI::viewOptions() const {
    std::cout << std::endl;
    std::cout << "--OPTIONS--" << std::endl;
    std::cout << "1. Visit Address" << std::endl;
    std::cout << "2. Previous Address" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

OPTION WebHistoryUI::getOption() const {
    // Retrieve and parse option
    int opt;
    std::cin >> opt;
    opt -= 1;

    // Switch option to return corresponding option
    switch(opt) {
        case 0:
            return OPTION::ENTER_ADDRESS;

        case 1:
            return OPTION::GO_BACK;

        case 2:
            return OPTION::EXIT;

        default:
            return OPTION::RETRY;
    }
}

std::string WebHistoryUI::getAddress() const {
    std::cout << std::endl;
    std::cout << "Please Enter a Website Address" << std::endl;

    // Save address input to a string
    std::string address;
    std::cin >> address;

    return address;
}

void WebHistoryUI::outputCurrentAddress(const std::string &address) const {
    std::cout << "Current Address: " << address << std::endl;
}

void WebHistoryUI::exit() const {
    std::cout << "Program Exiting..." << std::endl << std::endl;
}

void WebHistoryUI::start() const {
    std::cout << "+++ Web History Program +++" << std::endl;
}