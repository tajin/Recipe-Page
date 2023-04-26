// S122-Perez-CompareArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Angel Perez
// Goal: Compare 2 arrays and determine if they are the same

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Global const
const int maxArray = 100;

//Prototypes
bool areEquivalent(int [], int, int [], int);
int countOccurrences(int [], int, int );
void showArray(int [], int, string);
void getArray(int [], int&, string );


int main()
{
    int arrayA[maxArray], arrayB[maxArray];
    int n, sizeA, sizeB;

    getArray(arrayA, n, "Array A");
    sizeA = n;

    getArray(arrayB, n, "Array B");
    sizeB = n;

    showArray(arrayA, sizeA, "Array A");
    showArray(arrayB, sizeB, "Array B");


    if (areEquivalent(arrayA, sizeA, arrayB, sizeB) == true)
    {
        cout << "The arrays are:  Equivalent\n";
    }
    else
    {
        cout << "The arrays are:  Not Equivalent\n";
    }
}


//---------------------------------------------------
// User Defined Functinos
//---------------------------------------------------

// Get input
void getArray(int data[], int& n, string arrayName)
{
    do
    {   
        cout << "How many items will be there in Array A [at most 100]: ";
        cin >> n;

        if (n > 100 || n < 0)
        {
            cout << "Error - number of cells - try again\n\n";
        }
        else
        {
            break;
        }

    } while (true);


    cout << "Enter items [use space to seperate]: ";

    //Collects data
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    cout << endl << endl;
}

// Count repititions
int countOccurrences(int data[], int sizeData, int item)
{
    int counter = 0;

    for (int i = 0; i < sizeData; i++)
    {
        if (data[i] == item)
        {
            counter++;
        }
    }

    return counter;
}

// Check if arrays have equal amount of repititions
bool areEquivalent(int a[], int sizeA, int b[], int sizeB)
{   
    int c;
    
    if (sizeA != sizeB) 
    {
        return false;
    }

    for(int i = 0; i < sizeA; i++)
    {
        c = a[i];

        if (countOccurrences(a, sizeA, c) != countOccurrences(b, sizeB, c))
        {
            return false;
        }
    }

    return true;
}

// Print out the arrays
void showArray(int a[], int sizeA, string msg = "")
{
    cout << msg << endl;

    for (int i = 0; i < sizeA; i++) 
    {
        cout << a[i] << " ";
    }

    cout << endl << endl;
}

