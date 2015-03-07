// exPtrs.cpp
// Programmed By: Monisha Pulimood to illustrate working with pointers
// DO: Add maintenance documentation

#include <iostream>
#include "complex.h"

using namespace std;

// Instructions:
// Follow the instructions in comments that begin with "DO:".
// Insert the correct code as appropriate.
// Be sure to *replace* ..... with valid C++ code.

int main (void)
{
/*
    ********************* Begin Part 1 *************************
    cout << "\nPart 1 - Pointer variables" << endl;
    
    int a, b;			// integer variables
                        // DO: Declare pointer variables ptrA and ptrB that refer to the integer data
    
    // DO: Complete the cout statements to reflect the display messages
    cout << "Pointer ptrA has the data: " << ........  << endl;
    cout << "Pointer ptrB has the data: " << ........  << endl;
    
    
    a = 225;
    // DO: assign the memory address of a to ptrA, ie make ptrA
    // 'point to' a
    
    b = 167;
    // DO: assign the memory address of b to ptrB, ie make ptrB
    // 'point to' b
    
    
    // DO: Complete the cout statements to reflect the display messages
    cout << "\nVariable a is stored at address  " << ...... << endl;
    cout << "Pointer ptrA is stored at address " << ...... << endl;
    cout << "Variable b is stored at address  " << ........ << endl;
    cout << "Pointer ptrB is stored at address " << ........ << endl;
    cout << "Draw diagrams to illustrate the above " << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
    
    //DO: use 'a' to display the value
    cout << "\n Using a, Variable a holds the value " << ........ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "Pointer ptrA holds the value " << ........ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "\n Using ptrA, Variable a holds the value " << ........ << endl;
    cout << endl << endl;
    
    
    // DO: Assign ptrA to ptrB;
    
    
    cout << "\nAfter 1st assignment operation:  " << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "\nThe data stored in ptrA " << " is  " << ........ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "Using ptrA, the data stored in a " << " is " << ........ << endl;
    
    //DO: use 'a' to display the value
    cout << "Using a, the data stored in a " << " is " << ........ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "\n ptrA is at location " << ................ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "\n Using ptrA, a is at location " << ................ << endl;
    
    //DO: use 'a' to display the value
    cout << "\n Using a, a is at location " << ................ << endl;
    
    //DO: use 'ptrB' to display the value
    cout << "The data stored in ptrB " << " is " << ........ << endl;
    
    //DO: use 'ptrB' to display the value
    cout << "Using ptrB, the data stored in b " << " is " << ........ << endl;
    
    //DO: use 'b' to display the value
    cout << "Using b, the data stored in b " << " is " << ........ << endl;
    
    //DO: use 'ptrB' to display the value
    cout << "\n Using ptrB, b is at location " << ................ << endl;
    
    //DO: use 'b' to display the value
    cout << "\n Using b, b is at location " << ................ << endl;
    
    cout << "Draw diagrams to illustrate the above and explain what happened" << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
    
    //DO: Use ptrA to change the value of 'a' to 987
    
    
    cout << "\nAfter 2nd assignment operation " << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "\nThe data stored in ptrA " << " is  " << ........ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "Using ptrA, the data stored in a " << " is " << ........ << endl;
    
    //DO: use 'a' to display the value
    cout << "Using a, the data stored in a " << " is " << ........ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "\n ptrA is at location " << ................ << endl;
    
    //DO: use 'ptrA' to display the value
    cout << "\n Using ptrA, a is at location " << ................ << endl;
    
    //DO: use 'a' to display the value
    cout << "\n Using a, a is at location " << ................ << endl;
    
    //DO: use 'ptrB' to display the value
    cout << "The data stored in ptrB " << " is " << ........ << endl;
    
    //DO: use 'ptrB' to display the value
    cout << "Using ptrB, the data stored in b " << " is " << ........ << endl;
    
    //DO: use 'b' to display the value
    cout << "Using b, the data stored in b " << " is " << ........ << endl;
    
    //DO: use 'ptrB' to display the value
    cout << "\n Using ptrB, b is at location " << ................ << endl;
    
    //DO: use 'b' to display the value
    cout << "\n Using b, b is at location " << ................ << endl;
    
    cout << "Draw diagrams to illustrate the above and explain what happened" << endl << endl;
    cout << endl << endl;
    cout << endl << endl;
*/    
    /********************** End Part 1 ***************************/

    //DO: Comment out the code for Part 1 when doing Part 2
    
    //DO: Uncomment the code below for Part 2
    
    /********************* Begin Part 2 ***************************/
     
     cout << "\nPart 2 - Dynamic Memory Management" << endl;
     // DO: Declare pointer variables ptrC and ptrD that refer to the integer data
     
	 int *ptrC, *ptrD;
	 ptrC = 0;
	 ptrD = 0;
	 
     // DO: Complete the cout statements to reflect the display messages
     cout << "Pointer ptrC has the data: " << ptrC << endl;
     cout << "Pointer ptrD has the data: " << ptrD  << endl;
     
     // DO: Dynamically allocate space for an integer variable.
     // DO: Make ptrC 'point to' this dynamic variable.
	 ptrC = new int;
     // DO: Dynamically allocate space for another integer variable.
     // DO: Make ptrD 'point to' this dynamic variable.
	 ptrD = new int;
	 
     // DO: Complete the cout statements to reflect the display messages
     cout << "Using ptrC, the dynamic variable is at location " << ptrC  << endl;
     cout << "Using ptrD, the dynamic variable is at location " << ptrD  << endl;
     
     // DO: Use pointers ptrC and ptrD to display the data stored in the
     //     dynamic variables
     cout << "Using ptrC, the data store in the dynamic variable is " << *ptrC  << endl;
     cout << "Using ptrD, the data store in the dynamic variable is " << *ptrD  << endl;
     
     cout << "Draw diagrams to illustrate the above " << endl << endl;
     cout << endl << endl;
     cout << endl << endl << endl;
     
     // DO: Use pointer ptrC to store the value 125 in one dynamic variable
     // DO: Use pointer ptrD to store the value 504 in the other dynamic variable
     *ptrC = 125;
	 *ptrD = 504;
     
     // DO: Use pointers ptrC and ptrD to display the data now stored in the
     //     dynamic variables
     cout << "Using ptrC, the data stored in the dynamic variable is " << *ptrC  << endl;
     cout << "Using ptrD, the data stored in the dynamic variable is " << *ptrD  << endl;
     
     cout << "Draw diagrams to illustrate the above and explain what happened" << endl << endl;
     
     // DO: Assign ptrC to ptrD;
    delete ptrC;
    ptrC = ptrD;
     
     cout << "\nAfter the assignment operation:  " << endl;
     
     //DO: use 'ptrC' to display the value
     cout << "\nUsing ptrC, the dynamic variable is at location " << ptrC << endl;
     
     //DO: use 'ptrC' to display the value
     cout << "Using ptrC, the data stored in the dynamic variable is " << *ptrC << endl;
     
     //DO: use 'ptrD' to display the value
     cout << "\nUsing ptrD, the dynamic variable is at location " << ptrD << endl;
     
     //DO: use 'ptrD' to display the value
     cout << "Using ptrD, the data stored in the dynamic variable is " << *ptrD << endl;
     
     cout << "Draw diagrams to illustrate the above and explain what happened" << endl << endl;
     cout << endl << endl;
     cout << endl << endl << endl;
    

    delete ptrD;
     
     // DO: Release any dynamically allocated memory
     
     /********************** End Part 2 ***************************/
    
    //DO: Uncomment the code below for Part 3
    
    // ******************** Begin Part 3 **************************
    
    cout << "\nPart 3 - Dynamically Instantiating Objects " << endl;
    // DO: Declare pointer variables cmpPtr1 and cmpPtr2 that refer to Complex objects
    
    Complex *cmpPtr1;
    Complex *cmpPtr2;
    
    // DO: Complete the cout statements to reflect the display messages
    cout << "Pointer cmpPtr1 has the data: " << cmpPtr1  << endl;
    cout << "Pointer cmpPtr2 has the data: " << cmpPtr2  << endl;
    
    // DO: Dynamically allocate space for a complex object and make
    //     cmpPtr1 'point to' this dynamic object.
    
    cmpPtr1 = new Complex;
    
    // DO: Dynamically allocate space for another complex object and make
    //     cmpPtr2 'point to' this dynamic object.
    
    cmpPtr2 = new Complex;
    
    // DO: Complete the cout statements to reflect the display messages
    cout << "Using cmpPtr1, the dynamic variable is at location " << cmpPtr1  << endl;
    cout << "Using cmpPtr2, the dynamic variable is at location " << cmpPtr2  << endl;
    
    // DO: Use pointers ptrC and ptrD to display the data stored in the
    //     dynamic variables
    cout << "Using cmpPtr1, the data stored in the dynamic Complex object is " << *cmpPtr1  << endl;
    cout << "Using cmpPtr2, the data stored in the dynamic Complex object is " << *cmpPtr2  << endl;
    
    cout << "Draw diagrams to illustrate the above " << endl << endl;
    cout << endl << endl;
    cout << endl << endl << endl;
    
    // DO: Use the pointers to enable the user to input new data into the Complex objects.
    
    cout << "please enter a real value: ";
    float x = 0;
    cin >> x;
    (*cmpPtr1).setReal(x);
    
    cout << "please enter an imaginary value: ";
    cin >> x;
    (*cmpPtr1).setImaginary(x);
    
    cout << "please enter an real value: ";
    cin >> x;
    (*cmpPtr2).setReal(x);

    cout << "please enter an imaginary value: ";
    cin >> x;
    (*cmpPtr2).setImaginary(x);
    
    // DO: Use the pointers to display the data now stored in the Complex objects.
    cout << "Using cmpPtr1, the data stored in the dynamic Complex object is " << (*cmpPtr1).getReal() << " + " << (*cmpPtr1).getImaginary() << "i" << endl;
    cout << "Using cmpPtr2, the data stored in the dynamic Complex object is " << (*cmpPtr2).getReal() << " + " << (*cmpPtr2).getImaginary() << "i"  << endl;
    
    cout << "Draw diagrams to illustrate the above and explain what happened" << endl << endl;
    
    delete cmpPtr1;
    delete cmpPtr2;
    
    // DO: Release any dynamically allocated memory
    
    /********************** End Part 3 ***************************/
    return 0;
}     



