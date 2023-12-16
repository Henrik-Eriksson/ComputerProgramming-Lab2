#include "intArray.h"

static void swap(intArray arr, int i, int j); //Swaps two elements based on index
static void onlyUnique(intArray arr); //Removes identical elements
static int sortOrder = ASCENDING;
static int uniqueness = NONUNIQUE;

void printIntArray(intArray arr)
{
    printf("[ ");
    for (int i = 0; arr[i] != SENTINEL; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int getIntArraySize(intArray arr)
{
    int i;
    for (i = 0; arr[i] != SENTINEL; i++);
    return i;
}

int getIntArray(intArray arr)
{
    arr[0] = SENTINEL; //Default if input is invalid

    char str[100];
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

    //Split the string with the delimeter ',' and convert the parts to integers and assign to the intArray
    char* token = strtok(str, ",");

    int num;
    int i;
    for (i = 0; token != NULL; i++) {
        num = atoi(token);
        if (!num)
        {
            arr[0] = SENTINEL;
            return 0; //An invalid number was passed
        }
        arr[i] = num;
        token = strtok(NULL, ",");
    }

    arr[i] = SENTINEL;
    return 1;
}

void appendIntArray(intArray a, intArray b, intArray c)
{
    int i, j;
    for (i = 0; i < getIntArraySize(a); i++) c[i] = a[i];
    for (j = 0; j < getIntArraySize(b); j++) c[i + j] = b[j];
    c[i + j] = SENTINEL;
}

void interleaveIntArray(intArray a, intArray b, intArray c)
{
    int i, j;
    for (i = 0, j = 0; i < getIntArraySize(a) && i < getIntArraySize(b); i++, j += 2)
    {
        c[j] = a[i];
        c[j + 1] = b[i];
    }

    //If there's elements left in a or b that hasn't been interleaved due to uneven lengths add them
    for (; i < getIntArraySize(a); i++, j++) c[j] = a[i];
    for (; i < getIntArraySize(b); i++, j++) c[j] = b[i];

    c[j] = SENTINEL;


}

void sortIntArray(intArray arr)
{
    for (int i = 0; i < getIntArraySize(arr); i++)
    {
        for (int j = i + 1; j < getIntArraySize(arr); j++)
        {
            if (sortOrder == ASCENDING)
            {
                if (arr[j] < arr[i])
                {
                    swap(arr, i, j);
                }
            }

            if (sortOrder == DESCENDING)
            {
                if (arr[j] > arr[i])
                {
                    swap(arr, i, j);
                }
            }
        }
    }

    if (uniqueness == UNIQUE)
    {
        onlyUnique(arr);
    }
}

//Swap a with b, (a&b) index of elem
void swap(intArray arr, int a, int b)
{
    int temp;
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void onlyUnique(intArray arr)
{
    for (int i = 0; i < getIntArraySize(arr); i++)
    {
        for (int j = i + 1; j < getIntArraySize(arr); j++)
        {
            if (arr[i] == arr[j])
            {
                //If there's a element identical, Remove that element and fix the space by shifting every element from the right to the left
                //Do this by swapping the identical element with the right one constantly until it hits the end, and then replace the last
                //element wich was identical with the sentinel value
                int k;
                for (k = j; k < getIntArraySize(arr); k++)
                {
                    swap(arr, k, k + 1);
                }
                arr[k - 1] = SENTINEL;
            }
        }
    }
}

void setSortOrder(int o)
{
    sortOrder = o;
}

void setUniqueness(int u)
{
    uniqueness = u;
}