// S122-Perez Gradebook App.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Angel Perez
// Goal: Creat a local database for student name, age, grade, and ID number

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main()
{
    int numHolder;
    string studentName, anotherStudent;
    bool loop = true;
    vector<string> names;
    map<string, int> grade;
    map<string, int> age;
    map<string, int> studentID;

    while (loop == true) {
        cout << "Enter the name:  ";
        cin  >> studentName;
        names.push_back(studentName);

        cout << "Enter grade:     ";
        cin  >> numHolder;
        grade[studentName] = numHolder;

        cout << "Enter age:       ";
        cin  >> numHolder;
        age[studentName] = numHolder;

        cout << "Enter ID Number: ";
        cin  >> numHolder;
        studentID[studentName] = numHolder;
        cout << endl;

        cout << "Would you like to enter another student? (y/n): ";
        cin  >> anotherStudent;
        if (anotherStudent == "n") {
            loop = false;
        };
        cout << endl;
    };

    for (int j = 0; j < names.size(); j++){

        cout << "The name is:       " << names[j] << endl;
        cout << "The grade is:      " << grade[names[j]]  << endl;
        cout << "The age is:        " << age[names[j]] << endl;
        cout << "The student ID is: " << studentID[names[j]] << endl << endl;

    };
};