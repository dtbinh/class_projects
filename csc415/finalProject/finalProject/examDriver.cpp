/*#######################################################################
 *  driver file - examDriver.cpp
 *
 *  Programmed By: Monisha Pulimood for use in CSC 415
 *  Description: Program that tests the implementation for
 *                Final Exam Fall 2013
 *
 *#######################################################################*/


#include "roster.h"
#include "person.h"
#include "defendant.h"
#include "judge.h"
#include "docket.h"

#include <iostream>
#include <fstream>

int main (void)
{
	   
	roster sessionS12(2000), sessionF12(2000);
    
    // the inputFmFile() method reads data from the csv file into the roster
    sessionS12.inputFmFile();
    
    
    // the display method returns a string that displays all judges and defendants
    // along with their docket information (i.e. the records for their arrests)
    cout << "The data in the sessionS12 roster is: " << endl;
    cout << sessionS12.printInfo() << endl;
    
    sessionF12 = sessionS12;

    judge JudgeEaston;
    cin >> JudgeEaston; // add relevant data for the Judge object
    sessionF12.add(&JudgeEaston);
    
    //cout << "im in here let me out" << endl;
    
    cout << "After adding JudgeEaston to sessionF12, the data in the sessionS12 roster is: " << endl;
    cout << sessionS12.printInfo() << endl;
    
    cout << "After adding JudgeEaston to sessionF12, the data in the sessionF12 roster is: " << endl;
    cout << sessionF12.printInfo() << endl;
    
    
    roster sessionS13 (sessionF12);
    
    judge JudgeCarter;
    sessionS13.add(&JudgeCarter);
    
    cout << "After adding JudgeCarter to sessionS13, the data in the sessionF12 roster is: " << endl;
    cout << sessionF12.printInfo() << endl;
    
    cout << "After adding JudgeCarter to sessionS13, the data in the sessionS13 roster is: " << endl;
    cout << sessionS13.printInfo() << endl;
    
    
    defendant JohnDoe;
    cin >> JohnDoe; // add relevant data for the Defendant object, including
    // docket information
    
    sessionS13.add(&JohnDoe);
    
    cout << "After adding JohnDoe to sessionS13, the data in the sessionS12 roster is: " << endl;
    cout << sessionS12.printInfo() << endl;
    
    cout << "After adding JohnDoe to sessionS13, the data in the sessionF12 roster is: " << endl;
    cout << sessionF12.printInfo() << endl;
    
    cout << "After adding JohnDoe to sessionS13, the data in the sessionS13 roster is: " << endl;
    cout << sessionS13.printInfo() << endl;
    
    return 0;
}

