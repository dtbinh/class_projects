//Chemical.cpp

#include <iomanip>
#include "Chemical.h"

//constructor for chemical
Chemical::Chemical(string name, string ID, double treleases)
{
    chemName = name;
    chemID = ID;
    total_releases = treleases;
	concentrationLevel = "None";
}

//uses total releases to calculate concentration level
void Chemical::set_concentrationLevel()
{
    //determines the severity of chemical concentration
	if((none < total_releases) && (total_releases <= first))
		concentrationLevel = "Low";
	else if((first < total_releases) && (total_releases <= second))
		concentrationLevel = "Medium";
	else if((second < total_releases) && (total_releases <= third))
		concentrationLevel = "Medium High";
	else if((third < total_releases) && (total_releases <= fourth))
		concentrationLevel = "High";
	else if(fourth < total_releases)
		concentrationLevel = "Extremely High";
}

//sets total releases
void Chemical::setTR(int newTR)
{
	total_releases = newTR;
}

//gets total releases
double Chemical::getTR()
{
    return total_releases;
}

//adds total release to current total release
void Chemical::addTR(int tempTR)
{
	total_releases = (tempTR + total_releases);
}

//gets CAS number
string Chemical::get_CASNo()
{
	return chemID;
}

//operator overload for inputting data into chemical object
istream& operator>>(istream& lhs, Chemical& rhs)
{
    lhs >> rhs.chemName >> rhs.chemID >> rhs.total_releases;
    return lhs;
}

//outputs chemicals
ostream& operator<<(ostream& lhs, Chemical& rhs)
{
    lhs << setw(40) << left << rhs.chemName
		<< setw(40) << left << rhs.chemID
		<< setw(40) << left << rhs.total_releases
		<< setw(40) << left << rhs.concentrationLevel
		<< endl;
    return lhs;
}
