//
//  main.cpp
//  floatTest
//
//  Created by Jake Orben on 11/25/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{

    float one;
    float two;
    float three;
    float four;
    
    one = 1;
    two = 123.13;
    three = 12.3452;
    four = 0.12345274567;
    
    // insert code here...
    cout << "one " << one << ", two " << two << ", three " << three << ", four " << four;
    
    one = one * four;
    three = two + one;
    four = three;
    
    cout << "one " << one << ", two " << two << ", three " << three << ", four " << four;
    return 0;
}

