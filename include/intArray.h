// File: intArray.h 
// Author(s): Henrik Eriksson, Johan Sollenius
// Description: 
// This file contains the public interface for the intarray module. 
// An intarray represents a list of integer numbers of a certain size. [intArray.c]

#ifndef INTARRAY_H
#define INTARRAY_H
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

#define SENTINEL -1 //The teriminator that determines the size of the intArray
#define CAPACITY 50 //The "true" size of the array, Wich is the maximum size for an intArray.

typedef int intArray[CAPACITY];
enum sortOrders { ASCENDING, DESCENDING };
enum uniquenesses { UNIQUE, NONUNIQUE };

// This function takes an intArray as its only input parameter, and 
// prints out the array to the stdout excluding the terminating SENTINEL
void printIntArray(intArray arr);

// This function takes an intArray as its only input parameter, and 
// returns the length of the array, excluding the terminating SENTINEL. 
// Parameters 
// a: an intArray, for which the size is to be computed. 
// Returns 
// An integer representing the size of the intArray. int getIntArraySize(intArray a) 
int getIntArraySize(intArray arr);

//This function takes an intArray as its only input parameter, and
// asks for unsigned integers as input in format a,b,c,d,e...... if the input is invalid return 0 else 1
// adds the integers to the intArray
// Parameters 
// a: an intArray, for which the size is to be computed. 
// Returns 
// An integer 0(false) or 1(true) depending on the validity of the input from stdin 
int getIntArray(intArray arr);

//This function takes 3 intArrays as its input parameter, and
//Appends b to a and add it to a resulting c intArray
// Parameters 
// a,b: two intArrays to append, c: an intArray on wich to store the result on. 
void appendIntArray(intArray a, intArray b, intArray c);

//This function takes 3 intArrays as its input parameter, and
//Interleaves the elements a1,b1,a2,b2.... everyother. If uneven lengths add the rest to the end without interleaving
// Parameters 
// a,b: two intArrays to interleave, c: an intArray on wich to store the result on. 
void interleaveIntArray(intArray a, intArray b, intArray c);

//This function takes an intArray as its only input parameter, and
//Sorts an intArray either ascending, descending, unique or nonunique depending on the settings
//Standard is ASCENDING and NONUNIQUE
//Parameters
//arr: the intArray to be sorted
void sortIntArray(intArray arr);

//This function takes an int as its only input parameter
//Sets the private static variable in [intArray.c] wich determines in what way an intArray should be sorted when calling
// void sortIntArray(intArray arr)
//Parameters
//a: Sort setting use sortOrders enum, ASCENDING(0) or DESCENDING(1)
void setSortOrder(int a);

//This function takes an int as its only input parameter
//Sets the private static variable in [intArray.c] wich determines in what way an intArray should be sorted when calling
// void sortIntArray(intArray arr)
//Parameters
//a: Sort setting use uniquenesses enum, UNIQUE(0) or NONUNIQUE(1)
void setUniqueness(int a);
#endif