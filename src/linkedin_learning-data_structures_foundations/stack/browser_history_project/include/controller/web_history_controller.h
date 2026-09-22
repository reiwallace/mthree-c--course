#ifndef WEB_HISTORY_CONTROLLER
#define WEB_HISTORY_CONTROLLER

#include "../dao/web_history_data.h"
#include "../ui/web_history_ui.h"

class WebHistoryController {
private:
    WebHistoryData* data;
    WebHistoryUI* ui;
    bool running;


    /**
    Retrieves an address from the view and passes it to the dao
    */
    void getAddr();

    /**
        Exits the program
    */
    void exit();

public:
    /**
        Creates a new web history controller and immediately begins running
        @param data - WebHistoryData implementation to access from and write data to
        @param ui - WebHistoryUI implementation to display information to the user
    */
    WebHistoryController(WebHistoryData* data, WebHistoryUI* ui);
    WebHistoryController();
    ~WebHistoryController();

    /**
        Runs the main web history controller loop
    */
    void run();

    void setData(WebHistoryData* data);
    void setUi(WebHistoryUI* ui);
};



#endif