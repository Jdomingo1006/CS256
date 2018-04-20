/*James Domingo
CS256, Professor Nima Davarpanah
April 19th, 2018
*/
#include <iostream>
using namespace std;

//Swaps the values
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Function to reverse the array
void reverseArray(int array[], int array_size){
	//Assigning pointers to the array and values
	int *pointer1 = array,
		*pointer2 = array + array_size - 1;
	//While loop to switch values of array
	while (pointer1 < pointer2) {
		swap(pointer1, pointer2);
		pointer1++;
		pointer2--;
	}
}

//Function to print out array
void printArray(int* array, int array_size){
	int *length = array + array_size,
		*position = array;
	for (position = array; position < length; position++)
		cout << *position << " ";
}


int main()
{
	//Declaration and Assignment - Variables
	const int SIZE = 6;
	int array[SIZE];
	int *reversedArray;
	int size;
	int j = 0;

	//User inputted integers for an array. Max integer of 6.

	for (int i = 0; i < SIZE; i++) {
		cout << "Enter digit "<< (i + 1)<<":";
		cin >> array[i];
	}
	//Calls array function. Prints out user inputted integers as array
	cout << "The Original Array: ";
	printArray(array, 6);

	//Calls reverse function. Prints out reversed user inputted integer array
	cout << "\nReversed Array: ";
	reverseArray(array, 6);
	printArray(array, 6);

	//Easier to read
	cout << " \n";

	return 0;
}