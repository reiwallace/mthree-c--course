#include "../../include/controller/web_history_controller.h"
#include <string>

WebHistoryController::WebHistoryController() {}

WebHistoryController::WebHistoryController(WebHistoryData* data, WebHistoryUI* ui):
data(data), ui(ui) {
    run();
}

WebHistoryController::~WebHistoryController() {
    delete data;
    delete ui;
}

void WebHistoryController::setData(WebHistoryData* data) {
    this->data = data;
}

void WebHistoryController::setUi(WebHistoryUI* ui) {
    this->ui = ui;
}

void WebHistoryController::run() {
    running = true;
    ui->start();

    while(running) {
        ui->outputCurrentAddress(data->getCurrentWebsite());
        ui->viewOptions();
        OPTION option = ui->getOption();

        switch(option) {
            case OPTION::ENTER_ADDRESS:
                getAddr();
            break;
            
            case OPTION::GO_BACK: {
                std::string previousAddress = data->goBack();
            }
            break;
            
            case OPTION::EXIT: 
                exit();
            break;

            case OPTION::RETRY:
              break;
        }
    }
}

void WebHistoryController::getAddr() {
    std::string address = ui->getAddress();
    data->visitWebsite(address);
}

void WebHistoryController::exit() {
    running = false;
    ui->exit();
}

