//
//  judge.cpp
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#include "judge.h"

#include <iomanip>
#include <sstream>

//constructor for judge
judge::judge(string pJudge, string pStatus, string pVerdict){
    jdg = pJudge;
    status = pStatus;
    verdict = pVerdict;
}

//default consructor for judge
judge::judge(){
    jdg = " ";
    status = " ";
    verdict = " ";
}

//deconstructor for judge
judge::~judge()
{
    //cout << "Judge destructor called" << endl;
}

//to string for all judge info
string judge::printInfo ()
{
    ostringstream os;
    os << "judge info: " << setw(9) << jdg << setw(9) << status << setw(9) << verdict << endl;
    return os.str();
}

//inputs data into judge object
istream& operator>>(istream& lhs, judge& rhs)
{
    cout << "please entr the name of the judge:" << endl;
    string one;
    cout << "please enter the status:" << endl;
    string two;
    cout << "please enter the verdict:" << endl;
    string three;

    
    lhs >> one;
    lhs >> two;
    lhs >> three;

    
    rhs = judge(one, two, three);
    
    return lhs;
}

//sets one judge object equal to another
judge& judge::operator=(const judge& rhs)
{
    //cout << "enter judge assignment operator" << endl;
    if (this == &rhs)
        return *this;
    
    else{
        jdg = rhs.jdg;
        status = rhs.status;
        verdict = rhs.verdict;
        //cout << "done!!!" << jdg << status << verdict << endl;
            
        }
        return *this;
}

//createsa populated judge object
judge* judge::create(){
    judge* nj;
    nj = new judge(this->jdg, this->status, this->verdict);
    return nj;
}

