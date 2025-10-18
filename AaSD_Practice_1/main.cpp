#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>
#include "stack.h"
#include <Windows.h>

int priority(std::string token) {
    if (token == "(") return 1;
    if (token == "+" || token == "-") return 2;
    if (token == "*" || token == "/") return 3;
    if (token == "sin" || token == "cos") return 4;
    if (token == "^") return 5;
}
bool is_number(std::string token) {
    try {
        stoi(token);
        return true;
    }
    catch (...) {
        return false;
    }
}

std::string rpn(const std::string &ss) {
    Stack stack;
    std::string output;
    std::string token;
    std::stringstream sv(ss);
    while (sv >> token) {
        if (is_number(token)) {
            output += token;
            output += " ";
        }
        else {
            if (token == "(") {
                stack.push(token);
            }
            else if (token == ")") {
                while (stack.peek() != "(") {
                    output += stack.pop() + " ";
                }
                stack.pop();
                if (priority(stack.peek()) == 4) {
                    output += stack.pop() + " ";
                }
            }
            else if (token == "^") {
                stack.push(token);
            }
            else {
                while (stack.peek() != ""&&(priority(stack.peek()) >= priority(token)) && token != "^") {
                    output += stack.pop() + " ";
                }
                stack.push(token);
            }
        }
    }
    while (stack.peek() != "") {
        output += stack.pop() + " ";
    }
    return output;
}

int main() {
    std::string ss;
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Введите выражение (все символы и числа через пробел): ";
    getline(std::cin,ss);
    std::cout<< "Обратная польская нотация : "<<rpn(ss);
    return 0;
}
