//  Program to manage temperatures for a month in a 2-d array
//  Programmed by: Dr. Monisha Pulimood

//  Last modified on: September 12, 2013
//  Description: To demonstrate functions, arrays and file i/o
//  Filename: tempFns.cpp


#include <iostream>
#include <fstream>
#include <cmath>

#include "tempFns.h"

using namespace std;


void tempAvg (double tempArray [][MaxTimes], int days, int times)
{
	double total = 0.0, average = 0.0;
	
	if (days >= 28 && days <= MaxDays && times < MaxTimes)
	{
		// calculate daily averages
		for (int i=0; i < days; i++)
		{
			total = 0.0;
			for (int j=0; j < times; j++)
				total += tempArray [i][j];
			tempArray[i][times] = total / times;
		}
	}	
}

void stdAvg (double tempArray [][MaxTimes], int &days, int &times)
{
  double average = 0.0;
  double total = 0.0;
  double devTotal = 0.0;
  for (int i=0; i<days; i++)
  {
    total += tempArray [i][times];
  }
  average = total;
  average = average/days;

  cout << average << endl;
  
  for (int i=0; i<days; i++)
    {
      double temp = (tempArray[i][times] - average);
      devTotal += pow(temp, 2);
    }

  devTotal = devTotal/(days-1);
  double deviation = sqrt(devTotal);
  cout << "Standard deviation :" << endl;
  cout << deviation << endl;
}


bool inputFmFile (double tempArray [][MaxTimes], int &days, int &times)
{
    //int days, times;
    bool worked = true;
	string inFileName;
	ifstream inStr;
	
	do 
	{
		cout << "Enter name of file to read from: ";
		cin >> inFileName;
		
		inStr.open (inFileName.c_str());
		if (inStr.fail())
		{
			cerr << "Error opening file. Try again." << endl;
			inStr.clear();
			worked = false;
		}
		else 
			worked = true;
		
	} while (!worked);
	
	inStr >> days >> times;
	
	worked = true;
	if (days < MinDays || days > MaxDays || times <=0 || times >= MaxTimes)
		worked = false;
	else 
	{
	
		// Use a for loop to enter data into the array
		
		for (int i=0; i < days; i++)
			for (int j=0; j < times; j++)
				inStr >> tempArray [i][j];
		
		// Initialize daily averages to 0, i.e. set the last column to 0 
		for (int i=0; i < days; i++)
			tempArray [i][times] = 0.0;
	}
	inStr.close();
	return worked;
}



void outputData (double tempArray [][MaxTimes], int days, int times)
{
    //int days, times;
	cout << endl << "The temperatures for the month are : " << endl;
	cout.setf(ios::fixed);
	cout.precision (2);
    
	// Use a for loop to display the temperatures
	cout << setw(9) << "Day";
	for (int i=0; i < times-1; i++)
		cout << setw(8) << "Temp" << i+1;
    
	cout << setw(8) << "Average" << endl;
	
	for (int i=0; i < days; i++)
	{
		cout << setw(9) << i+1;
		for (int j=0; j < times; j++)
			cout << setw(9) << tempArray [i][j];
		cout << endl;
	}
	
}
	

void outputToFile (double tempArray [][MaxTimes], int days, int times)
{
	bool worked = false;
	string outFileName;
	ofstream outStr;
	
	do 
	{
		cout << "Enter name of file to write to: ";
		cin >> outFileName;
		
		outStr.open (outFileName.c_str());
		if (outStr.fail())
		{
			cerr << "Error opening file. Try again." << endl;
			outStr.clear();
			worked = false;
		}
		else 
			worked = true;
		
	} while (!worked);
	
	
	outStr << days << " " << times << endl;
	outStr << endl;	
		
	// Use a for loop to write out the temperatures
	
	for (int i=0; i < days; i++)
	{
		for (int j=0; j < times; j++)
			outStr << setw(9) << tempArray [i][j];
		outStr << endl;
	}
	
	outStr.close();

}

