// S122-Perez-SequentialandBinarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Angel Perez
// Goal: Use a sequential and Binary Search to display values of a csv file depending on the key of user input
//       Count how many operations it takes to find the value

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int populateStockMarkeyDatabase(vector<string>&, vector<string>&);
int myLinearSearch(string, vector<string> , int&);
int myBinarySearch(string, vector<string> , int&);

int main()
{
    vector<string> symbol;
    vector<string> company;

    int counter = 0, index;
    string key;

    cout << "Total Records: " << populateStockMarkeyDatabase(symbol, company) << endl;

    do {
        counter = 0;
        cout << "\nSEQ - Enter ticker symbol [XXX to end]: ";
        cin >> key;
        transform(key.begin(), key.end(), key.begin(), toupper);

        if (key == "XXX")
        {
            break;
        }

        index = myLinearSearch(key, symbol, counter);
        cout << "\tCompany: "<< setw(5) << company[index] << endl;
        cout << "\tCost: " << setw(5) << counter << " operations" <<endl;

    } while (true);

    cout << endl;

    do {
        counter = 0;
        cout << "\nBIN - Enter ticker symbol [XXX to end]: ";
        cin >> key;
        transform(key.begin(), key.end(), key.begin(), toupper);

        if (key == "XXX")
        {
            break;
        }

        index = myBinarySearch(key, symbol, counter);
        cout << "\tCompany: " << setw(5) << company[index] << endl;
        cout << "\tCost: " << setw(5) << counter << " operations" << endl;

    } while (true);

    cout << "\nAll Done";
}



int populateStockMarkeyDatabase(vector<string>& vSymbol, vector<string>& vCompany) 
{
    
    int index, counter = 0;
    string stock, data;
    ifstream myinfile;
    myinfile.open("C++/Note Files/stockTickerSymbol-Windows.csv");

    if (!myinfile)
    {
        cout << "Error - file not found";
        exit(101);
    }

    while (myinfile)
    {
        getline(myinfile, data, ',');
        vSymbol.push_back(data);

        getline(myinfile, data, '\n');
        vCompany.push_back(data);

        counter++;
    }

    return counter;
}

int myLinearSearch(string symbol, vector<string> v, int& counter)
{
    int index;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == symbol)
        {
            index = i;
            return index;
        }
        counter++;
    }

    return -1;
}

int myBinarySearch(string symbol, vector<string> v, int& counter)
{
    int position = -1,
        index,
        max = v.size()-1,
        min = 0;
    
    bool found = false;

    while (!found && min <= max)
    {
        index = (max + min) / 2;

        if (v[index] == symbol)
        {
            found = true;
            position = index;
        }
        else if (v[index] > symbol)
        {
            max = index - 1;
        }
        else
        {
            min = index + 1;
        }
        counter++;
    }

    return position;
}



