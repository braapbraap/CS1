// groupProjectPrototyping.cpp : Defines the entry point for the console application.


#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
	vector<Excercises> v;
	bool acceptInput = true;
	string name;
	int reps;
	int sets;
	int weight;
	while (acceptInput == true)
	{
		cout << "Please enter the name of your workout: " ;
		cin >> ws;
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
		cout << endl;
		if (z == "n")
		{
			acceptInput = false;
		}
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		v[i].printInfo();
	}
    return 0;
}

