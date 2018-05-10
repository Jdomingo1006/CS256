/*
*James Domingo
*CS256
*May 10th, 2018
*/

#include "stdafx.h"
#include <iostream> 
#include <string> 

using namespace std;


//Ship - class
class Ship {
private:
	string shipName;
	string shipBuilt;
public:
	//Constructor
	Ship(string name, string year) {
		shipName = name;
		shipBuilt = year;
	}
	void setShipName(string name) {
		shipName = name;
	}
	void setShipBuilt(string year) {
		shipBuilt = year;
	}

	string getShipName() { return shipName; }
	string getShipBuilt() { return shipBuilt; }

	virtual void print() {
		cout << "----------Displaying Ship---------------" << endl;
		cout << "Ship's Name: " << getShipName() << endl;
		cout << "Year built: " << getShipBuilt() << endl;
	}
};

//CruiseShip - class
class CruiseShip: public Ship{
private:
	int passengers;
public:
	CruiseShip(string name, string year, int pass) :Ship(name, year) {
		passengers = pass;
	}

	virtual void print() {
		cout << "\n\n" << endl;
		cout << "----------Displaying Cruise ship---------------" << endl;
		cout << "Ships Name: " << getShipName() << endl;
		cout << "Year built: " << getShipBuilt() << endl;
		cout << "Maximum capacity: " << passengers << " passengers" << endl;
	}

};

//CargoShip - class
class CargoShip :public Ship {
private:
	int tonnage;
public:
	CargoShip(string name, string year, int ton) :Ship(name, year) {
		tonnage = ton;
	}
	virtual void print() {
		cout << "\n\n" << endl;
		cout << "----------Displaying Cargo ship---------------" << endl;
		cout << "Ships Name: " << getShipName() << endl;
		cout << "Year Built: " << getShipBuilt() << endl;
		cout << "Weight capacity is: " << tonnage << " tonnage" << endl;
	}
};

//Main - function
int main() {
	Ship *shipTypes[3] = { new Ship("Limitless Paper","2005"), 
		new CruiseShip("in a ","2006", 1738), 
		new CargoShip("Paperless world","2007", 20) 
	};

	for (int i = 0; i < 3; i++) {
		shipTypes[i]->print();
	}
	return 0;
}