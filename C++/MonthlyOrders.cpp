// S122-Perez-Monthly-Orders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author: Angel Perez
// Goal: read input file, create a summary. Calculate balance, and display customer Id, name, product,
// quantity of product, price, and total balance.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // Variable
    string name, productName;
    int customerId, quantity;
    double price = 0, totalBalance = 0;


    // input
    ifstream myinfile("/tajin/Small-Projects/C++/Note Files/orders.txt");

    if (!myinfile) {
        cout << "ERROR - file not found";
        exit(1);
    }

    while (myinfile >> customerId) {
        cout << "CustID: " << customerId << ", ";
        myinfile.ignore();
        getline(myinfile, name);
        cout << "Name: " << name << endl;

        do {
        myinfile >> productName;
        if (productName == "#") {
            cout << "\tBalance:   " << totalBalance << endl << endl;
            totalBalance = 0;
            break;
        }
        myinfile >> quantity; 
        myinfile.ignore();

        myinfile >> price;

        totalBalance = totalBalance + (price * quantity);

        cout << "\t" << productName << "(" << quantity << ")  "
            << "Price:    " << price << endl;
        }while (productName != "#");
    }
    
}
