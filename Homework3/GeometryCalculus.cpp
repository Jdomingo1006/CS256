#include <iostream>

using namespace std;

int main() {
	//Declaration of variables
	int choice;
	double radius, area;
	double pi = 3.14159;
	double width, length;
	double base, height;

	//The menu of the calculator
	cout << "Geometry Calculator\n";
	cout << "1. Calculate the Area of a Circle\n";
	cout << "2. Calculate the Area of a Rectangle\n";
	cout << "3. Calculate the Area of a Triangle\n";
	cout << "4. Quit\n";
	cout << "Enter your choice (1-4): \n";

	cin >> choice;

	//Switch case for the user's chocie
	switch (choice) {
	case 1:
		cout << "Calculating the area of a circle\n";
		cout << "Enter your radius: ";
		cin >> radius;
		if (radius >= 0) {
			area = pi * (radius * radius);
			cout << "The area of a circle with the radius of " << radius << " has the area: " << area;
		}
		else {
			cout << "Please enter a positive number";
		}
		break;
	case 2:
		cout << "\nCalculating the area of a rectangle\n";
		cout << "Enter your width: ";
		cin >> width;
		cout << "Enter your length: ";
		cin >> length;
		if (width >= 0 && length >= 0) {
			area = length * width;
			cout << "Your rectangle's area is: " << area;
		}
		else {
			cout << "Please enter a positive number for both length and width";
		}
		break;
	case 3:
		cout << "\nCalculating the area of a triangle\n";
		cout << "Enter your base: ";
		cin >> base;
		cout << "Enter your height: ";
		cin >> height;
		if (base >= 0 && height >= 0) {
			area = base * height * .5;
			cout << "Your triangle's area is: " << area;
		}
		else {
			cout << "Please enter a positive number for both length and width";
		}
		break;
	case 4:
		cout << "Goodbye.";
		break;
	default:
		cout << "Please choose a number from 1 through 4.";
		break;

		return 0;
	}
}