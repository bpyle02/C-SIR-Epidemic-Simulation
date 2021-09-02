/*
	Brandon Pyle
	SIR Epidemic Simulation

	This program is a simple customizable epidemic simulation that uses the SIR model
*/

//Include statements
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

//Function prototypes

int main()
{
	//The following block of code creates the title box in the command line
	for (int i = 0; i < 50; i++)
		cout << "*";
	cout << endl << setw(49) << left << "*" << right << "*" << endl;
	cout << "*                  Brandon Pyle                  *" << endl;
	cout << "*            SIR Epidemic Simulation             *";
	cout << endl << setw(49) << left << "*" << right << "*" << endl;
	for (int i = 0; i < 50; i++)
		cout << "*";

	cout << endl << endl;

	//Variable Declarations
	int numDays;
	int population;
	double infectionRate = 0.0002; //Percent of other people a person can infect
	double recoveryRate = 12; //In days

	cout << "Enter the length of the simulation in days: ";
	cin >> numDays;

	cout << endl << "Enter the population number for the simulation: ";
	cin >> population;

	if (population > 5000)
		cout << "WARNING: Numbers greater than 5000 may result in incorrect or inaccurate results." << endl;
	else
		cout << endl;

	vector<double> S(population, 0.0); //Number of Susceptible People
	vector<double> I(population, 0.0); //Number of Infected People
	vector<double> R(population, 0.0); //Number of Removed People

	I[0] = 1; //Starts the simulation with 6 infected people
	S[0] = population - I[0]; //Initial number of susceptible people
	R[0] = 0; //Initial number of removed people

	cout << setw(5) << right << "Day";
	cout << setw(13) << right << "Susceptible";
	cout << setw(10) << right << "Infected";
	cout << setw(9) << right << "Removed" << endl;

	for (int i = 0; i < numDays; i++)
	{
		cout << setw(5) << right << i + 1;
		cout << setw(13) << right << fixed << setprecision(0) << S[i];
		cout << setw(10) << right << fixed << setprecision(0) << I[i];
		cout << setw(9) << right << fixed << setprecision(0) << R[i] << endl << endl;

		S[i + 1] = S[i] - infectionRate * S[i] * I[i];
		I[i + 1] = I[i] + infectionRate * S[i] * I[i] - I[i] / recoveryRate;
		R[i + 1] = R[i] + I[i] / recoveryRate;
	}
}