//
//  docket.cpp
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#include "docket.h"

#include <iomanip>
#include <sstream>

//docket constructer
docket::docket(string pDocket, string pDocketDate, string pOne, string pTwo, string pThree, string pFour){
    dckt = pDocket;
    docketDate = pDocketDate;
    one = pOne;
    two = pTwo;
    three = pThree;
    four = pFour;
}


//default docket constructer
docket::docket(){

    dckt = " ";
    docketDate = " ";
    one = " ";
    two = " ";
    three = " ";
    four = " ";
}

//docket deconstructor
docket::~docket()
{
    //cout << "Docket destructor called" << endl;
}

//puts all docket info into a string
string docket::printInfo ()
{
    ostringstream os;
    os << "docket info:" << setw(9) << dckt << setw(9) << docketDate << setw(9) << one << setw(9) << two << setw(9) << three << setw(9) << four << endl;
    return os.str();
}

//populates a docket object with incomming values
istream& operator>>(istream& lhs, docket& rhs)
{
    cout << "please enter docket name:"<< endl;
    string one;
    cout << "please enter docket date:" << endl;
    string two;
    cout << "please enter charge 1 y or n:" << endl;
    string three;
    cout << "please enter charge 2 y or n:" << endl;
    string four;
    cout << "please enter charge 3 y or n:" << endl;
    string five;
    cout << "please enter charge 4 y or n:" << endl;
    string six;
    
    lhs >> one;
    lhs >> two;
    lhs >> three;
    lhs >> four;
    lhs >> five;
    lhs >> six;
    
    rhs = docket(one, two, three, four, five, six);
    
    return lhs;
}

//sets one docket's information equal to another
docket& docket::operator=(const docket& rhs)
{
    //cout << "docket called!!!" << endl;
    if (this == &rhs)
        return *this;
    
    else{

        dckt = rhs.dckt;
        docketDate = rhs.docketDate;
        one = rhs.one;
        two = rhs.two;
        three = rhs.three;
        four = rhs.four;
        
    }
    return *this;
}

