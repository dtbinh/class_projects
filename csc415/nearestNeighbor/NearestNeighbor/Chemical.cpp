//Chemical.cpp

#include "Chemical.h"

Chemical::Chemical()
{
    
}

Chemical::Chemical(string name, string ID, bool cleanAirAct, bool metal, bool carcinogen, bool pbt) {
	this->name = name;
	this->ID = ID;
	this->cleanAirAct = cleanAirAct;
	this->pbt = pbt;
	this->metal = metal;
	this->carcinogen = carcinogen;
}

Chemical::Chemical(string name, double FA, double SA, double W, double TR, double PW){
	this->name = name;
	fugitive_air = FA;
	stack_air = SA;
	water = W;
	total_releases = TR;
	production_waste = PW;
}

double Chemical::calcSumSquare(Chemical& ratedChem, double rangeFugitive, double rangeStack, double rangeWater, double rangeTotal, double rangeProduction)
{
	//calling object should be the chemical of the location object to be rated.
	//fugitive_air, stack_air, water, total_releases, production_waste

	double result = pow(((fugitive_air - ratedChem.fugitive_air)/rangeFugitive), 2) + pow(((stack_air - ratedChem.stack_air)/rangeFugitive), 2) + pow(((water - ratedChem.water)/rangeWater), 2) + pow(((total_releases - ratedChem.total_releases)/rangeTotal), 2) + pow(((production_waste - ratedChem.production_waste)/rangeProduction), 2);
	return result;
}

double Chemical::calcSumSquare(double rangeFugitive, double rangeStack, double rangeWater, double rangeTotal, double rangeProduction) // ChemSubZero case, the chemical that needs to be compared in the inputLocation doesn't exist in the ratedLocation 
{ // normalizes scores with range values, calculated within classifier.
	return pow((fugitive_air/rangeFugitive), 2) + pow((stack_air/rangeStack), 2) + pow((water/rangeWater), 2) + pow((total_releases/rangeTotal), 2) + pow((production_waste/rangeProduction), 2);
}
	

string Chemical::listIntData()
{
    //strstream ss; //THIS LINE WORKS ON WINDOWS
    stringstream ss; //THIS LINE WORKS ON MAC
    ss << name << '\t' << fugitive_air << '\t' << stack_air << '\t' << water << '\t' << total_releases << '\t' << production_waste << '\t' << '\n';
    return ss.str();
}

ostream& operator<<(ostream& lhs, Chemical& rhs)
{
    lhs << "Name: " << rhs.name << endl;
    lhs << "ID Number: " << rhs.ID << endl;
    lhs << "This chemical DOES ";
    if(!rhs.cleanAirAct)
        lhs << "NOT ";
    lhs << "conform to the clean air act." << endl;
    lhs << "This chemical IS ";
    if(!rhs.metal)
        lhs << "NOT ";
    lhs << "metal." << endl;
    lhs << "This chemical IS ";
    if(!rhs.carcinogen)
        lhs << "NOT ";
    lhs << "carcinogenic." << endl;
    lhs << "This chemical DOES ";
    if(!rhs.pbt)
        lhs << "NOT ";
    lhs << "contain PBT." << endl;
    return lhs;
}

string Chemical::getName()
{
	return name;
}

double Chemical::getTR(){
    return total_releases;
}