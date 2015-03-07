//Chemical.h
#ifndef CHEMICAL_H
#define CHEMICAL_H

#include <iomanip>
#include <iostream>
//#include <strstream> //THIS WORKS ON WINDOWS
#include <sstream> //THIS WORKS ON MAC
#include <string>
#include <cmath>

using namespace std;

class Chemical
{
private:
    string name, ID;
    bool cleanAirAct,pbt,metal,carcinogen;
    double fugitive_air, stack_air, water, total_releases, production_waste;
    
public:
    Chemical();
    Chemical(string, double, double, double, double, double);
    Chemical(string name, string ID, bool cleanAirAct, bool metal, bool carcinogen, bool pbt);
    string listIntData();
    friend ostream& operator<<(ostream& lhs, Chemical& rhs);
	double calcSumSquare(Chemical&, double, double, double, double, double);
	double calcSumSquare(double, double, double, double, double);
    string getName();
    double getTR();
};

#endif