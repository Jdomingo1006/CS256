#include <iostream>
using namespace std;

float getPopulation(double, double, double);

int main() {
	int years;
	double birthRate, deathRate, population, newPopulation;

	//Getting birthrate/deathrate/population/etc from user
	cout << "Welcome to Population program\n";
	cout << "What is the starting size of the population?";
	cin >> population;
	cout << "What is the annual birth rate?";
	cin >> birthRate;
	cout << "What is the annual death rate?";
	cin >> deathRate;
	cout << "Amount of years to be calculated?";
	cin >> years;

	//Calculates new population with correct numbers
	if ((population > 2) && ((birthRate && deathRate) >= 0) && (years >=1)) {
		//Shows initial population
		cout << "\nInitial Population: " << population << "\n";
		
		//For-loop to count each year
		for (int i = 0; i < years; i++) {
			//Calls "getPopulation" function to calculate a new population
			newPopulation = getPopulation(population, birthRate, deathRate);
			//Prints out each year
			cout << "Population by year " << (i + 1) << ": " << newPopulation << "\n";
			//Updates population
			population = newPopulation;
		}
	}
	//Incorrect numbers from user
	else {
		cout << "Please enter valid numbers\n";
		cout << "Starting population should be more than 2.\n";
		cout << "No negative numbers for either rate.\n";
		cout << "Minimum number of 1 year for years.\n";
	}
	return 0;
}

//Function that calculates population with birthrate/deathrate
float getPopulation(double P, double B, double D) {
	double N;
	N = P + (B*P) - (D*P);
	return N;
}