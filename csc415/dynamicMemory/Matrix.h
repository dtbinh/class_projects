//
//  Matrix.h
//  DynamicMemory
//
//  Created by Jake Orben on 11/12/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#ifndef __DynamicMemory__Matrix__
#define __DynamicMemory__Matrix__

#include <iostream>
#include "Complex.h"

using namespace std;

class Matrix
{
public:
    //
    //Pre:a matrix and a complex
    //Post:none
    //Info:sets array equal to a complex
    //
    Matrix& operator=(const Complex&);
    //
    //Pre:two matricies
    //Post:none
    //Info:sets a matrix equal to a matrix
    //
    Matrix& operator=(const Matrix&);
    //
    //Pre:two matrixes
    //Post:none
    //Info:multiplies a matrix and a matrix
    //
    const Matrix operator*(const Matrix&)const;
    //
    //Pre:Matrix and a complex
    //Post:none
    //Info:multiplies a matrix and a complex
    //
    const Matrix operator*(const Complex&);
    //
    //Pre:complex and a matrix
    //Post:none
    //Info:adds a complex to a matrix
    //
    const Matrix operator+(const Complex&);
    //
    //Pre:two Matrix
    //Post:none
    //Info:adds two matricies
    //
    const Matrix operator+(const Matrix&);
    
    //
    //Pre: complex and a matrix
    //Post:none
    //Info: adds a complex to a matrix
    //
    friend const Matrix operator+(const Complex&, const Matrix&);
    //
    //Pre:matrix
    //Post:none
    //Info: outputs an array
    //
    friend ostream& operator<<(ostream&, const Matrix&);
    //
    //Pre:matrix
    //Post:none
    //Info:outputs a matrix from user input
    //
    friend istream& operator>>(istream&, Matrix&);
    //
    //Pre: complex and matrix input
    //Post: none
    //Info: outputs the result of a matrix multiplied
    //
    friend const Matrix operator*(const Complex&, const Matrix&);

    
    //
    //Pre: none
    //Post: none
    //Info:makes a new matrix objext
    //
    Matrix();
    //
    //Pre:two ints
    //Post:none
    //Info:creates a new Matrix
    //
    Matrix(int, int);
    //
    //Pre:a matrix
    //Post:none
    //Info:creates a copy constructor matrix
    //
    Matrix(const Matrix&);
    //
    //Pre:none
    //Post:none
    //Info: deletes unused data
    //
    ~Matrix();
    

    
private:
    //Matrix Multiply(Matrix, int, int, Matrix, int, int);
    Complex **mtx;
    int vert;
    int hor;
    
};

#endif /* defined(__DynamicMemory__Matrix__) */
