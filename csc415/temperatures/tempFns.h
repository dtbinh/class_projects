//  Program to manage temperatures for a month in a 2-d array
//  Programmed by: Dr. Monisha Pulimood

//  Last modified on: September 12, 2013
//  Description: To demonstrate functions, arrays and file i/o
//  Filename: tempFns.h


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


// Declare constants for the maximum and minimum number of values that can be  
//     stored in the array

const int MaxDays = 31;  // Maximum number of days in a month
const int MinDays = 28;  // Maximum number of days in a month
const int MaxTimes = 5;  // Maximum number of times temperature is measured in 
                         // a day plus one column to hold the daily average


//------------------------------------------------------------------------------
//
//  Function: tempAvg ()
//
//	Parameters:	
//    input double; array of temperatures
//    input integer; number of days for that month
//    input integer; number of times temperature is measured each day 
//                    for that month
//    
//	Pre-condition: input array must be populated with valid temperatures;
//                 input number of days must be between 28 & MaxDays (inclusive)
//                 input number of times must be at least one less than MaxTimes
//  Post-condition: The daily average temperature is calculated and stored
//                  in the last column of the array 
//------------------------------------------------------------------------------

void tempAvg (double [][MaxTimes], int, int);

//------------------------------------------------------------------------------
//
//  Function: stdAvg () to get the standard devation and average from data.
//
//    parameters:
//  output double; average temperature for the month
//  output double; standard deviation of the temperatures
//  
//  pre-condition: is fed a populated array
//  post-condition: output for average and standard deviation is provided
//
//-----------------------------------------------------------------------------

void stdAvg (double [][MaxTimes], int&, int&);

//------------------------------------------------------------------------------
//
//  Function: inputFmFile () to read temperature data from a file
//
//	Parameters:	
//    output double; array of temperatures
//    output integer; number of days for that month
//    output integer; number of times temperature is measured each day 
//                    for that month
//    
//	Pre-condition: 
//  Post-condition: array is populated with valid temperatures;
//                  number of days is populated if it is between MinDays and
//                            MaxDays (inclusive)
//                  number of times is populated if it is between 0 and MaxTimes
//                  function returns true if number of days and times are valid;
//                            false otherwise
//------------------------------------------------------------------------------

bool inputFmFile (double [][MaxTimes], int&, int&);



//------------------------------------------------------------------------------
//
//  Function: outputData () to display temperatures and daily averages
//
//	Parameters:	
//    input double; array of temperatures
//    input integer; number of days for that month
//    input integer; number of times temperature is measured each day 
//                    for that month
//    
//	Pre-condition: input array must be populated with valid temperatures;
//                 input number of days must be between 28 & MaxDays (inclusive)
//                 input number of times must be between 0 and MaxTimes 
//  Post-condition: The temperatures and daily averages are displayed,
//                  neatly formatted, on the screen
//-----------------------------------------------------------------------------------------

void outputData (double [][MaxTimes], int, int);



//-----------------------------------------------------------------------------------------
//
//  Function: outputToFile () to write temperatures and daily averages
//            in a file
//
//	Parameters:	
//    input double; array of temperatures
//    input integer; number of days for that month
//    input integer; number of times temperature is measured each day 
//                    for that month
//    
//	Pre-condition: input array must be populated with valid temperatures;
//                 input number of days must be between 28 & MaxDays (inclusive)
//                 input number of times must be between 0 and MaxTimes 
//  Post-condition: The temperatures and daily averages are written to a file
//-----------------------------------------------------------------------------------------

void outputToFile (double [][MaxTimes], int, int);



