/*James Domingo
*CS256
*April 24, 2018
*/
# include <iostream>
# include <iomanip>
#include <string>
using namespace std;
void listOfSeats();
int main()
{
	//Declaration and assignment of variables.
	int choice, rowChoice;
	int counter = 0, column1 = 0;
	int totalSeats = 450;
	const int rowCount = 15;
	int rowNumber[rowCount];
	const char boughtSeat = '#';
	const char availableSeat = '*';
	int userRow, userColumn;
	const int row = 15, column = 30;
	char seats[row][column];
	int tixSold = 0;
	double tixPrice = 0, tixTotal = 0;
	bool done = false;

	//Prints out theater seating
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
		{
			seats[i][j] = availableSeat;
		}
	}
	listOfSeats();

	//Enters price for each row
	cout << "Please enter your cost per row:" << endl;
	for (int i = 0; i < row; i++)
	{
		cout << "Row #" << i + 1 << ": $";
		cin >> rowNumber[i];
	}
	cout << endl;

	//Main menu of Theater Seating
	do {
		cout << "Welcome to Theater Seating!" << endl;
		cout << "Please select an option below: " << endl;
		cout << "1) Sell a ticket" << endl;
		cout << "2) List the current seating chart" << endl;
		cout << "3) How many tickets sold" << endl;
		cout << "4) Theater seating information" << endl;
		cout << "5) Seat availability for each row" << endl;
		cout << "6) Exit" << endl;
		cout << "User's selection (1, 2, 3, 4, 5, or 6): " << endl;
		cin >> choice;

		//Switch case depending on what number user chose
		switch (choice) {

		//Sells tickets
		case 1:
			cout << "Enter a row number and a seat number for the ticket: ";
			cout << endl;
			do {
				//Checks user input. Row must be 1-15 and columns must be 1-30
				cout << "Row #:";
				cin >> userRow;
				if (userRow < 1 || userRow > 15) {
					cout << "Please enter a valid row number."<<endl;
				}

			} while (userRow < 1 || userRow > 15);
			do {

				cout << "Column #:";
				cin >> userColumn;
				if (userColumn <0 || userColumn > 30) {
					cout << "Please enter a valid column number."<<endl;
				}
			} while (userColumn < 1 || userColumn > 30);
			cout << endl;
			//If-else statement to check if seat is taken/available
			if (seats[userRow - 1][userColumn - 1] == boughtSeat)
			{
				cout << "----------------------" << endl;
				cout << "Error:" << endl;
				cout << "This seat is taken! \nTry another one." << endl;
				cout << "----------------------\n\n" << endl;
				continue;
			}
			else {
				seats[userRow - 1][userColumn - 1] = boughtSeat;
				tixSold++;

				tixPrice = rowNumber[userRow - 1];
				tixTotal = tixTotal + tixPrice;
				cout << "----------------------" << endl;
				cout << "Price of ticket: $" << tixPrice << endl;
				cout << "Total ticket Price: $" << tixTotal << endl;
				cout << "----------------------" << endl;
				cout << "\n\n";
			}
			break;
		//Lists current seats
		case 2:
			//Prints out theater seating
			cout << "                   Seats" << endl;
			cout << "      123456789012345678901234567890";

			for (int i = 0; i < row; i++) {
				if (i < 9) {
					cout << endl << "Row " << i + 1 << " ";
				}
				else {
					cout << endl << "Row" << i + 1 << " ";
				}
					for (int j = 0; j < column; j++) 
					{
						cout << seats[i][j];
					}
					
				}
			cout << "\n\n";
			break;
		//List current tickets sold. Includes number of tickets sold and money made
		case 3:
			cout << endl;
			cout << "----------------------" << endl;
			cout << "Total tickets sold: " << tixSold << endl;
			cout << "Money made: $" << tixTotal << endl;
			cout << "----------------------" << endl;
			cout << "\n\n";
			break;
		//Lists seats sold and number of seats left
		case 4:
			cout << "----------------------" << endl;
			cout << "Total seats sold: " << tixSold << endl;
			cout << "Seats left: " << (totalSeats - tixSold) << endl;
			cout << "----------------------" << endl;
			break;
		//Lists available number of seats in each row
		case 5:
			do {
				cout << "Choose row: " << endl;
				cin >> rowChoice;
				if (rowChoice < 1 || rowChoice > 15) {
					cout << "Please enter a valid row number." << endl;
				}

			} while (rowChoice < 1 || rowChoice > 15);
			for (int i = 0; i < column; i++) {
				if (seats[rowChoice - 1][column1 - 1 + i] != boughtSeat) {
					counter++;
				}
			}
			cout << "----------------------" << endl;
			cout << "Row " << rowChoice<< " has " << counter<<" seats left" << endl;
			cout << "----------------------" << endl;
			cout << "\n" << endl;
			counter = 0;
			break;	
		//Quits the program
		case 6:
			//Only option to break the do-while loop
			cout << "Thank you for using Theater Seating!" << endl;
			done = true;
			break;
		//If user didnt choose any of the options
		default:
			cout << "Please enter 1, 2, 3, 4, 5, or 6!";
			break;
		}
	} while (!done);
	return 0;
}

//Function for listOfSeats. Called in the beginning of the program (line 34)
void listOfSeats() {
		const char boughtSeat = '#';
		const char availableSeat = '*';
		const int row = 15;
		const int column = 30;
		cout << "	  Theater seating layout" << endl;
		cout << "      123456789012345678901234567890";
		for (int i = 0; i < row; i++)
		{
			if (i < 9) {
				cout << endl << "Row " << i + 1 << " ";
			}
			else {
				cout << endl << "Row" << i + 1<< " ";
			}
			for (int j = 0; j < column; j++)
			{
				cout << availableSeat;
			}
		}
		cout << endl;
}