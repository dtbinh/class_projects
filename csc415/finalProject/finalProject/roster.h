//
//  list.h
//  finalProject
//
//  Created by Jake Orben on 12/8/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#ifndef __finalProject__list__
#define __finalProject__list__

#include <iostream>
#include "person.h"
#include "defendant.h"
#include "docket.h"
#include "judge.h"

using namespace std;
//#include "personList.h"

class roster{
private:
    //total size of array
    int length;
    //polymorphic array pointers
    person **ary;
    //total number of items in array
    int total;
    
    
public:
    //
    //pre: array size
    //post: none
    //creates a roster file with the desired number of elements
    //
    roster(int);
    //
    //pre: none
    //post: none
    //creates a default roster which can hold 3 items
    //
    roster();
    
    //
    //pre: must be a pre-existing array
    //post: none
    //Adds a new item to the array
    //
    roster add(person*);
    //
    //pre: existing person object
    //post: none
    //sets one person equal to another
    //
    roster& operator=(const roster&);
    //
    //pre: must have roster
    //post: none
    //delets an array and creates a replica
    //
    roster(const roster&);
    //
    //pre: existing person array
    //post: none
    //deletes all dynamic objects
    //
    ~roster();
    //
    //pre: popuolated items in array
    //post: none
    //calls the requisite person 'printInfo()' method for output
    //
    virtual string printInfo();
    //
    //pre: input file
    //post: none
    //populates an array from a file of persons
    //
    void inputFmFile();
    
};

#endif /* defined(__finalProject__list__) */
