#include <iostream>
#include <stack>

int main() {
    std::stack<std::string> cardStack;

    // Push items to the top of the stack
    cardStack.push("Jack of Hearts");
    cardStack.push("2 of Diamonds");
    cardStack.push("10 of Spades");

    // Get top card from the stack
    std::string top_card = cardStack.top();
    cardStack.pop();

    // Check if stack is empty
    if(cardStack.empty()) {
        std::cout << "Card stack is empty" << std::endl;
    } else {
        std::cout << "Card stack size: " << cardStack.size() << std::endl;
    }

    std::cout << std::endl;
    return 0;
}