#include <stdio.h>
/*void main(){
	FILE *fp; //pointer to a file type

	fp = fopen("textFile.txt", "w+");
	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);
	fclose(fp);
}*/

/*void main(){
	FILE *fp;
	char buff[255];

	fp = fopen("textFile.txt", "r");
	fscanf(fp, "%s", buff);
	printf("1 : %s\n", buff );

	fgets(buff, 255, (FILE*) fp);
	printf("2: %s\n", buff);

	fgets(buff, 255, (FILE*)fp);
	printf("3: %s\n", buff);
	fclose(fp);
 }*/

/*typedef struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
} Book;*/

/*union Data{
	int i; //4 bytes
	double f; //8 bytes
	char str[20]; //20 bytes
};*/

//typedef int number;

	/*
	char str[100];
	int i;

	printf("Enter a value :");
	fflush(stdout);
	scanf("%s %d", str, &i);

	printf("\nYou entered: %s %d ", str, i);*/

	/*char str[100]; //Char array STRING used as a buffer
	printf("Enter a value :");
	fflush(stdout);
	gets (str);
	printf("\nYou entered: ");
	puts(str);*/

	/*
	number c;
	printf("Enter a value:");
	fflush(stdout); //ECLIPSE BUG
	c = getchar();

	printf("\nYou entered: ");
	putchar(c);*/

	/*union Data data; //Be 20 bytes in ram
	data.i = 10;
	printf("data.i: %d\n", data.i);

	data.f = 220.5;
	printf("data.f: %f\n", data.f);

	strcpy(data.str, "C Programming");
	printf("data.str: %s\n", data.str);

	return 0;*/
	/*Book Book1, book2, book3;
	//struct Books Book1; //Declares "Book1"
	strcpy(Book1.title, "C Programming");
	strcpy(Book1.author, "Nima Davarpanah");
	strcpy(Book1.subject, "C Programming Tutorial");
	Book1.book_id = 123466;

	printf("Book 1 title: %s\n", Book1.title);
	printf("Book 1 author: %s\n", Book1.author);
	printf("Book 1 subject: %s\n", Book1.subject);
	printf("Book 1 book: %d\n", Book1.book_id);*/

	//Pointer exercise --- From Line 19 to 24
	/*int var = 20;
	int *ip; <-- ip is a pointer of type int
	ip = &var;
	printf("Address of var varibable: %x\n", &var);
	printf("Address stored in ip variable: %x\n", ip);
	printf("Value of *ip variable: %d\n", *ip);*/


	//Pass by pointers(Part 1 of 2) --- line 18 to 24

	/*int a = 45, b = 35;
	printf("Before Swap\n");
	printf("A = %d b = %d\n", a,b);
	swap(&a, &b);
	printf("After Swap\n");
	printf("A = %d b = %d\n", a,b);*/

//Extras
/*char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char greeting[] = "Hello";*/

/*
char str1[12] = "Hello";
char str2[12] = "World";
char str3[12];
int len;

//copies str1 into str3
strcpy(str3, str1);
printf(strcpy);



char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
printf("Greeting message: %s\n", greeting);*/


//Pass by pointers(Part 2 of 2) --- swap function
/*void swap(int* x, int* y){
	int z = *x;
	*x = *y;
	*y = z;
}*/

