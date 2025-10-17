#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class List {
	
private:
	List* create_list(int length);
public:
	List* prev;
	List* next;
	string value;
	List();
	List(const std::string& values);
	int get_length();
	void print_list();
	List get_element(int pos);
	string get_value();
	void add_element(int pos,const string& value);
	void delete_element(int pos);
	void set_value(string value);
};