//
//  Algorithm.h
//  Nearest Neighbor
//
//  Created by Thomas, Jake, Matt, Erin, Kylie, Nate on 11/17/13.
//  Copyright (c) 2013 Fern Force Five - Algorithm Team. All rights reserved.
//  Modified by Nate Milkosky on 11/23/13
//-------------------------------------------------------------------------------------------------
// Algorithm()
// Constructs an algorithm with empty coordinates

#ifndef __Nearest_Neighbor__Algorithm__
#define __Nearest_Neighbor__Algorithm__

#include "Location.h"
#include <iostream>
using namespace std;

class Algorithm
{
    
private:
    Location locs [1000];
    double latitude;
    double longitude;
    
public:
    Algorithm(double,double);
    double calcDistance(double&, double&, double&, double&);
    Location* getBrownfields(double&, Location[], int&);
    int* calcTestPointRating(Location[]);
};

#endif /* defined(__Nearest_Neighbor__Algorithm__) */
