//
//  defendant.h
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#ifndef __finalProject__defendant__
#define __finalProject__defendant__

#include "person.h"
#include "docket.h"

#include <iostream>

class defendant: public person{
    
private:

    //variables that represent defendant
    int id;
    int age;
    string dob;
    string sex;
    string race;
    string bail;
    string da;
    string jailTime;
    string sentence;
    docket dock;
    
public:
    //
    //pre: input data and a defendant object
    //post: none
    //creates a defendant with a docket attatched
    //
    defendant(int, string, int, string, string, string, string, string, string, string, docket);
    //
    //pre: input data and a defendant object
    //post: none
    //creates a defendant without a docket attatched
    //
    defendant(int, string, int, string, string, string, string, string, string, string);
    //
    //pre: none
    //post: none
    //creates a default defendant with all values equal to '-1'
    //
    defendant();
    //
    //pre: data in a defendant object
    //post: none
    //creates a string with all of the information from defendant in it
    //
    virtual string printInfo();
    //
    //pre: two existing defendant objects
    //post: none
    //sets the values from one defendant to the values of another
    //
    virtual defendant& operator=(const defendant&);
    //
    //pre: existing defendant object
    //post: none
    //creats a defendant object with populated values
    //
    virtual defendant* create();
    //
    //pre: defendant object
    //post: none
    //destructs defendant object
    //
    ~defendant();
    
    //
    //pre: data for defendant
    //post: none
    //inputs data into defendant object
    //
    friend istream& operator>>(istream&, defendant&);
    
};

#endif /* defined(__finalProject__defendant__) */
