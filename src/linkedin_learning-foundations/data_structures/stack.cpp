#include <iostream>
#include <queue>
#include <stack>
#include <string>


int main() {
    std::queue<std::string> eventQueue;
    std::stack<std::string> undoStack;

    eventQueue.push("Move Forward");
    eventQueue.push("Collect Coin");
    eventQueue.push("Attack Enemy");

    while(!eventQueue.empty()) {
        std::string currentEvent = eventQueue.front();
        std::cout << "Performing Event: " << currentEvent << std::endl;
        eventQueue.pop();
        undoStack.push(currentEvent);
    }

    while(!undoStack.empty()) {
        std::string lastEvent = undoStack.top();
        std::cout << "Undoing Event: " << lastEvent << std::endl;
        undoStack.pop();
    }

    return 0;
}