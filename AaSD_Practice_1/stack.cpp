#include "stack.h"

Stack::Stack() {
    top = nullptr;
}

void Stack::push(const std::string& value) {
    List* node = new List();
    node->value = value;
    node->next = top;
    node->prev = nullptr;
    if (top) top->prev = node;
    top = node;
}

std::string Stack::pop() {
    if (!top) return "";
    std::string val = top->value;
    List* temp = top;
    top = top->next;
    if (top) top->prev = nullptr;
    delete temp;
    return val;
}

std::string Stack::peek() {
    if (!top) return "";
    return top->value;
}

bool Stack::is_empty() {
    return top == nullptr;
}