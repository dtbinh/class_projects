//
//  roster.cpp
//  finalProject
//
//  Created by Jake Orben on 12/8/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "roster.h"

using namespace std;
//constructor for roster
//holds person array
roster::roster (int size)
{
    if (size <=0) {
        cout << "Error, invalid array size.";
    }
    
    else{
        length = size;
        total = 0;
        ary = new person*[size];
        for (int i = 0; i < length; i++) {
            ary[i] = NULL;
        }
        
    }
}

//empty roster constructor
roster::roster()
{
    length = 3;
    total = 3;
    ary = new person*[3];
    for (int i = 0; i < 3; i++) {
        ary[i] = NULL;
    }
}



//sets item in array equal to items incomming item
roster& roster::operator=(const roster& rhs)
{
    if (this == &rhs)
        return *this;
    
    else{
        
        
        for (int i = 0; i < rhs.length; i++) {
            delete ary[i];
        }
        //deletes array
        delete []ary;
        
        length = rhs.length;
        total = rhs.total;
        
        ary = new person*[length];
        
        for (int i = 0; i < rhs.length; i++) {
            ary[i] = NULL;
        }
        
        for (int i = 0; i < rhs.total; i++) {
            person *np;
            np = rhs.ary[i]->create();
            ary[i] = np;
            
        }
        return *this;
    }
    
}

//array deconstructor
roster::~roster()
{
    if (ary !=NULL)
    {
        //for some reason It will print from 122 objects but will only delete 120 objects, I don't know why
        /*
        for (int i = 0; i < total; i++) {
            cout << "test!!!!!!!" << i << endl;
            cout << ary[i]->printInfo() << endl;
        }
         */
        for (int i = 0; i < length; i++) {
            delete ary[i];
            //cout << i << endl;
        }
        //deletes colunms
        delete []ary;
    }
    
}

//roster copy constructor
roster::roster(const roster& r)
{
    length = r.length;
    total = r.total;
    
    ary = new person*[length];
    
    //have to set all items eqal to null
    for (int i = 0; i < r.length; i++) {
        ary[i] = NULL;
    }
    
    for (int i = 0; i < r.total; i++) {
        person *np;
        np = r.ary[i]->create();
        ary[i] = np;
    }
}

//prints out all information
string roster::printInfo(){
    int i = 0;
    ostringstream os;
    while (i < total) {
        os << ary[i]->printInfo();
        i++;
    }
    return os.str();
}


//reads in data from file
void roster::inputFmFile() {
    
	//initilizes variables
	string inputFile;
	total = 0;
    
	//gets users requested file
	cout << "Enter the name of the file you wish to import: " << endl;
	cin >> inputFile;
    
	//creates the file stream for the file
	ifstream inFile;
    
    //checks if file is openable
	inFile.open(inputFile.c_str());
    if (inFile.fail()){
        cerr << "there was an error opening the file" << endl;
        inFile.clear();
        exit(0);
    }
    
	//haha I got to put string cheese in a real program
	string cheese;
    
	//skips the first line
	getline(inFile, cheese, '\r');
    
	//while not end of file
	while (!inFile.eof()) {
        string one;
		string two;
		string three;
		string four;
		string five;
		string six;
        string seven;
        string eight;
        string nine;
        string ten;
        string eleven;
        string twelve;
        string thirteen;
        string fourteen;
        string fifteen;
        string sixteen;
        string seventeen;
        string eighteen;
        string nineteen;

        getline(inFile, one, ',');
        getline(inFile, two, ',');
        getline(inFile, three, ',');
        getline(inFile, four, ',');
        getline(inFile, five, ',');
        getline(inFile, six, ',');
        getline(inFile, seven, ',');
        getline(inFile, eight, ',');
        getline(inFile, nine, ',');
        getline(inFile, ten, ',');
        getline(inFile, eleven, ',');
        getline(inFile, twelve, ',');
        getline(inFile, thirteen, ',');
        getline(inFile, fourteen, ',');
        getline(inFile, fifteen, ',');
        getline(inFile, sixteen, ',');
        getline(inFile, seventeen, ',');
        getline(inFile, eighteen, ',');
        getline(inFile, nineteen, '\r');
        
        docket dck(seven, eight, nine, ten, thirteen, fourteen);
        ary[total] = new defendant (atoi(one.c_str()), two, atoi(three.c_str()),  four, five, six, eleven, twelve, eighteen, nineteen, dck);
        total++;
        ary[total] = new judge (fifteen, sixteen, seventeen);
        total++;
        
	}
}

//adds to array from new person
roster roster::add(person* in)
{
    //cout << total << endl;
    //cout << length << endl;
    if(total < length){
        ary[total] = in;
        total++;
    }
    else{
        cerr << "the array is at capacity and cannot take any new data." << endl;
    }
    return *this;
}





