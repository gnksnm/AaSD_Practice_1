#pragma once
#include <iostream>
#include <string>
#include <sstream>

class DArray {
private:
	unsigned size;
	unsigned count;
	std::string* arr;
	void resize_arr(unsigned new_size);
public:
	DArray();
	~DArray();
	void push_back(std::string value);
	void pop_back();
	std::string& operator[](unsigned index);
	unsigned get_size();
};