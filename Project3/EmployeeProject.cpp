/*
*James Domingo
*CS256
*Project 3
*May 24th 2018
*/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//Employee class
class Employee {
public:
	string name;
	int idNumber;
	string date;
	//Two constructors
	Employee() {
		name = "";
		idNumber = 0;
		date = "";
	}
	Employee(string inputName, int inputId, string inputDate) {
		name = inputName;
		idNumber = inputId;
		date = inputDate;
	}
	class InvalidEmployeeId {};
	//Setters
	void setName(string inputName) { name = inputName; }
	
	void setIdNumber(int inputId) {
		if ((inputId > 0) && (inputId < 9999))
			idNumber = inputId;
		else
			throw InvalidEmployeeId();
	}
	void setDate(string inputDate) { date = inputDate; }
	//Getters
	string getName() { return name; }
	int getIdNumber() { return idNumber; }
	string getDate() { return date; }	
};

//Production worker class
class ProductionWorker : public Employee {
public:
	int shift;
	double payRate;
	//Constructor
	ProductionWorker() {
		shift = 0;
		payRate = 0.0;
	}
	ProductionWorker(int inputShift, double inputPay) {
		setShift(inputShift);
		payRate = inputPay;
	}
	//Exception Classes
	class InvalidShift {};
	class InvalidPayRate {};
	//Setters
	void setShift(int inputShift) { 
		if ((inputShift > 0) && (inputShift < 24))
			shift = inputShift;
		else
			throw InvalidShift();
	}
	void setPayRate(double inputPay) {
		if (inputPay > 0)
			payRate = inputPay;
		else
			throw InvalidPayRate();
	}
	//Getters
	int getShift() { return shift; }
	double getPayRate() { return payRate; }

};

int main() {
	//Declaration of Variables
	double pay;
	int shift, idNumber;
	string name, date;
	bool loop1 = true, loop2 = true, loop3 = true;
	//Worker object
	ProductionWorker worker1;

	//User Inputted information
	
	//Input name
	cout << "Name of worker: ";
	cin >> name;
	worker1.setName(name);
	
	//Input ID
	cout << "Id: ";
	cin >> idNumber;
	while (loop1) {
		try
		{
			worker1.setIdNumber(idNumber);
			loop1 = false;
		}
		catch (Employee::InvalidEmployeeId) {
			cout << "\n\nError: Invalid Employee Id!" << endl;
			cout << "Enter valid ID Number: ";
			cin >> idNumber;
		}
	}
	
	//Input date of hire
	cout << "Date of hire: ";
	cin >> date;
	worker1.setDate(date);
	
	//Input payrate
	cout << "Payrate of " << name << ": $";
	cin >> pay;
	while (loop2) {
		try
		{
			worker1.setPayRate(pay);
			loop2 = false;
		}
		catch (ProductionWorker::InvalidPayRate) 
		{
			cout << "\n\nError: Invalid pay rate!" << endl;
			cout << "Enter valid Pay Rate: $";
			cin >> pay;
		}
	}
	
	//Inpur shift
	cout << "Shift: ";
	cin >> shift;
	while (loop3) {
		try
		{
			worker1.setShift(shift);
			loop3 = false;
		}
		catch (ProductionWorker::InvalidShift) {
			cout << "\n\nError: Invalid Shift!" << endl;
			cout << "Enter valid Shift Number: ";
			cin >> shift;
		}
	}

	//Print out information
	cout << "\n\n------------------Employee Info------------------" << endl;
	cout << "Name: " << worker1.getName() << endl;
	cout << "Id Number: " << worker1.getIdNumber() << endl;
	cout << "Date of hire: " << worker1.getDate() << endl;
	cout << "Pay Rate: $" << worker1.getPayRate() << " per hour" << endl;
	cout << "Shift: " << worker1.getShift() << endl;

}