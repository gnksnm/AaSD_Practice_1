#pragma once
#include <iostream>
#include <string>
#include <sstream>

class List {
	
private:
	List* create_list(int length);
public:
	List* prev;
	List* next;
	std::string value;
	List();
	List(const std::string& values);
	int get_length();
	void print_list();
	List get_element(int pos);
	std::string get_value();
	void add_element(int pos,const std::string& value);
	void delete_element(int pos);
	void set_value(std::string value);
};