//Chemical.cpp

#include "Chemical.h"

Chemical::Chemical()
{
    
}

Chemical::Chemical(string name, string ID, double treleases)
{
    chemName = name;
    chemID = ID;
    total_releases = treleases;
    dangerrating = none;
}

double Chemical::getTR()
{
    return total_releases;
}

void Chemical::calc_DangerRating()
{
    if(total_releases <= first)
        dangerrating = low;
    if((total_releases > first) && (total_releases <= second))
        dangerrating = medium;
    if((total_releases > second) && (total_releases <= third))
        dangerrating = mediumhigh;
    if((total_releases > third) && (total_releases <= fourth))
        dangerrating = high;
    if((total_releases > fourth))
        dangerrating = extremelyhigh;
}

istream& operator>>(istream& lhs, Chemical& rhs)
{
    lhs >> rhs.chemName >> rhs.chemID >> rhs.total_releases;
    return lhs;
}

ostream& operator<<(ostream& lhs, Chemical& rhs)
{
    lhs << "Name: " << rhs.chemName << endl;
    lhs << "ID Number: " << rhs.chemID << endl;
    lhs << "Total Releases: " << rhs.total_releases << endl;
    return lhs;
}
