// groupProjectPrototyping.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Excercises
{
private:
	string name;
	int reps;
	int sets;
	int weight;
public:
	void printInfo() const;
	Excercises();
	void userInput(bool& acceptInput);
};

void Excercises::printInfo() const
{
	cout << name << endl;
	cout << sets << endl;
	cout << reps << endl;
}

Excercises::Excercises()
{
	name = "noName";
	reps = 0;
	sets = 0;
	weight = 0;
}

void Excercises::userInput(bool& acceptInput)
{
	char contInput;

	cout << "Please enter the name of your workout" << endl;
	cin >> name;

	cout << "Please enter the number of reps you will be doing" << endl;
	cin >> reps;

	cout << "Please enter the number of sets you will be preforming" << endl;
	cin >> sets;

	cout << "Please enter the weight you will be lifting" << endl;
	cin >> weight;

	cout << "Would you like to add another exercise? y/n" << endl;
	cin >> contInput;

	if (contInput == 'n')
	{
		acceptInput = false;
	}
	return;

}


int main()
{
	vector<vector<Excercises> > dailyLogs(1, vector<Excercises>());
	vector<Excercises> newWorkout;//used to pushback new vector of exercises
	Excercises newExcercise; //used to pushback new excercises for a workout session
	int workout = 0, session = 0; //used to navigate through arrays
	bool hilo = true;

	while (hilo == true)//this loop adds exercises to the current session
	{
		dailyLogs[0].push_back(newExcercise);
		dailyLogs[0][(dailyLogs[0].size() - 1)].userInput(hilo);
	}

	return 0;
}