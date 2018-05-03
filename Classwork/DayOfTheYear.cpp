#include <iostream> 
#include <string>
using namespace std;

class DayOfYear {
private:
	int day; //Integer day
	string months[12]; //Array string for month names
	int EndDayOfMonth[13]; //Holds number of days after each month to help differentiating months
	
	static string DayAndMonth;
	static int continuedDays;

public:
	DayOfYear(int d); //Requested constructor
	void print(); //Requested print function
	void setEndDayOfMonth(); //Differentiate between months
	void setMonths(); //Month names
};

string DayOfYear::DayAndMonth = "";
int DayOfYear::continuedDays = 0;

//Constructor
DayOfYear::DayOfYear(int d) {
	day = d;
}

//Note: Need to get the day after each month
void DayOfYear::setEndDayOfMonth() {
	EndDayOfMonth[0] = 0; //First Day
	EndDayOfMonth[1] = 31; //January
	EndDayOfMonth[2] = 59; //Febuarary
	EndDayOfMonth[3] = 90; //March
	EndDayOfMonth[4] = 120; //April
	EndDayOfMonth[5] = 151; //May
	EndDayOfMonth[6] = 181; //June
	EndDayOfMonth[7] = 212; //July
	EndDayOfMonth[8] = 243; //August
	EndDayOfMonth[9] = 273; //September
	EndDayOfMonth[10] = 304; //October
	EndDayOfMonth[11] = 334; //November
	EndDayOfMonth[12] = 365; //December
}

//Set the month names
void DayOfYear::setMonths() {
	months[0] = "January";
	months[1] = "Febuarary";
	months[2] = "March";
	months[3] = "April";
	months[4] = "May";
	months[5] = "June";
	months[6] = "July";
	months[7] = "August";
	months[8] = "September";
	months[9] = "October";
	months[10] = "November";
	months[11] = "December";
}

//Being worked on. Used to print and called in main function
void DayOfYear::print() {
	int month = 0;
	//While loop - Goes through EndDayOfMonth function
	while (EndDayOfMonth[month] < day) {
		month++;
	}
	DayAndMonth += months[month - 1];
	continuedDays += day - EndDayOfMonth[month - 1];
	cout << "\nUser input: " << day;
	cout << "\nThe month and day is: " << DayAndMonth << " " << continuedDays << endl;
}

int main() {
	int dayInput;
	//User input
	cout << "Enter a day-number between 1 and 365: ";
		cin >> dayInput;
	//User input check.
	while (dayInput < 1 || dayInput >365) {
		cout << "Please enter a correct number" << endl;
		cout << "Enter day-number between 1 and 365: ";
		cin >> dayInput;
	}

	DayOfYear d(dayInput);
	d.setMonths();
	d.setEndDayOfMonth();
	d.print();
	return 0;
}