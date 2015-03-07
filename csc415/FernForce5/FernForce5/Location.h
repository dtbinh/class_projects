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
    int locationrating, numlocationchems;
    Chemical chemicals [100];
    
public:
    Location();
    Location(double, double);
    void addChemical(Chemical);
    void calc_LocationRating();
    double getLat();
    double getLon();
    Chemical* get_ListOfLocationChems();
    int get_LocationRating();
    friend istream& operator>>(istream&, Location&);
    friend ostream& operator<<(ostream&, Location&);
};

#endif
