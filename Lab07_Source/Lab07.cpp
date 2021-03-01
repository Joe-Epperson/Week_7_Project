// Joe Epperson, IV
// jee4cf@umsystem.edu
// 3/01/2021
// CS201L Lab 07

#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include <ios>
using namespace std;


double GetMiles();

double GetGallons();

double GetMPG(vector<double> miles, vector<double> gallons);

int main()
{
	vector<double> milesTotal;
	vector<double> gallonsTotal;
	double tempMiles;
	double tempGallons;
	char usrInput = 'r';
	while (true)
	{
		try
		{
			cout << "Would you like to enter a tank of gas? Input any character to contniue. (q) to quit." << endl;
			cin >> usrInput;
			usrInput = toupper(usrInput);
			if (usrInput == 'Q')
			{
				break;
			}
			else 
			{
				// Getting values for miles and gallons
				tempMiles = GetMiles();
				tempGallons = GetGallons();
				
				// Seperating the functions just in case an error is thrown, that way no invlaid input is stored into the vectors
				milesTotal.push_back(tempMiles);
				gallonsTotal.push_back(tempGallons);
			}
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
		}
	}
	double totalMPGVal;
	try
	{
		totalMPGVal = GetMPG(milesTotal, gallonsTotal);
		cout << "Your total Miles Per Gallon is : " << totalMPGVal << endl;
	}
	catch (runtime_error& excpt)
	{
		cout << excpt.what() << endl;
	}
}

double GetMiles()
{
	double milesVal;
	cout << "Enter the number of miles for this trip: " << endl;
	cin >> milesVal;
	//Throwing an error depending on input from the user
	if (milesVal <= 0)
	{
		throw runtime_error("Miles cannot be less than or equal to zero.");
	}
	else if (!cin)
	{
		throw runtime_error("Invalid input received, you must enter a decimal number.");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return milesVal;
}

double GetGallons()
{
	double gallonsVal;
	cout << "Enter the number of gallons for this trip: " << endl;
	cin >> gallonsVal;
	//Throwing an error depending on input from the user
	if (gallonsVal <= 0)
	{
		throw runtime_error("Gallons cannot be less than or equal to zero.");
	}
	else if (cin.fail())
	{
		throw runtime_error("Invalid input received, you must enter a decimal number.");
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return gallonsVal;
}

double GetMPG(vector<double> miles, vector<double> gallons)
{
	// Throwing an error if one of the vectors has no values in it
	if ((miles.size()) == 0 || (gallons.size() == 0))
	{
		throw runtime_error("No values recorded, MPG is nan.");
	}

	double totalMiles = 0;
	double totalGallons = 0;
	double totalMPG;

	// Calculating for total miles and gallons
	for (int i = 0; i < (miles.size()); ++i)
	{
		totalMiles += miles.at(i);
	}
	for (int i = 0; i < (gallons.size()); ++i)
	{
		totalGallons += gallons.at(i);
	}

	totalMPG = totalMiles / totalGallons;

	return totalMPG;
}