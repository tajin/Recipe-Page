// S122-Perez-SoccerPlayerSctructs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Angel Perez
// Goal: Utilizing data structuring, input data obtained from a file into a database. Display the database with the supporting data.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//Structs ------------------------------------------------------------------------------------------
struct Player
{
	string name, team;
	int goals, assists, minutes;
	double PI;
};

//Function Prototypes ------------------------------------------------------------------------------
void makeDatabase(string fileName, vector<Player>& vdb);
void showPlayer(Player p);
void showDatabase(vector<Player> playerDatabase);
Player findMostEffectivePlayer(vector<Player> playerDatabase);
double performanceIndex(Player p);

//MAIN ----------------------------------------------------------------------------------------------
int main()
{
	vector<Player> vdb;

	makeDatabase("soccer2023.txt", vdb);
	showDatabase(vdb);

	cout << "\nMost Effective Player\n";
	showPlayer(findMostEffectivePlayer(vdb));
}

//User Defined Functions ----------------------------------------------------------------------------
void makeDatabase(string fileName, vector<Player>& vdb)
{
	ifstream myinfile;
	string fileLocation = "C++/Note Files/" + fileName;
	string strName, strTeam;
	int goals, assists;
	int minutes;

	myinfile.open(fileLocation);

	if (!myinfile)
	{
		cout << "Error - file not found";
		exit(101);
	}

	while (getline(myinfile, strName))
	{

		getline(myinfile, strTeam);
		myinfile >> goals;
		myinfile >> assists;
		myinfile >> minutes;
		myinfile.ignore();

		Player p1{ strName, strTeam, goals, assists, minutes };
		p1.PI = performanceIndex(p1);
		vdb.push_back(p1);
	}

	myinfile.close();
}

void showPlayer(Player p)
{
	cout << setw(23) << left << p.name;
	cout << setw(23) << left << p.team;
	cout << setw(10) << left << p.goals;
	cout << setw(10) << left << p.assists;
	cout << setw(10) << left << p.minutes;
	cout << setprecision(2) << fixed << p.PI << endl;
}

void showDatabase(vector<Player> playerDatabase)
{
	cout << setw(23) << left << "Player Name";
	cout << setw(23) << left << "Team";
	cout << setw(10) << left << "Goals";	   
	cout << setw(10) << left << "Assists";	   
	cout << setw(10) << left << "Minutes";     
	cout << "Perf. Index\n";

	cout << string(88, '-') << endl;

	for (int i = 0; i < playerDatabase.size(); i++)
	{
		showPlayer(playerDatabase[i]);
	}
}

//--------------------------------------------------------------------------------------------------
Player findMostEffectivePlayer(vector<Player> playerDatabase)
{
	double max = 0;
	int index = 0;

	for (int i = 0; i < playerDatabase.size(); i++)
	{
		if (performanceIndex(playerDatabase[i]) > max)
		{
			max = performanceIndex(playerDatabase[i]);
			index = i;
		}
	}

	return Player(playerDatabase[index]);
}


double performanceIndex(Player p)
{
	double PI;
	
	PI = 1000 * (p.goals + (p.assists / static_cast<double>(2))) / p.minutes;
	return PI;
}
