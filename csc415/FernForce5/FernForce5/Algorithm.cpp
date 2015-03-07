//
//  Algorithm.cpp
//  Nearest Neighbor
//
//  Created by Thomas Borgia on 11/17/13.
//  Copyright (c) 2013 Fern Force Five - Algorithm Team. All rights reserved.
//

#include "Algorithm.h"
#include <math.h>

Algorithm::Algorithm(double x, double y)
{
    latitude = x;
    longitude = y;
}

double Algorithm::calcDistance(double& x1, double& y1, double& x2, double& y2)
{
    double distance;
    distance = sqrt(pow((x2-x1),2) + pow((y2 - y1),2));
    return distance;
}

// 1 Second ~ 100ft
//0.00042 Degrees in 1.5 Seconds
Location* Algorithm::getBrownfields(double& radius, Location allLocations[], int &numLocs)
{
    double xradius = longitude+radius;
    double negxradius = longitude-radius;
    double yradius = latitude+radius;
    double negyradius = latitude-radius;
    
    int numAdded = 0;
    for(int i = 0; i < numLocs; i++)
    {
        if(allLocations[i].getLat() <= yradius && allLocations[i].getLat() >= negyradius
           && allLocations[i].getLon() <= xradius && allLocations[i].getLon() >= negxradius)
        {
            locs[numAdded] = allLocations[i];
            numAdded++;
        }
    }
    return locs;
}

int* Algorithm::calcTestPointRating(Location near[])
{
    int* result = new int[100];
    
    return result;
}
