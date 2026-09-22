#include <deque>
#include <string>
#include "../../include/dao/web_history_data.h"

WebHistoryData::WebHistoryData(std::deque<std::string> stack):
historyStack(stack) {}

WebHistoryData::WebHistoryData() {
    historyStack = std::deque<std::string>();
}

void WebHistoryData::visitWebsite(const std::string& website) {
    historyStack.push_back(website);
}

std::string WebHistoryData::goBack() {
    // Retrieve the website, pop the value then return the website
    if(hasHistory()) {
        std::string website = historyStack.back();
        historyStack.pop_back();
        return website;
    } else {
        return "";
    }
}

std::string WebHistoryData::getCurrentWebsite() const {
    if(hasHistory()) {
        return historyStack.back();
    } else { 
        return "";
    }
}

bool WebHistoryData::hasHistory() const {
    return !historyStack.empty();
}