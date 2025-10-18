#include "list.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

List::List() {
    prev = nullptr;
    next = nullptr;
    value = "";
}

List::List(const string & values) {
    std::stringstream ss(values);
    int count = 0;
    string val;
    while (ss >> val) {
        count++;
    }
    if (count == 0) {
        next = prev = nullptr;
        value = "";
        return;
    }
    List* head = create_list(count);
    std::stringstream st(values);
    List* curr = head;
    
    while (st >> val && curr) {
        curr->value = val;
        curr = curr->next;
    }
    value = curr->value;
    next = curr->next;
    prev = curr->prev;
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
    if ((pos < this->get_length()) && (this->get_length() >= 0)) {
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        return *curr;
    } else {
        cout << endl << "��� �������� � ����� ��������";
    }
    return *this;
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

string List::get_value() {
    return this->value;
}

void List::add_element(int pos, const string &value) {
    List* node = new List();
    node->value = value;
    if (pos == 0) {
        prev = node;
        node->next = next;
        node->prev = nullptr;
        this->value = node->value;
        next = node->next;
        prev = node->prev;
    } else if (pos == get_length()) {
        List* curr = this;
        while (curr->next) {
            curr = curr->next;
        }
        node->prev = curr;
        curr->next = node;
        node->next = nullptr;
    } else if (pos < get_length()) {
        List* curr = this;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        node->prev = curr;
        node->next = curr->next;
        curr->next = node;
        if (node->next) {
            node->next->prev = node;
        }
    } else {
        cout << "������ �������� ������ ��� ����������";
    }
}

void List::delete_element(int pos) {
    if (pos == 0) {
        if (next) {
            value = next->value;
            List* temp = next;
            next = next->next;
            if (next) {
                next->prev = this;
            }
            delete temp;
        }
    } else if (pos == get_length() - 1) {
        List* curr = this;
        while (curr->next) {
            curr = curr->next;
        }
        curr->prev->next = nullptr;
        delete curr;
    } else if (pos < get_length() - 1) {
        List* curr = this;
        for (int i = 0; i < pos; i++) {
            curr = curr->next;
        }
        if (curr->prev = this)this->next = curr->next;
        else curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    } else {
        cout << "������ �������� ������ ��� ��������";
    }
}

void List::set_value(string value) {

}