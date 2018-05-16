// groupProjectPrototyping.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Time
{
private:
    int m;
    int d;
    int y;
public:
    Time(int month, int day, int year);
    void getTime();
    void printTime();
};


Time::Time(int month, int day, int year)
{
    m = month;
    d = day;
    y = year;
}


void Time::printTime()
{
    cout << m << "/" << d << "/" << y << endl;
}


class Excercises
{
private:
	string Ename;
	int Ereps;
	int Esets;
	int Eweight;

public:
	Excercises(string n, int r, int s, int w);
	void printInfo();
};

Excercises::Excercises(string n, int r, int s, int w)
{
	Ename = n;
	Ereps = r;
	Esets = s;
	Eweight = w;
}

void Excercises::printInfo()
{
	cout << endl;
	cout << "The excercise is: " << Ename << endl;
	cout << "The number of sets is: " << Esets << endl;
	cout << "The number of reps is: " << Ereps << endl;
	cout << "The amount of weight is: " << Eweight << endl;
}






int main()
{
    vector<Time> t;//vector for time class
    int y, z;
    int dateChoice;
    string anyKey;

	vector<Excercises> v;
	bool acceptInput = true;
	string name;
	int reps;
	int sets;
	int weight;




    char userDecision; //User navigation through the menu
    bool runProgram = true; //Main Program loop



    cout << "----------Welcome to GainzTracker!----------\n\n";
    while (runProgram == true)
	{
        cout << "\n*Would you like to log your workout or view a previous workout?* \n\n";
        cout << "1.  Log a new workout\n";
        cout << "2.  View a previous workout\n";
        cout << "3.  Quit GainzTracker\n\n";

        cout << "Enter the corresponding number: ";
        cin >> userDecision;
        cout << endl;

        if (userDecision == '1')
		{
            cout << "----------Exercise Input----------\n\n";

            SYSTEMTIME time;
            GetLocalTime(&time);
            int month = time.wMonth;
            int day = time.wDay;
            int year = time.wYear;

            Time date(month, day, year);


            t.push_back(date);

			while (acceptInput == true)
			{
				cout << "Please enter the name of your workout: " ;
				cin >> ws;	//This removes the white space when inputing two word i.e. bench press
				getline(cin, name);
				cout << "\nPlease enter the number of reps you will be doing: ";
				cin >> reps;
				cout << "\nPlease enter the number of sets you will be preforming: ";
				cin >> sets;
				cout << "\nPlease enter the weight you will be lifting: ";
				cin >> weight;
				Excercises E(name, reps, sets, weight);
				v.push_back(E);

				cout << "\nWould you like to do another excercise? (y for yes, n for no): ";
				string z;
				cin >> z;
				cout << "----------------------------------" << endl;
				if (z == "n")
				{
					acceptInput = false;
				}
			}
        }
        else if (userDecision == '2')
		{
            cout << "--------View a Previous Workout--------\n\n";

            cout << "Please choose a date\n\n";

            for (int x = 0; x < t.size(); x++)
            {
                y = x + 1;
                cout << y << ". ";
                t[x].printTime();
            }
            cout << "\n";
            cin >> dateChoice;

            cout << "\nNow showing workout #" << dateChoice << endl;
            z = --y;
            v[z].printInfo();
            cout << "\nPress any key to return to the main menu";
            cin >> anyKey;
        }
        else
            runProgram = false;
    }
    cout << "----------Thank you for using GainzTracker!----------";

    return 0;
}
