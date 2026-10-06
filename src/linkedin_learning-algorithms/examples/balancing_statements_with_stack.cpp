#include <iostream>
#include <stack>
#include <string>

bool checkMatchingParentheses(const std::string &s) {
    std::stack<char> parenthesesStack;

    char top;
    for(char c : s) {
        if(!parenthesesStack.empty()) {
            top = parenthesesStack.top();
        }

        if(
            c == '(' || 
            c == '{' || 
            c == '['
        ) {
            parenthesesStack.push(c);
        } else if (
            (c == ')' && top != '(') ||
            (c == '}' && top != '{') ||
            (c == ']' && top != '[')
        ) {
            return false;
        } else if (
            (c == ')' && top == '(') ||
            (c == '}' && top == '{') ||
            (c == ']' && top == '[')
        ) {
            parenthesesStack.pop();
        }
    }

    return parenthesesStack.empty();
}

int main() {
    std::string st = "(increment)";
    bool ans = checkMatchingParentheses(st);

    std::cout << "String: " << st << std::endl;
    std::cout << "Is " << (ans ? "" : "not ") << "valid." << std::endl;

    return 0;
}