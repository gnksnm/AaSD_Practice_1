#include "list.h"
//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;

List::List() {
	prev = nullptr;
    next = nullptr;
	value = 0;
}

List::List(int length, const string & values) {
    if (length <= 0) {
        next = prev = nullptr;
        value = 0;
        return;
    }
    List* head = create_list(length);
    std::stringstream ss(values);
    List* curr = head;
    int val;
    int count = 0;
    while (ss >> val && curr) {
        curr->value = val;
        curr = curr->next;
        count++;
    }
    value = head->value;
    next = head->next;
    prev = head->prev;
}

List* List::create_list(int length) {
    if (length <= 0) return nullptr;
    List* first = new List();
    List* curr = first;
    for (int i = 1; i < length; ++i) {
        List* node = new List();
        node->prev = curr;
        curr->next = node;
        curr = node;
    }
    return first;
}

void List::print_list() {
    List* curr = this;
    while (curr) {
        cout << curr->value << ' ';
        curr = curr->next;
    }
}

List List::get_element(int pos) {
    List* curr = this;
    if ((pos < this->get_length())&&(this->get_length()>=0)) {
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        return *curr;
    }
    else {
        cout << endl << "Нет элемента с таким индексом";
    }
}

int List::get_length() {
    int count = 0;
    List* curr = this;
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}

int List::get_value() {
    return this->value;
}