//  Program to manage temperatures for a month in a 2-d array
//  Programmed by: Dr. Monisha Pulimood

//  Last modified on: September 12, 2013
//  Description: To demonstrate functions, arrays and file i/o - Step 1
//  Filename: s1tempDriver.cpp



#include <iostream>

using namespace std;


int main (void)
{
	
    double temp1, temp2, temp3, tempAvg;
	
    cout << "Input 3 temperature values: ";
    cin >> temp1 >> temp2 >> temp3;
    
    // Calculate the average temperature
    tempAvg = (temp1 + temp2 + temp3)/3;
    cout << "The average temperature is " << tempAvg << endl;

	cout << "Bye!" << endl;
	return 0;
	
}
