//
//  person.h
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#ifndef __finalProject__person__
#define __finalProject__person__

#include <iostream>
#include <string>

using namespace std;

class person{
    
protected:
    //variable that defines a person
    string name;
    
public:
    //
    //pre: information for person object
    //post: none
    //creates a person object with the information provided
    //
    person(string);
    //
    //pre: none
    //post: none
    //creates a person with the name set to '-1'
    //
    person();
    //
    //pre: a person object
    //post: none
    //puts information from a person object into a string
    //
    virtual string printInfo();
    //
    //pre: existing person object
    //post: none
    //sets person object equal to another person object
    //
    virtual person& operator=(const person&);
    //
    //pre: existing person object
    //post: none
    //creates a populated person object
    //
    virtual person* create();
    //
    //pre: existing person object
    //post: none
    //deconstructs a person object, deleting dynamic data
    //
    ~person();
    
    //
    //pre: person object
    //post: none
    //sets the input data in a person object
    //
    friend istream& operator>>(istream&, person&);

    
};

#endif /* defined(__finalProject__person__) */
