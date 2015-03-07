//Chemical.h
#ifndef CHEMICAL_H
#define CHEMICAL_H

#include <iostream>

using namespace std;

/** Chemical Danger Levels */
const int none = 0;
const int low = 1;
const int medium = 2;
const int mediumhigh = 3;
const int high = 4;
const int extremelyhigh = 5;

/** Total Release Danger Interval Sizes */
const int first = 500;
const int second = 10000;
const int third = 25000;
const int fourth = 50000;

class Chemical
{
private:
    string chemName, chemID;
    double total_releases;
    int dangerrating;
    
public:
    Chemical();
    Chemical(string, string, double);
    double getTR();
    void calc_DangerRating();
    friend istream& operator>>(istream&, Chemical&);
    friend ostream& operator<<(ostream&, Chemical&);
};

#endif
