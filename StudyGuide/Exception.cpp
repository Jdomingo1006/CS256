#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

double divide(int, int);

int main() {

	int num1, num2;
	double quotient;

	//Get two numbers.
	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	//Divide num1 by num 2 and catch any
	//potential exceptions.

	try
	{
	quotient = divide(num1, num2);
	cout << "The quotient is " << quotient <<  endl;
	}
	catch (string exceptionString)
	{
		cout << exceptionString;
	}

	cout << "End of program.\n";
	return 0;
}

double divide(int numerator, int denominator) {
	if (denominator == 0)
	{
		string exceptionString = "Error: Cannot divide by zero. \n";
		throw exceptionString;
	}
	return static_cast<double>(numerator) / denominator;
}