/*James Domingo
 * CS256
 * HW2 - Exercise 1
 * April 11th, 2018
 */


#include <stdio.h>

int main(){
	//Problem 1 - Restaurant Bill
	double meal = 88.67;
	double tax = (meal * .0675);
	double tip = .20 * (tax + meal);
	double total = tip + tax + meal;
	printf("Cost of meal: $%.2f\n", meal);
	printf("Plus tax: $%.2f\n", tax);
	printf("20 percent tip: $%.2f\n", tip);
	printf("Your total will be: $%.2f", total);
	return 0;
}

