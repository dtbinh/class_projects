//  complexDriver.cpp

//  Driver program to test the implementation of the Complex class
//  For use in class
//  Created by: Dr. Monisha Pulimood

#include <iostream>
#include "complex.h"

using namespace std;

const int MaxSize = 5;

int main(void)
{
    Complex comp1 (4.6, 7.8);      // some complex numbers for our demonstration
    Complex comp2 (3.2);
    Complex comp3, comp4;
    Complex compArray[MaxSize];
    float testValue;
	

    // write simple statements that test the various functions
    // for example,
    cout << "The Complex number comp1 is: " << comp1 << endl;
    cout << "The Complex number comp2 is: " << comp2 << endl;
	cout << "Input a complex number: ";
	cin >> comp3;
    cout << "The Complex number comp3 is: " << comp3 << endl;	
	
	comp4 = comp1 + comp2;
	cout << "Adding comp1 and comp2 results in: " << comp4 << endl;
	
    //Store Complex objects in an array
    for (int i=0; i<MaxSize; i++)
    {
        cout << "Input a complex number: ";
        cin >> compArray[i];
        cout << endl << "compArray[" << i << "] is: " << compArray[i] << endl;
    }
    
    cout << "Input a float value: ";
    cin >> testValue;
    
	comp3 = compArray[2] + testValue;
	cout << "Adding compArray[2] and " << testValue << " results in: "<< comp3 << endl;
    
	comp4 = testValue + compArray[3];
	cout << "Adding " << testValue << " and compArray[3] results in: " << comp4 << endl;
		
	cout << "Exiting program. Bye." << endl << endl;
}
