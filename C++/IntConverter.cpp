#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int BinarytoInt(string);

int main()
{

    cout << "Result: " << BinarytoInt("1100 1110 1010 0011");
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