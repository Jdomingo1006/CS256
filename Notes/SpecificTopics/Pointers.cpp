#include <iostream>
using namespace std;
int main() {

	int* ptr;
	int* ptr2;
	int var = 7;
	int foo = 21;
	ptr = &var;
	*ptr = var;
	cout << "The address of var is: " << ptr << "\n"; // & = the address of. So pointer is pointing at the address of var
	cout << "The value of var is: " << *ptr << "\n"; // *ptr gains access to the value of var

	return 0;
}