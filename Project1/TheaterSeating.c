/*James Domingo
*CS256
*April 24, 2018
*/
#include <stdio.h>
int main(int argc, char** argv)
{
	//Declaration and assignment of variables.
	char choice;
	int rowChoice;
	int counter = 0, column1 = 0, seatCount = 0;
	int totalSeats = 450;
	const int rowCount = 15;
	int rowNumber[rowCount];
	const char boughtSeat = '#';
	const char availableSeat = '*';
	const int row = 15, column = 30;
	char seats[row][column];
	int tixSold = 0;
	double tixPrice = 0, tixTotal = 0;
	int userRow, userColumn;
	double input;
	int a = 0;

	//Prints out theater seating
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
		{
			seats[i][j] = availableSeat;
		}
	}
	printf("Seats  123456789012345678901234567890");

	for(int i=0; i<row; i++)
	{
		if (i <10){
			printf("\n%s%1d  ", "Row ", i);
		}
		else
		{
			printf("\n%s%1d  ", "Row", i);
		}

		for(int j=0; j<column; j++)
		{
			printf("%c", availableSeat);
		}
	}
	printf("\n");

	//Enters price for each row
	printf("Please enter your cost per row:");
	printf("\n");
	do{
		if(counter == 15){
			break;
		}
	for (int i = 0; i < row;)
	{
		printf("%s%1d%s", "Row # ", i+1, ": $");
		scanf("%1lf", &input);
		if(input >= 0){
			rowNumber[i] = input;
			i++;
			counter++;
		}else{
			printf("Invalid number\n");
			}
		}
	}while(input >= 0);
	do{
		//Main menu of Theater Seating
		printf("Welcome to Theater Seating!\n");
		printf("Please select an option below: \n");
		printf("1) Sell a ticket\n");
		printf("2) List the current seating chart\n");
		printf("3) How many tickets sold\n");
		printf("4) Seat availability for each row\n");
		printf("5) Exit\n");
		printf("User's selection (1, 2, 3, 4, or 5): \n");
		scanf("%1s", &choice);

		//Switch case depending on what number user chose
		switch (choice) {

		//Sells tickets
		case '1':
			printf("Enter a row number and a seat number for the ticket: ");
			printf("\n");
			do {
				//Checks user input. Row must be 1-15 and columns must be 1-30
				printf("Row #:");
				scanf("%i", &userRow);
				if (userRow < 1 || userRow > 15) {
					printf("Please enter a valid row number.");
				}

			} while (userRow < 1 || userRow > 15);
			do {

				printf("Column #:");
				scanf("%i", &userColumn);
				if (userColumn <0 || userColumn > 30) {
					printf("Please enter a valid column number.");
				}
			} while (userColumn < 1 || userColumn > 30);
			//If-else statement to check if seat is taken/available
			if (seats[userRow - 1][userColumn - 1] == boughtSeat)
			{
				printf("----------------------");
				printf("Error:\n");
				printf("This seat is taken! \nTry another one.\n");
				printf( "----------------------\n\n");
			}
			else {
				seats[userRow - 1][userColumn - 1] = boughtSeat;
				tixSold++;

				tixPrice = rowNumber[userRow - 1];
				tixTotal = tixTotal + tixPrice;
				printf("----------------------\n");
				printf("%s%.2f\n", "Price of ticket: $", tixPrice);
				printf("%s%.2f\n", "Total Price: $", tixTotal);
				printf("----------------------");
				printf("\n\n");
			}
			break;
		//Lists current seats
		case '2':
			//Prints out theater seating
			printf("%s","                   Seats\n");
			printf("%s","       123456789012345678901234567890");

			for (int i = 0; i < row; i++) {
				if (i < 9) {
					printf("\n%s%d  ", "Row ", (i+1));
				}
				else
				{
					printf("\n%s%d  ", "Row", (i+1));
				}
					for (int j = 0; j < column; j++)
					{
						printf("%c", seats[i][j]);
					}
				}
			printf("\n\n");
			break;
		//List current tickets sold. Includes number of tickets sold and money made
		case '3':
			printf( "----------------------\n");
			printf("%s%i\n", "Total Seats Sold: ", tixSold);
			printf("%s%.2f\n", "Money made: $ ", tixTotal);
			printf("----------------------" );
			printf( "\n\n");
			break;
		//Lists available number of seats in each row
		case '4':
			do {
				printf("Choose row: ");
				scanf("%i", &rowChoice);
				if (rowChoice < 1 || rowChoice > 15) {
					printf("Please enter a valid row number.\n");
				}
			} while (rowChoice < 1 || rowChoice > 15);
			for (int i = 0; i < column; i++) {
				if (seats[rowChoice - 1][column1 - 1 + i] != boughtSeat) {
					seatCount++;
				}
			}
			printf("----------------------\n");
			printf("%s%i%s%i%s\n", "Row ", rowChoice, " has ", seatCount, " seats left.");
			printf("----------------------");
			printf( "\n");
			seatCount = 0;
			break;
		//Quits the program
		case '5':
			//Only option to break the do-while loop
			printf("%s\n", "Thank you for using Theater Seating!");
			exit(0);
			break;
		//If user didnt choose any of the options
		default:
			printf("Please enter 1, 2, 3, 4, 5, or 6!");
			break;
		}
	}while(choice != '1' || choice != '2' || choice != '3' || choice != '4' || choice != '5' );
	return 0;
}
