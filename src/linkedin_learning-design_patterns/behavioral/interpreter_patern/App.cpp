#include <iostream>
#include <string>

class Expression {
public:
    virtual int evaluate() = 0;
};

class OperationExpression: public Expression {
private:
    std::string operatorSymbol;
    Expression *leftHandSide;
    Expression *rightHandSide;

public:
    OperationExpression(const std::string &operatorSymbol, Expression *lhs, Expression *rhs):
    operatorSymbol(operatorSymbol), leftHandSide(lhs), rightHandSide(rhs) {}

    int evaluate() override {
        if(operatorSymbol == "+") {
            return leftHandSide->evaluate() + rightHandSide->evaluate();
        } else if (operatorSymbol == "-") {
            return leftHandSide->evaluate() - rightHandSide->evaluate();
        } else {
            std::cout << "Unrecognised operator: " << operatorSymbol << "\n";
            return -1;
        }
    }
};

class NumberExpression: public Expression {
private:
    std::string numberString;

public:
    NumberExpression(const std::string &numberString): numberString(numberString) {}
    int evaluate() override {
        return std::stoi(numberString);
    }
};

int main() {
    NumberExpression *five = new NumberExpression("5");
    NumberExpression *seven = new NumberExpression("7");
    OperationExpression *fivePlusSeven = new OperationExpression("+", five, seven);

    NumberExpression *thirteen = new NumberExpression("13");
    OperationExpression *complexOp = new OperationExpression("-", thirteen, fivePlusSeven);


    std::cout << "Five plus seven is " << fivePlusSeven->evaluate() << "\n";

    std::cout << "Thirteen minus five plus seven is " << complexOp->evaluate() << "\n";

    delete five;
    delete seven;
    delete fivePlusSeven;

    std::cout << std::endl;
    return 0;
}