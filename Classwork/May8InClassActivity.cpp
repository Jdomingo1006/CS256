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
	int zip;
	int phone;
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
	void setZip(int zipCode);
	void setPhone(int phoneNumb);

	//getters
	string getLastName();
	string getFirstName();
	string getAddress();
	string getCity();
	int getZip();
	int getPhone();
};


//Setters - PersonData
void PersonData::setLastName(string ln) {lastName = ln;}
void PersonData::setFirstName(string fn) {firstName = fn;}
void PersonData::setAddress(string add) {address = add;}
void PersonData::setCity(string cit) {city = cit;}
void PersonData::setState(string st) {state = st;}
void PersonData::setZip(int zipCode) {zip = zipCode;}
void PersonData::setPhone(int phoneNumb) {phone = phoneNumb;}
//Getters - PersonData
string PersonData::getLastName() { return lastName; }
string PersonData::getFirstName() { return firstName; }
string PersonData::getAddress() { return address; }
string PersonData::getCity() { return city; }
int PersonData::getZip() { return zip;}
int PersonData::getPhone() { return phone; }

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
//Setters
void CustomerData::setCustomerNumber(int numb) { customerNumber = numb; }
void CustomerData::setMailingList(bool answer) { mailingList = answer; }
//Getters
int CustomerData::getCustomerNumber() { return customerNumber; }
bool CustomerData::getMailingList() { return mailingList; }

//PreferredCustomer class
class PreferredCustomer : public CustomerData {
private:
	double purchaseAmount;
	double discountLevel;
public:
	PreferredCustomer() {
		purchaseAmount = 0.0;
		discountLevel = 0.0;
	}
	//Setters
	void setPurchasesAmount(double purchase);
	void setDiscountLevel(double discount);
	//Getters
	double getPurchasesAmount();
	double getDiscountLevel();
};

//Setters
void PreferredCustomer::setPurchasesAmount(double purchase) { 

}
void PreferredCustomer::setDiscountLevel(double discount) { discountLevel = discount; }
//Getters
double PreferredCustomer::getPurchasesAmount() { return purchaseAmount; }
double PreferredCustomer::getDiscountLevel() { return discountLevel; }


int main() {

	return 0;
}