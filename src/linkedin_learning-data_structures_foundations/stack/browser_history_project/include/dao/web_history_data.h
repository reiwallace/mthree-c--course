#ifndef WEB_HISTORY_DATA
#define WEB_HISTORY_DATA

#include <deque>
#include <string>

class WebHistoryData {
private:
    // Using a double ended queue to emulate a stack
    std::deque<std::string> historyStack;

public:
    WebHistoryData(std::deque<std::string> stack);
    WebHistoryData();
    ~WebHistoryData();

    /**
        Adds a website to the stack to be returned to in the future
        @param website - Website address
    */
    void visitWebsite(const std::string& website);

    /**
        Returns the previously visited website and removes it from the history
        @returns String website address
    */
    std::string goBack();

    /**
        Views the previously visited website but doesn't remove it
        @returns String website address
    */
    std::string getCurrentWebsite() const;

    /**
        Check if the user has any history available
    */
    bool hasHistory() const;
};

#endif