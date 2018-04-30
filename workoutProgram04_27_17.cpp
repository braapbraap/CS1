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

int main()
{
	
	vector<vector<Excercises> > dailyLogs(2, vector<Excercises> (1));
	
	dailyLogs[0][0].printInfo(); 


	
	

    return 0;
}

