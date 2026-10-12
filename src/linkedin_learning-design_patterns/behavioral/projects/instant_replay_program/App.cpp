#include <iostream>
#include <vector>

class Canvas;
class ReplayCanvas;

class CanvasMomento {
private:
    friend class Canvas;
    friend class ReplayCanvas;
    const std::vector<std::string> shapes;

public:
    CanvasMomento(std::vector<std::string> shapes): shapes(shapes) {}

};
 
class CanvasIterator {
public:
    virtual ~CanvasIterator() {}
    virtual CanvasMomento *next() = 0;
    virtual bool isFinished() = 0;
};

class ForwardsIterator: public CanvasIterator {
private:
    int currentPosition;
    std::vector<CanvasMomento*> &history;
public:
    ForwardsIterator(std::vector<CanvasMomento*> &history): currentPosition(0), history(history) {}

    CanvasMomento *next() override {
        return history.at(currentPosition++);
    }

    bool isFinished() override {
        return currentPosition >= history.size();
    }
};

class History {
public:
    virtual void addState(CanvasMomento *newState) = 0;
    virtual CanvasMomento *undo() = 0;
};

class NullHistory: public History {
private:
    CanvasMomento *state;
public:
    NullHistory() {
        state = new CanvasMomento({});
    }

    void addState(CanvasMomento *newState) {
        state = newState;
    }
    
    CanvasMomento *undo() {
        return state;
    }
};

class CanvasHistory: public History {
private:
    std::vector<CanvasMomento*> oldStates;

public:
    ~CanvasHistory() {
        for(auto state: oldStates) {
            delete state;
        }
    }

    void addState(CanvasMomento *newState) override {
        oldStates.push_back(newState);
    }

    CanvasMomento * undo() override {
        delete oldStates.back();
        oldStates.pop_back();
        CanvasMomento* previousState = oldStates.back();
        return previousState;
    }

    ForwardsIterator *getForwardsIterator() {
        return new ForwardsIterator(oldStates);
    }
};

class Canvas {
private:
    std::vector<std::string> shapes;
    History *history;

public:
    Canvas(History *history): history(history) {}

    void addShape(const std::string & newShape) {
        shapes.push_back(newShape);
        history->addState(new CanvasMomento(shapes));
    }

    void undo() {
        shapes = history->undo()->shapes;
    }

    void clearAll() {
        shapes.clear();
        history->addState(new CanvasMomento(shapes));
    };


    std::vector<std::string> getShapes() { return shapes; };
};

class ReplayCanvas {
private:
    std::vector<std::string> shapes;
    ForwardsIterator *historyIterator;

public:
    ReplayCanvas(CanvasHistory *history) {
        historyIterator = history->getForwardsIterator();
    }

    void replay() {
        while(!historyIterator->isFinished()) {
            CanvasMomento *nextState = historyIterator->next();
            shapes = nextState->shapes;

            std::cout << "The shapes are now: ";
            for(auto shape : shapes) {
                std::cout << shape << ", ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    NullHistory *history = new NullHistory;
    Canvas *canvas = new Canvas(history);
    
    canvas->addShape("rhombus");
    canvas->addShape("triangle");
    canvas->addShape("square");
    canvas->addShape("circle");
    
    std::cout << "Null canvas current shapes:\n";
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";
    
    std::cout << "Trying to undo...\n";
    canvas->undo();
    canvas->undo();
    canvas->undo();
    
    std::cout << "Null canvas shapes after undo:\n";
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";

    std::cout << std::endl;
    return 0;
}