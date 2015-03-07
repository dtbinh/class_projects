// Program that illustrates the use of inheritance and polymorphism.
// Programmed By: Monisha Pulimood 
//               
// DO: Add maintenance information 
////////////////////////
//
// workerDriver.cpp
// Driver to test virtual functions 

#include <iostream>
#include "HourlyWorker.h"
#include "SalariedEmployee.h"
#include "Employee.h"

using namespace std;


int main (void)
{
  const int MaxSize = 10;
  
  // Declare a fixed size array called employeeList that can hold 10
  //     objects of type Employee
  
  // DO: Instantiate an object at the first cell of the array 
  //     as an hourly worker with parameters: 
  //     "Bob", "Smith", 40.0, 7.50, 0.2
  
  // DO: display the information for the hourly worker instantiated above
  //     using the printInfo()() function
	
  
  // DO: Instantiate an object at the second cell of the array 
  //     as a salaried employee with parameters: 
  //     "John", "Doe", 36000.0, 0.06, 0.25
  
  // DO: display the information for the salaried employee instantiated
  //     above using the printInfo() function
  
  // DO: Instantiate another object at the third cell of the array 
  //     as a salaried employee with some parameters
  
  // DO: display the information for the salaried employee instantiated
  //     above using the printInfo() function
  
  // DO: Instantiate an object at the fourth cell of the array 
  //     as an employee with some parameters
  
  // DO: display the information for the employee instantiated
  //     above using the printInfo() function
  
  
  employeeList[3] = employeeList[2];
    
  
  // DO: display the information for the object at the fourth cell
  //     using the object2string() function
  
  
  cout << endl;
  cout << "Exiting program" << endl;
  return 0;
}
