#include <iostream>
using namespace std;

int main() {
	int population, years, newPopulation;
	double birthRate, deathRate;

	cout << "Welcome to Population program\n";
	cout << "What is the starting size of the population?";
	cin >> population;
	cout << "What is the annual birth rate?";
	cin >> birthRate;
	cout << "What is the annual death rate?";
	cin >> deathRate;
	cout << "Amount of years to be calculated?";
	cin >> years;

	if ((population > 2) && ((birthRate && deathRate) >= 0) && (years >=1)) {
		newPopulation = population + birthRate * population - deathRate*population;
		//newPopulation = years * newPopulation;
		cout << "The new population is " << newPopulation <<"\n";
	}
	else {
		cout << "Please enter valid numbers\n";
		cout << "Starting population should be more than 2.\n";
		cout << "No negative numbers for either rate.\n";
		cout << "Minimum number of 1 year for years.\n";
	}
	return 0;
}