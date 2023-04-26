// S122-Perez-Security-Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Angel Perez
// Goal: Divide input into 2 parts (A,B) then add up the numbers in A and then the numbers in B. (ex a = 123, add 1 + 2 + 3)
//       Then you you add the sum of a and b. You then add the digits of the sum as done previously. When 1 digit is left, 
//       Append the final digit to the original number as a new secure value.

#include <iostream>
using namespace std;

int main()
{
    int originalValue,
        a,    b,   c, 
        addA, addB,addC,
        secureValue;

    cout << "Enter a six-digit integer: ";
    cin >> originalValue;

    a = originalValue/1000;
    b = originalValue % 1000;

    addA = (a/100) + ((a % 100) / 10) + (a%10);
    addB = (b / 100) + ((b % 100) / 10) + (b % 10);

    c = addA + addB;
    addC = (c % 10) + (c / 10);

    secureValue = (originalValue * 10) + addC;
    cout << "Original Number: " << originalValue << endl;
    cout << " Secured number: " << secureValue << endl;

}

