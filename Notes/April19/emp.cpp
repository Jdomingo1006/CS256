#include "Employee.h"
#include <iostream>

#include <string> //String class to use string objects
using namespace std; //standard namespace being used

Employee::Employee(string nm, int id, string dept, string pos) {
	name = nm;
	idNumber = id;
	department = dept;
	position = pos;
}
Employee::Employee(string nm, int id) {
	name = nm;
	idNumber = id;
	department = "";
	position = "";

}
Employee::Employee() {
	name = "";
	idNumber = 0;
	department = "";
	position = "";

}
	//Setters
	void Employee::setName(string nm) 
	{
		name = nm;
	}
	void Employee::setidNumber(int id) 
	{
		idNumber = id;
	}
	void Employee::setDepartment(string dept)
	{
		department = dept;
	}
	void Employee::setPosition(string pos) 
	{
		position = pos;
	}
	//Getters
	string Employee::getName() 
	{
		return name;
	}
	int Employee::getidNumber() 
	{
		return idNumber;

	}
	string Employee::getDepartment()
	{
		return department;

	}
	string Employee::getPosition() 
	{
		return position;
	}