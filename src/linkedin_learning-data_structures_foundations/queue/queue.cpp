#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> printerQueue;
    printerQueue.push("TaylorSwiftTickets.pdf");
    printerQueue.push("MarketingNotes.docx");
    printerQueue.push("Proof.png");

    while(!printerQueue.empty()) {
        std::string document = printerQueue.front();
        std::cout << "Printing " << document << std::endl;
        printerQueue.pop();
    }

    return 0;
}