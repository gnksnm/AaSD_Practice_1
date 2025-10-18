#include "darray.h"

DArray::DArray() {
	size = 4;
	count = 0;
	arr = new std::string[size];
}

DArray::~DArray() {
	delete arr;
}

void DArray::resize_arr(unsigned new_size) {
	std::string* new_arr = new std::string[new_size];
	for (int i = 0; i <count; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
	size = new_size;
} 
void DArray::push_back(std::string value) {
	if (size == count) {
		resize_arr(size * 2);
	}
	arr[count] = value;
	count++;
}
void DArray::pop_back() {
	if (count == 0)
		throw std::out_of_range("Dinamic array is empty!");
	count--;
}

std::string& DArray::operator[](unsigned index) {
	if (index >= size)
		throw std::out_of_range("Index out of range!");
	return arr[index];
}

unsigned DArray::get_size() {
	return size;
}
