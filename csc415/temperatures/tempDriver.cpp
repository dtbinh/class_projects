//  Program to manage temperatures for a month in a 2-d array
//  Programmed by: Dr. Monisha Pulimood

//  Last modified on: September 12, 2013
//  Description: To demonstrate functions, arrays and file i/o
//  Filename: tempDriver.cpp



#include <iostream>
#include <fstream>
#include <cmath>

#include "tempFns.h"

using namespace std;


int main (void)
{
	// Declare an array of type double called temperatures 
	//     Use the constant MaxDays for the number of rows
	//     and the constant MaxTimes for the number of temperatures
	
	double temperatures [MaxDays][MaxTimes];
	
	int numDays = 0; // holds number of days in the month 
	int numTimes = 0; // holds number of times the temperature is measured each day
	bool success = true; 
	
	// Read the data from a file
	success = inputFmFile (temperatures, numDays, numTimes);

	if (success)
	{
				
		// Call the function tempAvg () here 
		tempAvg (temperatures, numDays, numTimes); 
		
		// Display the data on the screen
		cout << "Temperature data after calculating averages." << endl;
		outputData (temperatures, numDays, numTimes+1);
		cout << endl;

		//Display average temperature
		cout <<"Average temperature :" << endl;
                stdAvg (temperatures, numDays, numTimes);
		
		// Write data to a file - only temperatures, not averages
		outputToFile (temperatures, numDays, numTimes);
		
	}
	else 
		cout << "Sorry the file contains invalid values. Please try again." << endl;

	cout << "Bye!" << endl;
	return 0;
	
}
