#include <iostream>
#include <string>

class State {
private:
    State *nextState = nullptr;
    const std::string DESCRIPTION;
public:
    State(State *nextState, std::string description):
    nextState(nextState), DESCRIPTION(description) {}

    virtual std::string getDescription() {
        return DESCRIPTION;
    }

    virtual State *getNextState() {
        return nextState;
    }
};

class PurchaseState: public State {
public:
    PurchaseState(State *nextState): 
    State(nextState, "Current State: PURCHASED - Will be shipping soon\n") {}
};

class InTransitState: public State {
public:
    InTransitState(State *nextState): 
    State(nextState, "Current State: IN_TRANSIT - Your item is on the way\n") {}
};

class DeliveredState: public State {
public:
    DeliveredState(State *nextState): 
    State(nextState, "Current State: DELIVERED - Your item has arrived\n") {}
};

class Purchase {
private:
    std::string productName;
    State *currentState;

public:
    Purchase(const std::string &productName, State *initialState):
    productName(productName), currentState(initialState) {}

    std::string getDescription() {
        return currentState->getDescription();
    }

    void goToNextState() {
        if(currentState->getNextState()) {
            currentState = currentState->getNextState();
        } else {
            std::cout << "No more states!\n";
        }
    }
};

int main() {
    DeliveredState *deliveredState = new DeliveredState(nullptr);
    InTransitState *inTransitState = new InTransitState(deliveredState);
    PurchaseState *purchasedState = new PurchaseState(inTransitState);

    Purchase *purchase = new Purchase("Shoes", purchasedState);

    std::cout << purchase->getDescription() << "\n";

    purchase->goToNextState();
    std::cout << purchase->getDescription() << "\n";

    purchase->goToNextState();
    std::cout << purchase->getDescription() << "\n";


    delete deliveredState;
    delete inTransitState;
    delete purchasedState;
    delete purchase;

    return 0;
}