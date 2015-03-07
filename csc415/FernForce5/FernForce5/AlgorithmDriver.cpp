//
//  AlgorithmDriver.cpp
//  Nearest Neighbor Algorithm
//
//  Created by Thomas, Jake, Matt, Erin, Kylie, Nate on 11/23/13.
//  Copyright (c) 2013 Fern Force 5. All rights reserved.
//

#include "Algorithm.h"
#include "Location.h"
#include <iostream>
#include <fstream>
#include <sstream>

double sTOd(char* str)
{
    stringstream ss;
    ss.str(str);
    double ret;
    ss >> ret;
    return ret;
}

int main(int argc, char *argv[], char *envp[])
{
    Location allLocations [1000];
    int numoflocations = 0;
    ifstream inFile1;
    string inFile1name = "instances.txt";
    inFile1.open (inFile1name.c_str());
    string temp;
    while(!inFile1.eof())
    {
        getline(inFile1,temp,'\n');
        istringstream ss1(temp), ss2(temp);
        double templat, templon;
        ss1 >> templat >> templon;
        
        for(int i=0; i<numoflocations; i++)
        {
            if((allLocations[i].getLat() == templat) && (allLocations[i].getLon() == templon))
            {
                string tempchem, tempcas;
                int temptr;
                ss1 >> tempchem >> tempcas >> temptr;
                Chemical temp = Chemical(tempchem, tempcas, temptr);
                allLocations[i].addChemical(temp);
            }
            else
            {
                ss2 >> allLocations[i];
                numoflocations++;
            }
        }
    }
    
    int MAX_VALUES = 10;
    Algorithm testPt(sTOd(argv[0]), sTOd(argv[1])); // convert string args to floats and then create an algorithm file
    int* values = new int[MAX_VALUES];
   // values = testPt.calcTestPointRating();
    for(int i = 0; i < MAX_VALUES; i++)
        cout << values[i] << endl;
    return 0;
}
