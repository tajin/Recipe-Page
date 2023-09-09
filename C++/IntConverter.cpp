// Convert int into binary and hex (Unsigned)
// Convert Binary into decimal and hex (Unsigned)
// Convert hex into Binary
// Convert int to hex (signed)
// Convert hex to int (signed)
// Convert int to Binary (signed)
// Add hex + hex

// Function == string(Binary) return Int
// Fuction == Int return string(Hex)
// Fuction == string(Hex) string(Hex) return sum of both hex as string(Hex)
//   Constraint each hex input as long as 1,000 digits
// Function == string(Binary) string(Binary) return Binary - Binary as string(Binary)
//   Find the smaller number first and then subtract from bigger number
//   Result should be positive

#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// Useful functions
string InttoBinary(int);

// Required functions
int BinarytoInt(string);
string InttoHex(int);
string HexplusHex(string, string);
string BinaryMinusBinary(string, string);

int main()
{

    cout << "Int to Binary: " << InttoBinary(-72) << endl;
    cout << "Result: " << BinarytoInt("0000000000001010") << endl;
    cout << "Int to Hex: " << InttoHex(21);
    cout << "Hex1 plus Hex2: " << HexplusHex("6A", "4B");
}

string InttoBinary(int num)
{
    int quotient = abs(num), remainder, b;
    bool isNegative = false, toggle = true;
    string Binary;
    char c = '0';


    while (quotient > 0)
    {
        remainder = quotient % 2;
        c = '0' + remainder;
        Binary += c;
        quotient = quotient / 2;
    }

    if (num < 0) 
    {
        isNegative = true;
        Binary += '0';
    }
    reverse(Binary.begin(), Binary.end());


    if (isNegative == true)
    {
        for (int i =0; i < Binary.length(); i ++)
        {
            if (Binary[i] ==  '1'){Binary[i] = '0';}
            else {Binary[i] = '1';}
        }

        for (int i = Binary.length()-1; i >-1; i --)
        {
            b = Binary[i] - '0';

            if (b+toggle > 1)
            {
                Binary[i] = '0';
            }
            else
            {
                c = '0' + (b+toggle);
                Binary[i] = c;
                toggle = false;
            }
        }
    }


    return Binary;
}

int BinarytoInt(string input)
{
    int sum = 0, length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (input[i] == '1')
        {
            sum += pow(2, (length - i) - 1);
        }
    }
    return sum;
}

string InttoHex(int num)
{
    string Hex, alphabet = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int quotient = num, remainder;
    char c = '0';

    while (quotient > 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
        {
            c = '0' + remainder;
        }
        else
        {
            c = alphabet[remainder - 9];
        }
        Hex += c;
        quotient = quotient / 16;
    }

    reverse(Hex.begin(), Hex.end());

    return Hex;
}


string HexplusHex(string hex1, string hex2)
{
    return "YEs";
}
