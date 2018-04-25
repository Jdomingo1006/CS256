/*
James Domingo
CS256
Quiz 2
*/

#include <iostream> 
using namespace std;
double pi = 3.14159;
class Circle {
	double radius;
	
public:
	Circle();
	Circle(double rad);
	
	//Setters
	void setRadius(double rad);

	//Getters
	double getRadius();
	double getArea();
	double getDiameter();
	double getCircumference();

};

//Constructors
Circle::Circle() {
	radius = 0.0;
}
Circle::Circle(double rad) {
	radius = rad;
}

//Setter
void Circle::setRadius(double rad) {
	radius = rad;
}

//Getter
double Circle::getRadius() {
	return radius;
}

double Circle::getDiameter() {
	double diameter;
	diameter = radius * 2;
	return diameter;
}
double Circle::getCircumference() {
	double circumference;
	circumference = 2 * pi * radius;
	return circumference;
}
double Circle::getArea() {
	double area;
	area = pi * radius * radius;
	return area;
}

int main(int argc, char ** argv) {
	double enteredRadius;
	cout << "Enter radius: " << endl;
	cin >> enteredRadius;
	Circle Circle(enteredRadius);

	//Set radius
	Circle.setRadius(enteredRadius);

	//Get radius/diameter/circumference/area
	cout << "Radius is: " << Circle.getRadius() << endl;
	cout << "Diameter is: " << Circle.getDiameter() << endl;
	cout << "Circumference is: " << Circle.getCircumference() << endl;
	cout << "Area is: " << Circle.getArea() << endl;


	return 0;
}