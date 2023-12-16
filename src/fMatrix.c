
#define _CRT_SECURE_NO_WARNINGS
#include "fMatrix.h"


//Helper functions for matMul
static float* getRow(int idx, fMatrix* a);
static float* getCol(int idx, fMatrix* a);


fMatrix* createMatrix(float a)
{
	fMatrix* m = malloc(sizeof(fMatrix));

	if (m != NULL)
	{
		for (int r = 0; r < ROWS; r++)
		{
			for (int c = 0; c < COLS; c++)
			{
				(*m)[r][c] = a;
			}
		}

	}

	return m; //Will return NULL if for some reason the memory didn't get allocated
}

void destroyMatrix(fMatrix* m)
{
	if (m != NULL) free(m);
}

void printMatrix(fMatrix* m)
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			printf("%.2f  ", (*m)[r][c]);
		}
		printf("\n");
	}
}


int getMatrix(fMatrix* m)
{
	char str[100];
	float tmp[ROWS][COLS]; 
	scanf("%s", str);

	//No starting or ending comma
	if (str[0] == ',') return 0;
	if (str[strlen(str) - 1] == ',') return 0;

	//No consecutive commas
	int c = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ',') c++;
		else c = 0;
		if (c == 2) return 0;
	}

	//Split the string with the delimeter ',' and convert the parts to float and assign to the matrix
	char* token = strtok(str, ",");
	float num;
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			if (token == NULL) return 0; //Not enough numbers
			num = strtof(token, NULL);
			if (!num) return 0; //A non number was passed
			tmp[r][c] = num;
			token = strtok(NULL, ",");
		}
	}
	
	if (token != NULL) return 0; //A matrix larger than the one asked for was passed

	//If everyhting is valid begin to modify the matrix
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			(*m)[r][c] = tmp[r][c];
		}
	}


	return 1;

}

void matAdd(fMatrix* a, fMatrix* b)
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			(*a)[r][c] += (*b)[r][c];
		}
	}
}


//HELPER FUNCTIONS FOR MATMUL
//Get the specific row in the matrix, and put it in a float array
float* getRow(int idx, fMatrix* m)
{
	float* row = ((float*)malloc(ROWS * sizeof(float)));
	if (row == NULL) exit(137);

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			if (r == idx)
			{
				row[c] = (*m)[r][c];
			}

		}
	}
	
	return row;
}
//Get the specific column in the matrix, and put it in a float array
float* getCol(int idx, fMatrix* m)
{
	float* col = ((float*)malloc(COLS * sizeof(float)));
	if (col == NULL) exit(137);

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			if (c == idx)
			{
				col[r] = (*m)[r][c];
			}

		}
	}
	return col;
}
//------------------

void matMul(fMatrix* a, fMatrix* b)
{
	fMatrix* tmpMat = createMatrix(0.0f);


	int fNum = 0;
	for (int r = 0; r < ROWS; r++)
	{
		//Get the row to multiply with the first column in the second matrix
		float* row = getRow(r, a);
		for (int c = 0; c < COLS; c++)
		{
			//Get the column to multiply with the row in the first matrix
			float* col = getCol(c, b);

			fNum = 0;
			for (int j = 0; j < 3; j++)
			{
				fNum += row[j] * col[j];
			}
			//Assign it to the temporary matrix
			(*tmpMat)[r][c] = fNum;

			free(col);
		}
		free(row);



	}

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			(*a)[r][c] = (*tmpMat)[r][c];
		}
	}

	destroyMatrix(tmpMat);


}





