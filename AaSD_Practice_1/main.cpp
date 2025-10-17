#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "stack.h"

bool is_operator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/" || token == "^";
}

int precedence(const std::string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

bool is_math_function(const std::string& token) {
    return token == "sin" || token == "cos";
}

std::string shunting_yard(const std::string& expr) {
    Stack op_stack;
    std::string output;
    std::string token;
    std::stringstream ss(expr);

    while (ss >> token) {
        if (std::isdigit(token[0])) {
            output += token + " ";
        }
        else if (is_math_function(token)) {
            op_stack.push(token);
        }
        else if (is_operator(token)) {
            while (!op_stack.is_empty() &&
                is_operator(op_stack.peek()) &&
                ((precedence(op_stack.peek()) > precedence(token)) ||
                    (precedence(op_stack.peek()) == precedence(token) && token != "^"))) {
                output += op_stack.pop() + " ";
            }
            op_stack.push(token);
        }
        else if (token == "(") {
            op_stack.push(token);
        }
        else if (token == ")") {
            while (!op_stack.is_empty() && op_stack.peek() != "(") {
                output += op_stack.pop() + " ";
            }
            if (!op_stack.is_empty() && op_stack.peek() == "(") {
                op_stack.pop();
            }
            if (!op_stack.is_empty() && is_math_function(op_stack.peek())) {
                output += op_stack.pop() + " ";
            }
        }
        else {
            std::cout << "Неизвестный токен: " << token << std::endl;
            return "";
        }
    }

    while (!op_stack.is_empty()) {
        output += op_stack.pop() + " ";
    }

    return output;
}

double evaluate_rpn(const std::string& rpn) {
    Stack value_stack;
    std::stringstream ss(rpn);
    std::string token;

    while (ss >> token) {
        if (std::isdigit(token[0])) {
            value_stack.push(token);
        }
        else if (is_operator(token)) {
            double b = std::stod(value_stack.pop());
            double a = std::stod(value_stack.pop());
            double result = 0;
            if (token == "+") result = a + b;
            if (token == "-") result = a - b;
            if (token == "*") result = a * b;
            if (token == "/") result = a / b;
            if (token == "^") result = std::pow(a, b);
            value_stack.push(std::to_string(result));
        }
        else if (is_math_function(token)) {
            double a = std::stod(value_stack.pop());
            double result = 0;
            if (token == "sin") result = std::sin(a);
            if (token == "cos") result = std::cos(a);
            value_stack.push(std::to_string(result));
        }
    }

    return std::stod(value_stack.pop());
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << " ";
    std::string expr;
    std::cout << "Введите выражение (через пробел между токенами): ";
    std::getline(std::cin, expr);
    std::string rpn = shunting_yard(expr);
    std::cout << "Обратная польская запись: " << rpn << std::endl<<"Результат: "<<evaluate_rpn(rpn);
    return 0;
}
