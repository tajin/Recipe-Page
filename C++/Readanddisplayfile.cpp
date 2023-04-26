// S122-Perez-stringandnums.cpp
// Author: Angel Perez
// Goal: Read records from a disk file. Each record contains a person name and age
//		 The app finds and reports the name and age the youngest and oldest person in the group.
// ---------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	//variable decloration
	string name, nameOldest, nameYoungest;
	int    age, ageOldest, ageYoungest;

	//input
	ifstream myinfile("/tajin/Small-Projects/C++/Note Files/namesandage.txt");

	if (!myinfile) {
		cout << "There was an ERROR";
		exit(1);
	}

	while (getline(myinfile, name)) {
		myinfile >> age;
		myinfile.ignore();

		cout << "I read from disk => " << age << "\t" << name << endl;

	}

	myinfile.close();

	//Output
	cout << "\nAll Done\n";

}
