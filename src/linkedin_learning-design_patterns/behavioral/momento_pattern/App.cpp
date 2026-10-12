#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Canvas;

class CanvasMomento {
private:
    friend class Canvas;
    const std::vector<std::string> shapes;

public:
    CanvasMomento(std::vector<std::string> shapes): shapes(shapes) {}

};
 
class Canvas {
private:
    std::vector<std::string> shapes;
    std::stack<CanvasMomento*> oldStates;

public:
    ~Canvas() {
        while(!oldStates.empty()) {
            delete oldStates.top();
            oldStates.pop();
        }
    }

    void addShape(const std::string & newShape) {
        oldStates.push(new CanvasMomento(shapes));
        shapes.push_back(newShape);
    };

    void undo() {
        CanvasMomento* previousState = oldStates.top();
        shapes = previousState->shapes;
        oldStates.pop();
        delete previousState;
    }

    void clearAll() {
        shapes.clear();
    };


    std::vector<std::string> getShapes() { return shapes; };
};
 
int main(int argc, const char * argv[]) {
    Canvas *canvas = new Canvas;
    
    canvas->addShape("rhombus");
    canvas->addShape("triangle");
    canvas->addShape("square");
    canvas->addShape("circle");
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";
    
    canvas->undo();
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";
    
    canvas->addShape("rhombus");
    canvas->addShape("triangle");
    canvas->addShape("square");
    canvas->addShape("circle");
    canvas->undo();
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";
 
    delete canvas;

    return 0;
}