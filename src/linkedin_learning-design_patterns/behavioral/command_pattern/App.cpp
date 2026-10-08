#include <iostream>
#include <string>
#include <vector>
class Canvas {
private:
    std::vector<std::string> shapes;

public:
    void addShape(const std::string &newShape) {
        shapes.push_back(newShape);
    }

    void clearAll() {
        shapes.clear();
    }

    std::vector<std::string> getShapes() {
        return shapes;
    }
};

class Command {
public:
    virtual ~Command() {};
    virtual void execute() = 0;
};

class AddShapeCommand: public Command {
private:
    std::string shape;
    Canvas *canvas;

public:
    AddShapeCommand(const std::string& shape, Canvas *canvas): shape(shape), canvas(canvas) {}

    void execute() {
        canvas->addShape(shape);
    }
};

class ClearCommand: public Command {
private:
    Canvas *canvas;

public:
    ClearCommand(Canvas *canvas): canvas(canvas) {}

    void execute() {
        canvas->clearAll();
    }

};

class Button {
private:
    Command *COMMAND; 

public:
    Button(Command *command): COMMAND(command) {}

    void click() {
        COMMAND->execute();
    }
};

std::string vectorToString(std::vector<std::string> vec) {
    std::string vectorString = "{";

    for(const std::string& string : vec) {
        vectorString.append(string);

        if(&string != &vec.back()) {
            vectorString.append(", ");
        }
    }

    vectorString.append("}");

    return vectorString;
}

int main() {
    Canvas *canvas = new Canvas();

    Button *addTriangleButton = new Button(new AddShapeCommand("triangle", canvas));
    Button *addSquareButton = new Button(new AddShapeCommand("square", canvas));
    Button *clearButton = new Button(new ClearCommand(canvas));

    addTriangleButton->click();
    std::cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << "\n";

    addSquareButton->click();
    addSquareButton->click();
    addTriangleButton->click();
    std::cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << "\n";

    clearButton->click();
    std::cout << "Current canvas state: " << vectorToString(canvas->getShapes()) << "\n";

    delete canvas;
    delete addTriangleButton;
    delete addSquareButton;
    delete clearButton;
    return 0;
}
