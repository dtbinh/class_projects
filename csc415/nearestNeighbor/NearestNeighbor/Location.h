//Location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include "Chemical.h"

using namespace std;

class Location
{
private:
    string streetAddress, state, facility, city;
    int rating;
    Chemical chemicals[100];
    int numChemicals;
public:
    Location();

    //-----------------------------------------------------------------------------------------
	//
	//  Function: Location(string streetAddress, string state, string facility, string city);
	//
	//    Parameters: 	streetAddress - address of the brownfield
	//					state - US state with the brownfield
	//					facility - name of the brownfield facility
	//					city - name of the city the brownfield is in
	//    
	//    Pre-condition: none
	// 	  Post-condition: instantiates the location object with the above parameters
	//-----------------------------------------------------------------------------------------
    Location(string streetAddress, string state, string facility, string city);

    //-----------------------------------------------------------------------------------------
	//
	//  Function: void addChemical(Chemical);
	//
	//    Parameters: Chemical: chemical to be added to the chemicals[] array
	//    
	//    Pre-condition: chemical object must be populated with information
	// 	  Post-condition: adds the chemical to the chemicals[] array
	//-----------------------------------------------------------------------------------------
    void addChemical(Chemical);

    //-----------------------------------------------------------------------------------------
	//
	//  Function: string listAllChemicals();
	//
	//    Parameters: none
	//    
	//    Pre-condition: none
	// 	  Post-condition: prints out all chemicals in that location along with information
	//						about that chemical
	//-----------------------------------------------------------------------------------------
    string listAllChemicals();

    //overloaded << operator to print facility, street address, city, state, number of chemicals,
    //rating.
    friend ostream& operator<<(ostream& lhs, Location& rhs);

    //-----------------------------------------------------------------------------------------
	//
	//  Function: 
	//
	//    Parameters: 
	//    
	//    Pre-condition: 
	// 	  Post-condition: 
	//-----------------------------------------------------------------------------------------
    Chemical* getChemicalList();
    int getRating();
    void setRating(int);
    void calcRating();
    int getNumChemicals();
};

#endif