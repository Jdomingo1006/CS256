#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int x = 25;
	int *ptr = nullptr; //Pointer variable, can point ot an int

	ptr = &x; //Store the address of x in ptr


	cout << "The address of x is " << ptr << endl; //Prints out random letters/numbers
	cout << "Pointer and declassification example: " << (*ptr +5) << endl; //Prints out 30
	cout << "The size of x is " << sizeof(x) << " bytes\n"; //4 bytes
	cout << "The value in x is " << x << endl; //Prints out 25
	return 0;
}
