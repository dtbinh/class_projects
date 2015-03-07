//Location.h
#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include "Chemical.h"

using namespace std;

class Location
{
private:
    double latitude, longitude;
    int numlocationchems;
	string concentrationLevel;
    Chemical chemicals [50];
    
public:
    Location(double = 0, double = 0);
    void addChemical(Chemical);
	void addChemicals(Chemical [], int);
	int is_chematLocation(string);
	Chemical* get_ListOfLocationChems();
	void set_concentrationLevel();
    double getLat();
    double getLon();
	Chemical get_ChematIndex(int);
	int get_chemTR(int);
	int get_numlocchems();
    friend istream& operator>>(istream&, Location&);
    friend ostream& operator<<(ostream&, Location&);
};

#endif
