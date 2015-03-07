//
//  Algorithm.cpp
//  Nearest Neighbor
//
//  Created by Thomas Borgia on 11/17/13.
//  Copyright (c) 2013 Fern Force Five - Algorithm Team. All rights reserved.
//
#include "Algorithm.h"
#include "Location.h"
#include "Chemical.h"
#include <math.h>

Algorithm::Algorithm(double lat, double lon, Location locationsArray[], int numLocs)
{
	TestPoint = Location (lat, lon); // sets up test point
	numAllLocations = numLocs;
	resultAdded = 0;
	for(int i=0; i<numAllLocations; i++)
		allLocations[i] = locationsArray[i]; // copies array data
}

double Algorithm::calcDistance(double x, double y)
{
    double distance;
    distance = sqrt(pow((TestPoint.getLon()-x),2) + pow((TestPoint.getLat() - y),2));
    return distance;
}

// 1 Second ~ 100ft
//0.00042 Degrees in 1.5 Seconds
Location* Algorithm::nearbyBrownfields(double radius)
{
	resultAdded = 0;

	double templon = TestPoint.getLon();
	double templat = TestPoint.getLat();

    double xradius = templon+radius;
    double negxradius = templon-radius;
    double yradius = templat+radius;
    double negyradius = templat-radius;

    for(int i = 0; i < numAllLocations; i++)
    { // checks if a Location is in the radius
        if(allLocations[i].getLat() <= yradius && allLocations[i].getLat() >= negyradius
           && allLocations[i].getLon() <= xradius && allLocations[i].getLon() >= negxradius)
        {
            result[resultAdded] = allLocations[i]; //add a location
			resultAdded++;
        }
    }
    return result;
}

// 1 Second ~ 100ft
//0.00042 Degrees in 1.5 Seconds
Location* Algorithm::nearbydegreeBrownfields(double outerradius, double innerradius)
{
	resultAdded = 0;

	double templon = TestPoint.getLon();
	double templat = TestPoint.getLat();

	//Inner square radius dimensions
    double xinnerradius = templon+innerradius;
    double negxinnerradius = templon-innerradius;
    double yinnerradius = templat+innerradius;
    double negyinnerradius = templat-innerradius;

	//Outer square radius dimensions
	double xouterradius = templon+outerradius;
	double negxouterradius = templon-outerradius;
	double youterradius = templat+outerradius;
	double negyouterradius = templat-outerradius;

    for(int i = 0; i < numAllLocations; i++)
    {
		double templon = allLocations[i].getLon();
		double templat = allLocations[i].getLat();
		if
			(((templon <= xouterradius) && (templon >= xinnerradius))||
			((templon >= negxouterradius) && (templon <= negxinnerradius)) //check inner radius
			&&
			(((templat <= youterradius) && (templat >= yinnerradius))||
			((templat >= negyouterradius) && (templat <= negyinnerradius))))//check outer radius
        {
            result[resultAdded] = allLocations[i]; // add the location
			resultAdded++;
        }
    }
    return result;
}

Location& Algorithm::get_potentialChems()
{

	//Add all chemicals of brownfields in first degree to test point
	nearbyBrownfields(INNER_RADIUS);
	for(int i=0; i<resultAdded; i++)
		TestPoint.addChemicals((result[i].get_ListOfLocationChems()), (result[i].get_numlocchems()));

	//Add chemicals which contain a higher TR than low after distance division*/
	nearbydegreeBrownfields(OUTER_RADIUS, INNER_RADIUS);
	for(int i=0; i<resultAdded; i++)
	{
		double distance;
		distance = calcDistance(result[i].getLat(), result[i].getLon());
		for(int j=0; j<result[i].get_numlocchems(); j++)
		{
			if(((result[i].get_chemTR(j))/(pow(distance,2))) > first)
			{
				Chemical temp = result[i].get_ChematIndex(j);
				temp.setTR(temp.getTR()/(pow(distance,2)));
				TestPoint.addChemical(temp);
			}
		}
	}

	return TestPoint;
}
