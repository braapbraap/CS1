// groupProjectPrototyping.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
	void userInput();
};

void Excercises::printInfo() const
{
	cout << name << ": ";
	cout << reps << " reps, ";
	cout << sets << " sets, at ";
	cout << weight << "lbs.\n\n";
}

Excercises::Excercises()
{
	name = "noName";
	reps = 0;
	sets = 0;
	weight = 0;
}


void Excercises::userInput()
{
	ofstream outFile;
	outFile.open("savedata.txt", std::ios_base::app);

	cout << "Please enter the name of the new exercise: ";
	cin >> ws;
	getline(cin, name);

    outFile << name << endl;

	cout << "Please enter the number of reps you will be doing: ";
	cin >> reps;
	outFile << reps << endl;

	cout << "Please enter the number of sets you will be preforming: ";
	cin >> sets;
	outFile << sets << endl;

	cout << "Please enter the weight you will be lifting: ";
	cin >> weight;
	outFile << weight << endl;



	outFile.close();

	return;

}

void like2Continue(bool& acceptInput)
{
	char contInput = 'y';
	cout << "Would you like to continue? y/n : ";
	cin >> contInput;

	if (contInput == 'n')
	{
		acceptInput = false;
	}

	cout << "\n----------------------------------------------- \n";
}

int main()
{
	vector<vector<Excercises> > dailyLogs(1, vector<Excercises>());
	vector<Excercises> newWorkout;//used to pushback new vector of exercises
	Excercises newExcercise; //used to pushback new excercises for a workout session
	int workout = 0, exercises = 0; //used to navigate through arrays
	bool runProgram = true;
	int menu = -1;

	while (runProgram == true)
	{
		cout << "----------Welcome to GainzTracker!----------\n\n";
		cout << "*Would you like to log your workout or view a previous workout?* \n\n";
		cout << "1.  Log a new workout\n";
		cout << "2.  View a previous workout\n";
		cout << "3.  Quit GainzTracker\n\n";

		cout << "Enter the corresponding number: ";
		cin >> menu;
		cout << "\n\n";

		switch (menu)
		{
		default:
			cout << "Invalid Selection. Please try again\n\n";
			break;

		case 0:
			runProgram = false;
			break;

		case 1:
			while (runProgram == true)//this loop adds exercises to the current session
			{
				dailyLogs[workout].push_back(newExcercise);
				dailyLogs[workout][(dailyLogs[0].size() - 1)].userInput();
				like2Continue(runProgram);
				cout << "The exercises for this workout session are: \n";
				for (int i = 0; i < (dailyLogs[workout].size()); i++)
				{
					dailyLogs[workout][i].printInfo();
				}

			}
			if (runProgram == false){
            ofstream endWorkout;
            endWorkout.open("savedata.txt", std::ios_base::app);
            endWorkout << "!" << endl;
            endWorkout.close();}

			runProgram = true;
			break;

		case 2:
			while(runProgram == true)
			{
				cout << "Which session would you like to view: \n";
				for (int i = 0; i < (dailyLogs.size() - 1); i++)
				{
					cout << "Session #" << i + 1 <<  "\n";
				}
				cin >> workout;
				cout << endl;
				cout << "Okay. Here is list of exercises for session " << workout << ": \n";
				for (int i = 0; i < dailyLogs[workout - 1].size(); i++)
				{
					dailyLogs[workout - 1][i].printInfo();
				}
				like2Continue(runProgram);
			}
		}
		dailyLogs.push_back(newWorkout);
		workout = (dailyLogs.size() - 1);
		menu = -1;

	}
}
