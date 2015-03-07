//Location.cpp

#include "Location.h"

Location::Location()
{
    latitude = 0;
    longitude = 0;
    locationrating = 0;
    numlocationchems = 0;
}

Location::Location(double lat, double lon)
{
    latitude = lat;
    longitude = lon;
    locationrating = 0;
    numlocationchems = 0;
}

void Location::addChemical(Chemical newChemical)
{
    chemicals[numlocationchems] = newChemical;
    numlocationchems++;
}

void Location::calc_LocationRating()
{
    int sum=0, result=0;
    for(int i=0; i<numlocationchems; i++)
        sum += chemicals[i].getTR();
    result = sum/numlocationchems;
    
    locationrating = result;
}

Chemical* Location::get_ListOfLocationChems()
{
    return chemicals;
}

double Location::getLon()
{
    return longitude;
}

double Location::getLat()
{
    return latitude;
}
int Location::get_LocationRating()
{
    return locationrating;
}

istream& operator>>(istream& lhs, Location& rhs)
{
    lhs >> rhs.latitude >> rhs.longitude >> rhs.chemicals[rhs.numlocationchems];
    return lhs;
}

ostream& operator<<(ostream& lhs, Location& rhs)
{
    lhs << "Number of Chemicals: " << rhs.numlocationchems << endl;
    lhs << "Rating: " << rhs.locationrating << endl;
    return lhs;
}
