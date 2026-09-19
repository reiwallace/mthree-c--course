#include <iostream>
#include <queue>
#include <string>


int main() {
    std::queue<std::string> eventQueue;

    eventQueue.push("Move Forward");
    eventQueue.push("Collect Coin");
    eventQueue.push("Attack Enemy");

    while(!eventQueue.empty()) {
        std::string currentEvent = eventQueue.front();
        std::cout << "Performing Event: " << currentEvent << std::endl;
        eventQueue.pop();
    }

    return 0;
}