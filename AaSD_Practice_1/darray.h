#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class DArray {
private:
	unsigned size;
	unsigned count;
	string* arr;
	void resize_arr(unsigned new_size);
public:
	DArray();
	~DArray();
	void push_back(string value);
	void pop_back();
	string& operator[](unsigned index);
	unsigned get_size();
};