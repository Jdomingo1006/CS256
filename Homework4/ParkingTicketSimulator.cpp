/*
*James Domingo
*CS256
*May 10th, 2018
*/


#include "stdafx.h"
#include <iostream> 
#include <string> 
using namespace std;

//Parked car function
class ParkedCar {
private:
	string make;
	int model;
	string color;
	string licenseNumber;
	int minutes;
public:
	//Default constructor
	ParkedCar() {
		make = "";
		model = 0;
		color = "";
		licenseNumber = "";
		minutes = 0;
	}
	//Setters
	void setMake(string inputMake) { make = inputMake; }
	void setModel(int inputModel) { model = inputModel; }
	void setColor(string inputColor) { color = inputColor; }
	void setLicenseNumber(string inputLicense) { licenseNumber = inputLicense; }
	void setMinutes(int inputMinute) { minutes = inputMinute; }
	//Getters
	string getMake() { return make; }
	int getModel() { return model; }
	string getColor() { return color; }
	string getLicenseNumber() { return licenseNumber; }
	int getMinutes() { return minutes; }
	//Print function
	void print() {
		cout << "Car's Make: " << getMake() << endl;
		cout << "Car's Model: " << getModel() << endl;
		cout << "Car's License Number: " << getLicenseNumber() << endl;
		cout << "Car's Color:" << getColor() << endl;
	}

};



//ParkingMeter - Class
class ParkingMeter:public ParkedCar{
private:
	int minutesPurchased;
public:
	//Default constructor
	ParkingMeter() {
		minutesPurchased = 0;
	}
	//Setters
	void setMinutesPurchase(int inputMinute) { minutesPurchased = inputMinute; }
	//Getters
	int getMinutesPurchase() { return minutesPurchased; }
	//Print function
	void print() {
		cout << "Minutes purchased: " << getMinutesPurchase() << endl;
	}
};

//Parking Ticket - Class
class ParkingTicket:public ParkedCar {
private:
	int minutesParked;
	int fineGiven;
public:
	void getTicket(int inputMinute) {
		minutesParked = inputMinute;
		if ((minutesParked / 60) <= 0) {
			fineGiven = 25; //fine = $25
		}else {
			int hoursParked = minutesParked / 60; //finds out the hours parked
			fineGiven = 25 + (10 * (hoursParked)); // $25 + ($10 x (hours))
		}
	}
	//Getter for fine given
	int getFineGive() { return fineGiven; }
	void print() {
		cout << "Amount of minutes parked illegally: " << minutesParked << " minutes" << endl;
		cout << "Fine amount: $" << fineGiven << endl;
	}
};
//Police Officer - Class
class PoliceOfficer:public ParkingTicket {
private:
	string policeName;
	int badgeNumber;
public:
	//Constructor
	PoliceOfficer() {
		policeName = "";
		badgeNumber = 0;
	}
	//Setters
	void setPoliceName(string inputName) { policeName = inputName; }
	void setBadgeNumber(int inputBadge) { badgeNumber = inputBadge; }
	//Getters
	string getPoliceName() { return policeName; }
	int getBadgeNumber() { return badgeNumber; }
};

int main() {

	//Police Officer info
	string name;
	int badge;
	PoliceOfficer officerInfo;
	cout << "---------Starting Information--------------" << endl;
	cout << "Parking rates: $25 for the first 60 minutes." << endl;
	cout << "       $10 for the following hours" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Please enter your information" << endl;
	cout << "Name: ";
	cin >> name;
	cout << "Badge number: ";
	cin >> badge;
	officerInfo.setPoliceName(name);
	officerInfo.setBadgeNumber(badge);

	//Cars in Violation information
	ParkingMeter parkingInfo;
	string make, color, licenseNumber;
	int model, minutes;
	cout << "--------------Violator's car information--------------" << endl;
	cout << "Enter Car's information" << endl;
	cout << "Car's make: ";
	cin >> make;
	cout << "Car's model: ";
	cin >> model;
	cout << "Car's color: ";
	cin >> color;
	cout << "Car's license number: ";
	cin >> licenseNumber;
	cout << "Amount of minutes in violation: ";
	cin >> minutes;
	//Setting user input car information
	parkingInfo.setColor(color);
	parkingInfo.setLicenseNumber(licenseNumber);
	parkingInfo.setMake(make);
	parkingInfo.setMinutes(minutes);
	parkingInfo.setModel(model);

	//Cost of fine
	cout << "\n\n\n" << endl;
	ParkingTicket ticketInfo;
	cout << "--------------Fine Information--------------" << endl;
	ticketInfo.getTicket(parkingInfo.getMinutes());
	ticketInfo.print();


	//Final output
	cout << "--------------Car Description--------------" << endl;
	cout << "Car's Make: " << parkingInfo.getMake() << endl;
	cout << "Car's Model: " << parkingInfo.getModel() << endl;
	cout << "Car's License Number: " << parkingInfo.getLicenseNumber() << endl;
	cout << "Car's Color:" << parkingInfo.getColor() << endl;
	cout << "-------------------------" << endl;
	cout << "Issued by: " << officerInfo.getPoliceName() << endl;
	cout << "Badge number: " << officerInfo.getBadgeNumber() << endl;


	return 0;
}