// Program that illustrates the use of inheritance and polymorphism.
// Programmed By: Monisha Pulimood 
//               
// DO: Add maintenance information 
////////////////////////
//
// workerDriver.cpp

#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Employee.h"

using namespace std;


int main (void)
{
	cout << "Instantiating objects" << endl;
	Employee JohnDoe ("John Doe", "345678901");
	cout << endl;
	cout << endl;
	SalariedEmployee JohnSmith("John Smith", "123456789", 0.05, 129050, 0.25);
	cout << endl;
	cout << endl;
	HourlyEmployee JaneDoe ("Jane Doe", "567890123", 35, 14, 0.10);
	cout << endl;
	
	cout << "Printing data for objects" << endl;
	cout << JohnDoe.printInfo () << endl;
	cout << JohnSmith.printInfo () << endl;
	cout << JaneDoe.printInfo () << endl;
	
	cout << endl;
	cout << "Exiting program. Bye!" << endl << endl;
	return 0;
}
