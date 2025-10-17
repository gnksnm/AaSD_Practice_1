#include <iostream>
#include "list.h"
using namespace std;
int main() {
	string values = "10 20 30 40 50 60 70";
	List list(7,values); 
	cout<<list.get_length()<<endl;
	list.print_list();
	List a = list.get_element(1);
	cout << endl << a.get_value();
	return 0;
}