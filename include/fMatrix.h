// File: fMatrix.h 
// Author(s): Henrik Eriksson, Johan Sollenius
// Description: 
// This file contains the public interface for the fmatrix module. 
// A fmatrix represents a matrix of floating point numbers of a certain size. [intArray.c]

#define _CRT_SECURE_NO_WARNINGS
#ifndef FMATRIX_H
#define FMATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//3x3 matrix
#define ROWS 3 
#define COLS 3
typedef float fMatrix[ROWS][COLS];

//This function takes a float as its only input parameter, and
// creates a new fMatrix filled with the float
// Parameters 
// a: a float, for which the fMatrix is to be filled with. 
// Returns 
// A pointer to a fMatrix
fMatrix* createMatrix(float a);

//This function takes a pointer to a fMatrix as its only input parameter, and
// frees the fMatrix from the heap
void destroyMatrix(fMatrix* a);

//This function takes a pointer to a fMatrix as its only input parameter, and
// prints the matrix to the console
void printMatrix(fMatrix* a);

//This function takes a fMatrix pointer as its only input parameter, and
// asks for a specific number of floats as input in format a,b,c,d,e...... if the input is invalid return 0 else 1
// adds the float to the matrix
// Parameters 
// a: a fMatrix pointer. 
// Returns 
// An integer 0(false) or 1(true) depending on the validity of the input from stdin 
int getMatrix(fMatrix* a);

//This function takes two fMatrix pointers as input parameter, and
// adds them together, Store the result in the first fMatrix (a).
void matAdd(fMatrix* a, fMatrix* b);

//This function takes two fMatrix pointers as input parameter, and
// does matrix multiplication, Store the result in the first fMatrix (a).
void matMul(fMatrix* a, fMatrix* b);
#endif