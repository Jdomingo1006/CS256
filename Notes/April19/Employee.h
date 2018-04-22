#pragma once
//#ifndef Employee_H
//#define Employee_H
//ALL THE CODE WE ARE WRITING BELOW
//#endif

#include <string> //String class to use string objects
using namespace std; //standard namespace being used

//Class is struct/functions
//Want to encapsulate the data
class Employee {
private:
	string name;
	int idNumber;
	string department;
	string position;
public:
	//Constructors with different parameters
	Employee(string nm, int id, string dept, string pos);
	Employee(string nm, int id);
	Employee();


	// setters or accessors
	void setName(string nm);
	void setidNumber(int id);
	void setDepartment(string dept);
	void setPosition(string pos);

	//getters or mutators
	string getName();
	int getidNumber();
	string getDepartment();
	string getPosition();
};