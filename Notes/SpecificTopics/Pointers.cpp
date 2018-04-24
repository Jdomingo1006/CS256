#include <iostream>
using namespace std;
int main() {

	int* ptr;
	int var = 7;
	ptr = &var;
	*ptr = var;
	cout << "The address of var is: " << ptr << "\n"; // & = the address of. So pointer is pointing at the address of var
	cout << "The value of var is: " << *ptr << "\n"; // *ptr gains access to the value of var
	//Print out:
	//The address of var is: 1000
	//The value of var is: 7

	return 0;
}
