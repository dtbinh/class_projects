//
//  Algorithm.h
//  Nearest Neighbor
//
//  Created by Thomas Borgia on 11/17/13.
//  Copyright (c) 2013 Fern Force Five - Algorithm Team. All rights reserved.
//  Modified by Nate Milkosky on 11/23/13
//  Commented by Nate Milkosky on 12/2/13
//-------------------------------------------------------------------------------------------------
// Attributes	
//
// Location TestPoint: the location on which the algorithm will be applied.
// Location allLocations[200]: the nearby locations which MAY affect the test point
// int numAllLocations: the number of location objects in allLocations
// Location result[200]: the nearby locations that will affect the test point - after allLocations 
//						 has been processed
// int resultAdded: the number of elements in result
//-------------------------------------------------------------------------------------------------
// Algorithm(double, double, Location [], int)
//
// Constructs an object that will use the nearest neighbor algorithm on a location.
// Preconditions: The parameters are valid.
// Postconditions: An object has been constructed with a set of coordinates and a set of locations.
//-------------------------------------------------------------------------------------------------
// double calcDistance(double x, double y)
// 
// Calculates the distance between two points using the distance formula.
// Preconditions: The Algorithm object has been instantiated.
// Postconditions: A double value that includes the distance has been returned.
//-------------------------------------------------------------------------------------------------
// Location* nearbyBrownfields(double radius)
//
// Processes all elements of allLocations, and determine if they are close enough to the test point
// using the radius from the parameter.
// Preconditions: allLocations has been populated.
// Postconditions: a list of nearby locations has been returned.
//-------------------------------------------------------------------------------------------------
// Location* nearbydegreeBrownfields(double outerradius, double innerradius)
//
// Processes all elements of allLocations and determine if they are in a certain distance range from
// the test point using the outer and inner radius defined in the parameters.
// Preconditions: allLocations has been populated.
// Postconditions: a list of locations within a certain distance range has been returned.
//-------------------------------------------------------------------------------------------------
// Location& get_potentialChems()
//
// General procedure that gets the nearby brownfields, and then add the chemicals to the new test 
// point Location object.
// Preconditions: the test point has been instantiated, and allLocations has been populated.
// Postconditions: the potential chemicals have been added to the test point Location object.
//-------------------------------------------------------------------------------------------------

#ifndef __Nearest_Neighbor__Algorithm__
#define __Nearest_Neighbor__Algorithm__

#include "Location.h"
#include <iostream>
using namespace std;

const double INNER_RADIUS = 0.00042;
const double OUTER_RADIUS = 0.00084;

class Algorithm
{
    
private:
    Location TestPoint;
	Location allLocations[200];
	int numAllLocations;
    Location result [200];
	int resultAdded;

public:
    Algorithm(double, double, Location [], int);
	double calcDistance(double, double);
    Location* nearbyBrownfields(double);
	Location* nearbydegreeBrownfields(double, double);
	Location& get_potentialChems();
};

#endif /* defined(__Nearest_Neighbor__Algorithm__) */
