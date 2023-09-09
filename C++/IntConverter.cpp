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
#include <algorithm>
using namespace std;

// Useful functions
string InttoBinary(int);
string BinarytoHex(string);
string HextoBinary(string);

// Required functions
int BinarytoInt(string);
string InttoHex(int);
string HexplusHex(string, string);
string BinaryMinusBinary(string, string);

int main()
{
    cout << "65 in Binary is " << InttoBinary(65)
         << " and 65 in unsigned Hex is: " << InttoHex(65) << endl;
    cout << "409 in Binary is " << InttoBinary(409)
         << " and 409 in unsigned Hex is: " << (409) << endl;
    cout << "16385 in Binary is " << InttoBinary(16385)
         << " and 16385 in unsigned Hex is: " << InttoHex(16385) << endl
         << endl;

    cout << "The unsign decimal for 0011 0101 1101 1010 is "
         << BinarytoInt("0011010111011010") << " and Hex is"
         << BinarytoHex("0011010111011010") << endl;
    cout << "The unsign decimal for 1100 1110 1010 0011 is "
         << BinarytoInt("1100111010100011") << " and Hex is"
         << BinarytoHex("1100111010100011") << endl;
    cout << "The unsign decimal for 1111 1110 1101 1011 is "
         << BinarytoInt("1111111011011011") << " and Hex is"
         << BinarytoHex("1111111011011011") << endl
         << endl;

    cout << "The Binary of A4693FBC is "
         << "10100100011010010011111110111100" << endl
         << HextoBinary("A4693FBC") << endl;
    cout << "The Binary of B697C7A1 is "
         << "10110110100101111100011110100001" << endl;
    cout << "The Binary of 2B3D9461 is "
         << "00101011001111011001010001100001" << endl
         << endl;

    cout << "The hex of -21 is "
         << "-15" << endl;
    cout << "The hex of -45 is "
         << "-2D" << endl
         << endl;

    cout << "The Decimal of 6Bf9 is "
         << "27641" << endl;
    cout << "The Decimal of C123 is "
         << "49443" << endl
         << endl;

    cout << "The 8-bit Binary of -72 is" << InttoBinary(-72) << endl;
    cout << "The 8-bit Binary of -98 is" << InttoBinary(-98) << endl;
    cout << "The 8-bit Binary of -26 is" << InttoBinary(-26) << endl
         << endl;

    cout << "The sum of 6B4 + 3FE is " << HexplusHex("6B4", "3FE") << endl;
    cout << "The sum of A49 + 6BD is " << HexplusHex("A49", "6BD") << endl
         << endl;

    cout << "Using a function, the int of the 16-bit integer 0101 0000 0100 0111 is "
         << BinarytoInt("0101000001000111") << endl
         << endl;
    cout << "Using a function, the Hex of the integer 4573 is "
         << InttoHex(4573) << endl
         << endl;
    cout << "Using a function, the sum of the Hex values 9DB and 4AB is "
         << HexplusHex("9DB", "4AB") << endl
         << endl;
    cout << "Using a function, the result of 00000101 - 10001000 is "
         << BinaryMinusBinary("00000101", "10001000") << endl
         << endl;
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
    /*
    while(Binary.length() <4)
    {
        Binary += '0';
    }
    */

    reverse(Binary.begin(), Binary.end());

    if (isNegative == true)
    {
        for (int i = 0; i < Binary.length(); i++)
        {
            if (Binary[i] == '1')
            {
                Binary[i] = '0';
            }
            else
            {
                Binary[i] = '1';
            }
        }

        for (int i = Binary.length() - 1; i > -1; i--)
        {
            b = Binary[i] - '0';

            if (b + toggle > 1)
            {
                Binary[i] = '0';
            }
            else
            {
                c = '0' + (b + toggle);
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
    string sum, alphabet = "0123456789ABCDEFG";
    int a, b, quotient = 0, remainder = 1, i = hex1.length() - 1;
    char c;

    while ((remainder >= 1) or (quotient > 0))
    {
        if (isdigit(hex1[i]))
        {
            a = hex1[i] - '0';
        }
        else
        {
            a = (int(hex1[i]) - 64) + 9;
        }

        if (isdigit(hex2[i]))
        {
            b = hex2[i] - '0';
        }
        else
        {
            b = (int(hex2[i]) - 64) + 9;
        }

        if (i < 0)
        {
            a = 0;
            b = 0;
        }

        remainder = ((a + b) + quotient) % 16;
        quotient = ((a + b) + quotient) / 16;

        if (remainder > 9)
        {
            sum += alphabet[remainder];
        }
        else
        {
            sum += '0' + remainder;
        }

        i--;
    }

    sum.pop_back();
    reverse(sum.begin(), sum.end());

    return sum;
}

string BinaryMinusBinary(string Bin1, string Bin2)
{
    int a, b, small, big;
    string result;

    a = BinarytoInt(Bin1);
    b = BinarytoInt(Bin2);

    if (a > b)
    {
        result = InttoBinary(a - b);
    }
    else
    {
        result = InttoBinary(b - a);
    }

    return result;
}

string BinarytoHex(string Bin)
{
    int num = BinarytoInt(Bin);
    string result = InttoHex(num);

    return result;
}

string HextoBinary(string Hex)
{
    string Bin, result;
    int current;

    for (int i = 0; i < Hex.length() - 1; i++)
    {
        if (isdigit(Hex[i]) == false)
        {
            current = (int(Hex[i]) - 64) + 9;
        }
        else
        {
            current = Hex[i] - '0';
        }

        Bin = InttoBinary(current);

        result += Bin;
    }

    return result;
}
