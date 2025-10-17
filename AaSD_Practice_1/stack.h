#pragma once
#include <string>
#include "list.h"

class Stack {
private:
    List* top;
public:
    Stack();
    void push(const std::string& value);
    std::string pop();
    std::string peek();
    bool is_empty();
};