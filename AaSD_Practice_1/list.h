#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class List {
private:
	List* prev;
	List* next;
	int value;
	List* create_list(int length);
public:
	List();
	List(int length,const std::string& values);
	int get_length();
	void print_list();
	List get_element(int pos);
	int get_value();
	void add_element(int pos,int value);
	void delete_element(int pos);
	void set_element(int pos, int value);
};