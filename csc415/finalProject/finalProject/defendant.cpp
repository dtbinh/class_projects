//
//  defendant.cpp
//  finalProject
//
//  Created by Jake Orben on 12/7/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#include "defendant.h"
#include <iomanip>
#include <sstream>

//constructor for defendant with a docket
defendant::defendant(int pId, string pName, int pAge, string pDob, string pSex, string pRace, string pBail, string pDa, string pJailTime, string pSentence, docket pDock){
    id = pId;
    name = pName;
    age = pAge;
    dob = pDob;
    sex = pSex;
    race = pRace;
    bail = pBail;
    da = pDa;
    jailTime = pJailTime;
    sentence = pSentence;
    dock = pDock;
}

//constructor for a defndant without a docket
defendant::defendant(int pId, string pName, int pAge, string pDob, string pSex, string pRace, string pBail, string pDa, string pJailTime, string pSentence){
    id = pId;
    name = pName;
    age = pAge;
    dob = pDob;
    sex = pSex;
    race = pRace;
    bail = pBail;
    da = pDa;
    jailTime = pJailTime;
    sentence = pSentence;
}

//default constructor for a defendant
defendant::defendant(){
    
    id = -1;
    name = " ";
    age = -1;
    dob = " ";
    sex = " ";
    race = " ";
    bail = " ";
    da = " ";
    jailTime = " ";
    sentence = " ";
}

//defendant deconstructor
defendant::~defendant()
{
    //cout << "Defendant destructor called" << endl;
}

//defendant to string
string defendant::printInfo ()
{
    ostringstream os;
    os << "defendant info: " << setw(9) << id << setw(9) << name << setw(9) << age << setw(9) << dob << setw(9) << sex << setw(9) << race << setw(9) << bail << setw(9) << da << setw(9) << jailTime << setw(9) << sentence << endl << dock.printInfo() << endl;
    return os.str();
}

//inputs data into defendant
istream& operator>>(istream& lhs, defendant& rhs)
{
    cout << "please enter ID:" << endl;
    int one;
    cout << "please enter name:" << endl;
    string two;
    cout << "please enter age:" << endl;
    int three;
    cout << "please enter dob:" << endl;
    string four;
    cout << "please enter sex:" << endl;
    string five;
    cout << "please enter race:" << endl;
    string six;
    cout << "please enter bail:" << endl;
    string seven;
    cout << "please enter da:" << endl;
    string eight;
    cout << "please enter jail time:" << endl;
    string nine;
    cout << "please enter sentence:" << endl;
    string ten;
    cout << "please enter docket info:" << endl;
    docket eleven;
    
    lhs >> one;
    lhs >> two;
    lhs >> three;
    lhs >> four;
    lhs >> five;
    lhs >> six;
    lhs >> seven;
    lhs >> eight;
    lhs >> nine;
    lhs >> ten;
    lhs >> eleven;
    
    rhs = defendant(one, two, three, four, five, six, seven, eight, nine, ten, eleven);
    
    return lhs;
}

//sets one defendant equal to another
defendant& defendant::operator=(const defendant& rhs)
{
    //cout << "enter defendant assignment operator" << endl;
    if (this == &rhs)
        return *this;
    
    else{
        id = rhs.id;
        name = rhs.name;
        age = rhs.age;
        dob = rhs.dob;
        sex = rhs.sex;
        race = rhs.race;
        bail = rhs.bail;
        da = rhs.da;
        jailTime = rhs.jailTime;
        sentence = rhs.sentence;
        dock = rhs.dock;
    }
return *this;
}

//used to create a populated defendant object
defendant* defendant::create(){
    defendant* nd;
    nd = new defendant(this->id, this->name, this->age, this->dob, this->sex, this->race, this->bail, this->da, this->jailTime, this->sentence, this->dock);
    return nd;
}

