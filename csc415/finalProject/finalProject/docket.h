//
//  docket.h
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#ifndef __finalProject__docket__
#define __finalProject__docket__

#include "person.h"

#include <iostream>
#include <string>

class docket{
    
private:
    //variables that define a docket
    string dckt;
    string docketDate;
    string one;
    string two;
    string three;
    string four;
    
public:
    //
    //pre: information for a docket
    //post: none
    //creates a docket with the entered information
    //
    docket(string, string, string, string, string, string);
    //
    //pre: none
    //post: none
    //creates a default docket with all values set to '-1'
    //
    docket();
    //
    //pre: populated docket object
    //post: none
    //puts all docket info into strings
    //
    string printInfo();
    //
    //pre: existing docket objects
    //post: none
    //sets one docket equal to another
    //
    docket& operator=(const docket&);
    //
    //pre: existing docket object
    //post: none
    //deconstructs a docket object
    //
    ~docket();
    
    //
    //pre: empty docket object
    //post: none
    //populates a docket object with the information provided
    //
    friend istream& operator>>(istream&, docket&);
};


#endif /* defined(__finalProject__docket__) */
