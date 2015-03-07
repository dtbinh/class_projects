//Location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include "Chemical.h"

using namespace std;

class Location
{
private:
	//latitudes and longitudes for the location
    double latitude, longitude;
	//danger rating for a location, number of chemicals at the location and the average concentration of chemicals
    int locationrating, numlocationchems, avgtotalreleases;
	//array of chemical objects
    Chemical chemicals [50];
    
public:
	/* 
	 * default constructor
	 * pre-condition: none
	 * post-condition: location object was constucted
	 */
    Location();
	
	/* 
	 * constructor with latitude then longitude as arguments
	 * pre-condition: latitude and longitude must be passed as arguments
	 * post-condition: a location object with latitude and longitude will be created
	 */
    Location(double, double);
	
	/*
	 * adds a chemical object to the chemical array for the test point
	 * pre-condition: a chemical is confirmed to be within one of the 
	 * degrees of certainty for a given test point.
	 * post-condition: the chemical is added to the location object
	 */
    void addChemical(Chemical);
	
	/*
	 * adds chemicals to the chemical array for a test point
	 * pre-condtion: multiple chemicals are confirmed to be within one of the degrees of
	 * certainty for a given test point.
	 * post-condion: a chemical array is added to the array of the location test point
	 */
	void addChemicals(Chemical [], int);
	
	/*
	 * calculates the average total releases of a location by adding up the total releases for each
	 * chemical then dividing it by the number of chemicals at that location.
	 * pre-condition: none
	 * post-condiont: the average total releases for a location is calculated and returned
	 */
    int calc_AvgTR
	
	/* 
	 * determines if a chemical is at a particular location, if it is then location in the chemical array
	 * is returned, else a -1 is returned
	 * pre-condition: a CAS number of a chemical is passed as an argument
	 * post-condtion: the chemicals position in the location object's chemical array is
	 * returned, else a -1 is returned
	 */
	int is_chematLocation(string);
	
	/*
	 * the danger rating of a location is calculated based on the average total releases
	 * pre-condtion: none
	 * post-condtion: the danger rating of a location is assigned
	 */
    void calc_LocationRating();
	
	/*
	 * the list of chemicals at a location is returned
	 * pre-condion: none
	 * post-condtion: the list of chemicals at a test point are returned
	 */
	Chemical* get_ListOfLocationChems();
	
	/*
	 * returns the latitude of the test point
	 * pre-condition: none
	 * post-condition: the latitude of a test point is returned
	 */
    double getLat();
	
	/*
	 * returns the longitude of the test point
	 * pre-condition: none
	 * post-condition: the longitude of a test point is returned
	 */
    double getLon();
	
	/*
	 * returns the chemical at a specified index
	 * pre-condtion: a valid array index is passed as an argument
	 * post-condtion: the chemical at the index is returned
	 */
	Chemical get_ChematIndex(int);
	
	/*
	 * returns the total releases of a chemical at a specified index
	 * pre-condtion: a valid array index is passed as an argument
	 * post-condtion: the total releases of a chemical at the index is returned
	 */
	int get_chemTR(int);
	
	/*
	 * returns the number of chemicals at the test point
	 * pre-condtion: none
	 * post-condtion: the number of chemicals at the test point are returned
	 */
	int get_numlocchems();
	
	/*
	 * returns the danger rating of the test point
	 * pre-condtion: none
	 * post-condtion: the danger rating of the test point is returned
	 */
    int get_LocationRating();
	
	/*
	 * overload the input operator
	 * pre-condtion: none
	 * post-condition: the input operator is overloaded such that a location object can be created by input
	 */
    friend istream& operator>>(istream&, Location&);
	
	/*
	 * overload the output operator
	 * pre-condtion: none
	 * post-condition: the output operator is overloaded such that a location object is displayed
	 */
    friend ostream& operator<<(ostream&, Location&);
};

#endif
