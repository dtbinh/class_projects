//
//  person.cpp
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#include "person.h"
#include <iomanip>
#include <sstream>

using namespace std;

person::person(string pName) {
    name = pName;
}

person::person() {
    name = " ";
}

person::~person()
{
    //cout << "Person destructor called" << endl;
}

string person::printInfo ()
{
    ostringstream os;
    os << setw(9) << name << endl;
    return os.str();
}

istream& operator>>(istream& lhs, person& rhs)
{
    
    string one;
    
    lhs >> one;
    
    rhs = person(one);
    
    return lhs;
}



person& person::operator=(const person& rhs)
{
    //cout << "Person called!!!" << endl;
    if (this == &rhs)
        return *this;
    
    else{
        name = rhs.name;
    }
    return *this;
}

person* person::create(){
    person* np;
    np = new person(this->name);
    return np;
}

