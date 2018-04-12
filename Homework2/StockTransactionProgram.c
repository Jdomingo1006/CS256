/*James Domingo
 * CS256
 * HW2 - Exercise 3
 * April 11th, 2018
 */
int main(){
	//First part of the problem
	int shares = 1000;
	double costPerShare = 45.50;
	double TotalCost = shares * costPerShare;
	double commission = (.02 * TotalCost);

	//Second part of the problem
	int sharesSold = 1000;
	double soldPerShare = 56.90;
	double TotalSold = sharesSold * soldPerShare;
	double secondCommission = (.02 * TotalSold);

	//Profit made
	//Found out by (Sold - Cost) which both includes the subtraction of commission
	double profit = ((TotalSold - secondCommission) - (TotalCost - commission));

	//Third part of the problem
	printf("Joe paid $%.2f for the stock\n", TotalCost);
	printf("Joe paid his broker $%.2f\n", commission);
	printf("He sold the stock for $%.2f\n", TotalSold);
	printf("After selling the stock, he paid his broker $%.2f\n\n", secondCommission);
	printf("Joe gained a profit of $%.2f\n", profit);

	return 0;
}

