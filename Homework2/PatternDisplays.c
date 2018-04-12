/*James Domingo
 * CS256
 * HW2 - Exercise 2
 * April 11th, 2018
 */
#include <stdio.h>

int main(){
	printf("________________________________\n");
	printf("%s%20s\n","Pattern A", "Pattern B");
	printf("________________________________\n");

	for(int a = 0; a<=10; a++)
	{
		for(int b = 0; b<=a; b++)
		{
			printf("+");

		}
		printf("%20s", "");
		for(int c = 10; c>=a; c--)
		{

			printf("+");
		}
		printf("\n");
	}
	return 0;
}
