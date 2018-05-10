/*
*James Domingo
*CS256
*May 9th 2018
*/
#include "stdafx.h"
#include <iostream> 
#include <string> 
using namespace std;

//PersonData class
class PersonData {
private:
	string lastName;
	string firstName;
	string address;
	string city;
	string state;
	long int zip;
	long int phone;
public:
	// default Constructor
	PersonData() {
		lastName = "";
		firstName = "";
		address = "";
		city = "";
		state = "";
		zip = 0;
		phone = 0;
	}
	//setters
	void setLastName(string ln);
	void setFirstName(string fn);
	void setAddress(string add);
	void setCity(string cit);
	void setState(string st);
	void setZip(long zipCode);
	void setPhone(long phoneNumb);

	//getters
	string getLastName();
	string getFirstName();
	string getAddress();
	string getCity();
	string getState();
	long int getZip();
	long int getPhone();
};

//Setters - PersonData
void PersonData::setLastName(string ln) { lastName = ln; }
void PersonData::setFirstName(string fn) { firstName = fn; }
void PersonData::setAddress(string add) { address = add; }
void PersonData::setCity(string cit) { city = cit; }
void PersonData::setState(string st) { state = st; }
void PersonData::setZip(long int zipCode) { zip = zipCode; }
void PersonData::setPhone(long int phoneNumb) { phone = phoneNumb; }
//Getters - PersonData
string PersonData::getLastName() { return lastName; }
string PersonData::getFirstName() { return firstName; }
string PersonData::getAddress() { return address; }
string PersonData::getCity() { return city; }
string PersonData::getState() { return state; }
long int PersonData::getZip() { return zip; }
long int PersonData::getPhone() { return phone; }

//CustomerData class
class CustomerData : public PersonData {
private:
	int customerNumber;
	bool mailingList;
public:
	//Constructor
	CustomerData() {
		customerNumber = 0;
		mailingList = false;
	}
	//Setters
	void setCustomerNumber(int numb);
	void setMailingList(bool answer);
	//Getters
	int getCustomerNumber();
	bool getMailingList();
};
//Setters - CustomerData
void CustomerData::setCustomerNumber(int numb) { customerNumber = numb; }
void CustomerData::setMailingList(bool answer) { mailingList = answer; }

//Getters - CustomerData
int CustomerData::getCustomerNumber() { return customerNumber; }
bool CustomerData::getMailingList() { return mailingList; }

//PreferredCustomer class
class PreferredCustomer : public CustomerData {
private:
	double purchaseAmount;
	double discountLevel;
public:
	PreferredCustomer() {
		purchaseAmount = 0;
		discountLevel = 0;
	}
	//Setters
	void setPurchasesAmount();
	void setDiscountLevel();
	//Getters
	double getPurchasesAmount();
	double getDiscountLevel();
};

//Setters - PreferredCustomer
void PreferredCustomer::setPurchasesAmount() {
	double spent;
	cout << "Total amount spent: " << endl;
	cin >> spent;
	purchaseAmount = spent;

}
void PreferredCustomer::setDiscountLevel() {
	if (purchaseAmount >= 500 && purchaseAmount < 1000) {
		discountLevel = 5;
	}
	else if (purchaseAmount >= 1000 && purchaseAmount < 1500) {
		discountLevel = 6;
	}
	else if (purchaseAmount >= 1500 && purchaseAmount < 2000) {
		discountLevel = 7;
	}
	else if (purchaseAmount >= 2000) {
		discountLevel = 10;
	}
}

//Getters - PreferredCustomer
double PreferredCustomer::getPurchasesAmount() {
	return purchaseAmount;
}
double PreferredCustomer::getDiscountLevel() {
	return discountLevel;
}


int main() {
	PreferredCustomer customer;
	string userfirstN, userlastN, userAddress, userCity, userState;
	long int userZip, userPhone;
	int userId;

	cout << "Enter first name: " << endl;
	cin >> userfirstN;
	customer.setFirstName(userfirstN);
	cout << "Enter last name:" << endl;
	cin >> userlastN;
	customer.setLastName(userlastN);
	cout << "Enter address:" << endl;
	cin >> userAddress;
	customer.setAddress(userAddress);
	cout << "Enter city:" << endl;
	cin >> userCity;
	customer.setCity(userCity);
	cout << "Enter state:" << endl;
	cin >> userState;
	customer.setState(userState);
	cout << "Enter zip code:" << endl;
	cin >> userZip;
	customer.setZip(userZip);
	cout << "Enter customer number:" << endl;
	cin >> userId;
	customer.setCustomerNumber(userId);
	customer.setMailingList(true);
	customer.setPurchasesAmount();
	customer.setDiscountLevel();
	cout << "Enter phone number:" << endl;
	cin >> userPhone;
	customer.setPhone(userPhone);

	cout << "\n\nCustomer Data shown below:" << endl;
	cout << "First Name:" << customer.getFirstName() << endl;
	cout << "Last Name:" << customer.getLastName() << endl;
	cout << "Customer Number:" << customer.getCustomerNumber() << endl;
	cout << "City name:" << customer.getCity() << endl;
	cout << "State name:" << customer.getState() << endl;
	cout << "Zip Code:" << customer.getZip() << endl;
	cout << "Phone number:" << customer.getPhone() << endl;
	cout << "Mailing list:" << customer.getMailingList() << endl;
	cout << "Customer purchase amount:" << customer.getPurchasesAmount() << endl;
	cout << "Customer discount:" << customer.getDiscountLevel() << "%" << endl;

	return 0;
}