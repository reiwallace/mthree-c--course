# include "include/controller/web_history_controller.h"
# include "include/dao/web_history_data.h"
#include "include/ui/web_history_ui.h"

int main() {
    WebHistoryUI* ui = new WebHistoryUI();
    WebHistoryData* data = new WebHistoryData();

    WebHistoryController controller(data, ui);

    return 0;
}