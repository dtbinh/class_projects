//
//  AlgorithmDriver.cpp
//  Nearest Neighbor Algorithm
//
//  Created by Thomas Borgia on 11/23/13.
//  Copyright (c) 2013 Fern Force 5. All rights reserved.
//

#include "Algorithm.h"
#include "Location.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

Location allLocations [200];
int numoflocations = 0;

double sTOd(string str) //convert a string to a double
{
    stringstream ss(str);
    double ret;
    ss >> ret;
    return ret;
}

int is_inlocations(double templat, double templon) //check if a pair of coordinates is already in the location array.
{
    for(int i=0; i<=numoflocations; i++)
    {
        if((allLocations[i].getLat() == templat) && (allLocations[i].getLon() == templon))
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[], char *envp[])
{
    ifstream inFile1;
    string inFile1name = "instances.txt";
    inFile1.open (inFile1name.c_str());
    while(!inFile1.eof())
    {
        string temp;
        getline(inFile1,temp,'\n');
        istringstream ss1(temp), ss2(temp);
        double templat=0, templon=0;
        ss1 >> templat >> templon;
        //Loaded the first line into two different strings: one for the coordinates and the other for the whole string
        int number = is_inlocations(templat, templon);
        if(number>-1) // if the location is in the list of locations, update a previous entry
        {
            string tempchem, tempcas;
            int temptr;
            ss1 >> tempchem >> tempcas >> temptr;
            Chemical temp = Chemical(tempchem, tempcas, temptr);
            allLocations[number].addChemical(temp);
        }
        if(number==-1) // if the location is not in the list, then add it
        {
            ss2 >> allLocations[numoflocations];
            numoflocations++;
        }
    }

    Algorithm coords1 (sTOd(argv[1]), sTOd(argv[2]), allLocations, numoflocations); //Create an 
//	algorithm object using the locations from the text file and the test point passed by arguments.
	cout << coords1.get_potentialChems();

    return 0;
}
