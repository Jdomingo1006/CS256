/*
*CS256
*May 3rd, 2018
*James Domingo
*/
//****************************************
//Problem 2 - Lots of code used from the first DayOfTheYear problem
//****************************************
#include <iostream> 
#include <string>
using namespace std;

void checkMonth(string month, int day);

class DayOfYear2 {
private:
	string YearMonth;
	int YearDay;
	string months[12];
	int EndDayOfMonth[13];
	static int Date;
public:
	DayOfYear2(string monthTwo, int dayTwo);
	void print2();
	void setEndDayOfMonth2();
	void setMonths2();
};

//Sets date to 0
int DayOfYear2::Date = 0;

//Constructor with string month and integer day as parameters
DayOfYear2::DayOfYear2(string monthTwo, int dayTwo) {
	YearMonth = monthTwo;
	YearDay = dayTwo;
}

//Function that checks the end days of each month
void DayOfYear2::setEndDayOfMonth2() {
	EndDayOfMonth[0] = 31;
	EndDayOfMonth[1] = 28;
	EndDayOfMonth[2] = 31;
	EndDayOfMonth[3] = 30;
	EndDayOfMonth[4] = 31;
	EndDayOfMonth[5] = 30;
	EndDayOfMonth[6] = 31;
	EndDayOfMonth[7] = 31;
	EndDayOfMonth[8] = 30;
	EndDayOfMonth[9] = 31;
	EndDayOfMonth[10] = 30;
	EndDayOfMonth[11] = 31;
}

//Setting month names
void DayOfYear2::setMonths2() {
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

//Function that is called to print out what day the user inputted
void DayOfYear2::print2() {
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int index = 0;
	if (YearMonth.compare("December") == 0)
		index = 11;
	else if (YearMonth.compare("November") == 0)
		index = 10;
	else if (YearMonth.compare("October") == 0)
		index = 9;
	else if (YearMonth.compare("September") == 0)
		index = 8;
	else if (YearMonth.compare("August") == 0)
		index = 7;
	else if (YearMonth.compare("July") == 0)
		index = 6;
	else if (YearMonth.compare("June") == 0)
		index = 5;
	else if (YearMonth.compare("May") == 0)
		index = 6;
	else if (YearMonth.compare("April") == 0)
		index = 5;
	else if (YearMonth.compare("March") == 0)
		index = 4;
	else if (YearMonth.compare("April") == 0)
		index = 3;
	else if (YearMonth.compare("March") == 0)
		index = 2;
	else if (YearMonth.compare("Febuary") == 0)
		index = 1;
	else if (YearMonth.compare("January") == 0)
		index = 0;
	int total = 0;
	for (int i = 0; i < index; i++)
		total += monthDays[i];
	total += YearDay;
	cout << "\nThe day of the year " << YearMonth << ", " << YearDay << " is: " << total << "\n";

}
//Checks to see if user input is valid for month
void checkMonth(string month, int day) {
	int index = 0;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month.compare("December") == 0)
		index = 11;
	else if (month.compare("November") == 0)
		index = 10;
	else if (month.compare("October") == 0)
		index = 9;
	else if (month.compare("September") == 0)
		index = 8;
	else if (month.compare("August") == 0)
		index = 7;
	else if (month.compare("July") == 0)
		index = 6;
	else if (month.compare("June") == 0)
		index = 5;
	else if (month.compare("May") == 0)
		index = 6;
	else if (month.compare("April") == 0)
		index = 5;
	else if (month.compare("March") == 0)
		index = 4;
	else if (month.compare("April") == 0)
		index = 3;
	else if (month.compare("March") == 0)
		index = 2;
	else if (month.compare("Febuary") == 0)
		index = 1;
	else if (month.compare("January") == 0)
		index = 0;
	if (day > monthDays[index] || day > 31 || day < 1) {
		cout << "Invalid Day.Program Terminated.\n";
		exit(0);
	}
}

int main() {
	//Declaration of variables
	string month2;
	int day2;

	//Asks user input
	cout << "Please input a month (capital first letter): \n";
	cin >> month2;
	cout << "Please input a day 1-31:\n";
	cin >> day2;

	//calls checkMonth function to see if user input is valid
	checkMonth(month2, day2);

	//Initialization of classes to use functions
	DayOfYear2 userDay2(month2, day2);
	userDay2.setEndDayOfMonth2();
	userDay2.print2();
	return 0;
}