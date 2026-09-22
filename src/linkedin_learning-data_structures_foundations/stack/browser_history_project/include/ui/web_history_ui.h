#ifndef WEB_HISTORY_CONSOLE
#define WEB_HISTORY_CONSOLE

#include <string>

enum class OPTION {
    ENTER_ADDRESS,
    GO_BACK,
    EXIT,
    RETRY
};

class WebHistoryUI {
public:
    /**
        Views history menu options
    */
    void viewOptions() const;

    /**
        Gets a menu option as an OPTION enum
    */
    OPTION getOption() const;

    /**
        Gets an address input from the user
    */
    std::string getAddress() const;

    /**
        Outputs an address to the user
        @param address
    */
    void outputCurrentAddress(const std::string &address) const;

    /**
        Outputs exit message to the user
    */
    void exit() const;

    /**
        Outputs opening text to the user
    */
    void start() const;
};

#endif