//Location.cpp   

#include "Location.h"

Location::Location(){
	numChemicals=0;
}

Location::Location(string streetAddress, string state, string facility, string city){
	numChemicals=0;
	this->streetAddress = streetAddress;
	this->state = state;
	this->facility = facility;
	this->city = city;
}

void Location::addChemical(Chemical newChemical){
	chemicals[numChemicals] = newChemical;
	numChemicals++;
}

string Location::listAllChemicals()
{
    string store;
    for(int i=0;i<numChemicals;i++)
        store+=chemicals[i].listIntData();
    return store;
}

ostream& operator<<(ostream& lhs, Location& rhs)
{
    lhs << "Facility: " << rhs.facility << endl;
    lhs << "Street Address: " << rhs.streetAddress << endl;
    lhs << "City: " << rhs.city << endl;
    lhs << "State: " << rhs.state << endl;
    lhs << "Number of Chemicals: " << rhs.numChemicals << endl;
    lhs << "Rating: " << rhs.rating << endl;
    return lhs;
}

Chemical* Location::getChemicalList()
{
	return chemicals;
}

int Location::getNumChemicals()
{
	return numChemicals;
}

int Location::getRating(){
    return rating;
}

void Location::setRating(int rating){
    this->rating = rating;
}

void Location::calcRating(){
    int result=0;
    int total_releases=0;
    for (int i=0;i<numChemicals;i++){
        total_releases += (int)chemicals[i].getTR();
    }

    result = (int)(((total_releases*100)/(11159*numChemicals)));
    setRating(result);
}