//Location.cpp

#include "Location.h"

//default constructor
Location::Location()
{
    latitude = 0;
    longitude = 0;
    locationrating = 0;
    numlocationchems = 0;
    avgtotalreleases = 0;
}

//constructor with latitude and longitude as parameters
Location::Location(double lat, double lon)
{
    latitude = lat;
    longitude = lon;
    locationrating = 0;
    numlocationchems = 0;
}

//adds a chemical to the chemical array if the chemical is present at the test point
void Location::addChemical(Chemical newChemical)
{
	int temp = is_chematLocation(newChemical.get_CASNo());
	if(temp == -1)
	{
		chemicals[numlocationchems] = newChemical;
		numlocationchems++;
	}
	else if(temp > -1)
	{
		chemicals[temp].addTR(newChemical.getTR());
	}
	calc_LocationRating();
}

//adds multiple chemicals to a location if they can be found at the test point
void Location::addChemicals(Chemical newChemicals [], int numoflocchems)
{

	for(int i=0; i<numoflocchems; i++)
	{
		int temp = is_chematLocation(newChemicals[i].get_CASNo());
		if(temp == -1)
		{
			chemicals[numlocationchems] = newChemicals[i];
			numlocationchems++;
		}
		else if(temp > -1)
		{
			chemicals[temp].addTR(newChemicals[i].getTR());
		}
	}
	calc_LocationRating();
}

//determines if a chemical is at a location
int Location::is_chematLocation(string newID)
{
	int value=-1;
	int counter=0;
	while((value == -1) && (counter < numlocationchems))
	{
		if(newID == chemicals[counter].get_CASNo())
			value = counter;
		else
			value = -1;
			counter++;
	}
	return value;
}

//calculates the average total releases of the location by adding the total releases
//then dividing them by the number of chemicals at the location
int Location::calc_AvgTR()
{
    int sum=0, result=0;
    for(int i=0; i<numlocationchems; i++)
        sum += chemicals[i].getTR();
    result = sum/numlocationchems;
    return result;
}

//the danger rating of a location is calculated
void Location::calc_LocationRating()
{
    if(avgtotalreleases == 0)
    {
        locationrating = none;
    }
    if((avgtotalreleases > none) && (avgtotalreleases <= first))
    {
        locationrating = low;
    }
    if((avgtotalreleases > first) && (avgtotalreleases <= second))
    {
        locationrating = medium;
    }
    if((avgtotalreleases > second) && (avgtotalreleases <= third))
    {
        locationrating = mediumhigh;
    }
    if((avgtotalreleases > third) && (avgtotalreleases <= fourth))
    {
        locationrating = high;
    }
    if((avgtotalreleases > fourth))
    {
        locationrating = extremelyhigh;
    }
}

//the total releases of a particular chemical is returned
int Location::get_chemTR(int arrIndex)
{
	return chemicals[arrIndex].getTR();
}

//the list of chemicals at a location are returned
Chemical* Location::get_ListOfLocationChems()
{
	return chemicals;
}

//the chemical at a particular index is returned
Chemical Location::get_ChematIndex(int arrIndex)
{
	return chemicals[arrIndex];
}

//the number of chemicals at the test point are returned
int Location::get_numlocchems()
{
	return numlocationchems;
}

//the longitude of the test point is returned
double Location::getLon()
{
    return longitude;
}

//the latitude of the test point is returned
double Location::getLat()
{
    return latitude;
}

//the location rating for the test point is returned
int Location::get_LocationRating()
{
    return locationrating;
}

//input operator overload
istream& operator>>(istream& lhs, Location& rhs)
{
    lhs >> rhs.latitude >> rhs.longitude >> rhs.chemicals[rhs.numlocationchems];
    rhs.numlocationchems++;
    return lhs;
}

//output operator overload
ostream& operator<<(ostream& lhs, Location& rhs)
{
    lhs << "Location Data" << endl;
    lhs << "-----------------------------------------------------------------" << endl;
    lhs << "Location " << rhs.latitude << "," << rhs.longitude << "." << endl;
    lhs << "Number of Chemicals at Location: " << rhs.numlocationchems << endl;
    lhs << "Location Rating: " << rhs.locationrating << endl;
    lhs << "Location chemicals: " << endl;
    for(int i=0; i<rhs.numlocationchems; i++)
        lhs << rhs.chemicals[i];
    lhs << "-----------------------------------------------------------------" << endl;
    return lhs;
}
