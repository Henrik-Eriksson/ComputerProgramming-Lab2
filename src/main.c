#include "intArray.h"
#include "fMatrix.h"
void displayMainMenu(void);

int main()
{
	puts("By: Henrik Eriksson & Johan Sollenius");
	intArray a = { 0 };
	intArray b = { 0 };
	intArray c = { 0 };
	fMatrix* m1 = createMatrix(0.0f);
	fMatrix* m2 = createMatrix(0.0f);
	displayMainMenu();
	
	int input;
	
	while (1)
	{
		
		printf("?: ");
		if (scanf("%d", &input) != 1) //Incase a string is entered
		{
			puts("Invalid choice, Try again");
			fseek(stdin, 0, SEEK_END);
		}

		switch (input)
		{
		case 1:

			puts("Enter first intArray");
			while (!getIntArray(a)) puts("Invalid input, Try again");
			printIntArray(a);
			puts("Enter second intArray");
			while (!getIntArray(b)) puts("Invalid input, Try again");
			appendIntArray(a, b, c);
			puts("Result:");
			printIntArray(c);
			break;
		case 2:
			puts("Enter first intArray");
			while (!getIntArray(a)) puts("Invalid input, Try again");
			printIntArray(a);
			puts("Enter second intArray");
			while (!getIntArray(b)) puts("Invalid input, Try again");
			interleaveIntArray(a, b, c);
			puts("Result:");
			printIntArray(c);
			break;
		case 3:
			puts("Enter intArray to be sorted");
			while (!getIntArray(a)) puts("Invalid input, Try again");
			printIntArray(a);
			sortIntArray(a);
			puts("Result:");
			printIntArray(a);
			break;
		case 4:
			puts("Enter first matrix");
			while (!getMatrix(m1)) puts("Invalid input, Try again");
			printMatrix(m1);
			puts("Enter second matrix");
			while (!getMatrix(m2)) puts("Invalid input, Try again");
			printMatrix(m2);
			matAdd(m1, m2);
			puts("-------------------");
			printMatrix(m1);
			break;
		case 5:
			puts("Enter first matrix");
			while (!getMatrix(m1)) puts("Invalid matrix, Try again");
			printMatrix(m1);
			puts("Enter second matrix");
			while (!getMatrix(m2)) puts("Invalid matrix, Try again");
			printMatrix(m2);
			matMul(m1, m2);
			puts("-------------------");
			printMatrix(m1);
			break;
		case 6:
			displayMainMenu();
			break;
		case 7:
			exit(0);
			break;
		}
	}
}

void displayMainMenu(void) {
	puts("==========MAINMENU WELCOME=============\n");
	puts(" 1. Append two integer arrays");
	puts(" 2. Interleave two integer arrays");
	puts(" 3. Sort an integer array");
	puts(" 4. Add two 3x3 float matrices");
	puts(" 5. Multiply two 3x3 float matrices");
	puts(" 6. Print MainMenu");
	puts(" 7. Quit\n");
	printf("======================================\n");

}
