//
//  judge.h
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#ifndef __finalProject__judge__
#define __finalProject__judge__

#include "person.h"
#include <string>

#include <iostream>

class judge: public person{
    
private:
    //values that define a judge
    string jdg;
    string status;
    string verdict;
    
public:
    //
    //pre: judge info
    //post: none
    //creates a judge object
    //
    judge(string, string, string);
    //
    //pre: none
    //post: none
    //default constructor for judge initilized to '-1'
    //
    judge();
    //
    //pre: populated judge object
    //post: none
    //puts the values for a judge into a string
    //
    virtual string printInfo();
    //
    //pre: existing judge object
    //post: none
    //sets one judge object equal to another
    //
    virtual judge& operator=(const judge&);
    //
    //pre: existing judge object
    //post: none
    //creates a populated judge object
    //
    virtual judge* create();
    //
    //pre: judge object
    //post: none
    //deconstructs a judge object removes dynamic;y alocated memory
    //
    ~judge();
    
    friend istream& operator>>(istream&, judge&);

};

#endif /* defined(__finalProject__judge__) */
