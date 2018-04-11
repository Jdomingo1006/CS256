/*James Domingo
 * CS256
 * HW2 - Exercise 2
 * April 11th, 2018
 */
#include <stdio.h>
int main(){
	//Problem 2 - Ocean Levels
	double currentOL = 1.5;
	double fiveYears = currentOL * 5;
	double sevenYears = currentOL * 7;
	double tenYears = currentOL * 10;
	printf("The current ocean level is %.2f millimeters\n", currentOL);
	printf("After 5 years, the ocean level would be %.2f millimeters\n", fiveYears);
	printf("After 7 years, the ocean level would be %.2f millimeters\n", sevenYears);
	printf("After 10 years, the ocean level would be %.2f millimeters\n", tenYears);
	return 0;
}

