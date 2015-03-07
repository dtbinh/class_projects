//
//  Matrix.cpp
//  DynamicMemory
//
//  Created by Jake Orben on 11/12/13.
//  Copyright (c) 2013 Jake Orben. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Matrix.h"
#include "Complex.h"

using namespace std;

//Matrix constructor
Matrix::Matrix (int h, int v)
{
    if (v <= 0 || h <=0) {
        cout << "Error, invalid array size.";
    }
    
    else{
        
        vert = v;
        hor = h;

        mtx = new Complex *[h];
    
        for (int i = 0; i < h; i++)
        {
            mtx[i] = new Complex [v];
        }

    }
}

//empty Matrix constructor
Matrix::Matrix()
{
    mtx = new Complex *[3];
    
    for (int i = 0; i < 3; i++)
    {
        mtx[i] = new Complex [4];
    }
    
    vert = 4;
    hor = 3;
}

//Matrix copy constructor redeclares a matrix and copies all items in another matrix to it
Matrix::Matrix(const Matrix& r)
{
    vert = r.vert;
    hor = r.hor;
    
    mtx = new Complex *[hor];
    
    for (int i = 0; i < hor; i++)
    {
        mtx[i] = new Complex [vert];
    }
    
    
    for (int i = 0; i < r.hor; i++) {
        for (int j = 0; j < r.vert; j++) {
            mtx[i][j] = r.mtx[i][j];
        }
    }
}

//Matrix deconstructor
Matrix::~Matrix()
{
 if (mtx !=NULL)
 {
    //deletes rows
    for (int i = 0; i < hor; i++)
    {
        delete mtx[i];
    }
    //deletes colunms
    delete []mtx;
 }
    
}

//outputs matrix
ostream& operator<<(ostream& lhs, const Matrix& rhs)
{
    for (int i = 0; i < rhs.hor; i++) {
        lhs << "[";
        for (int j = 0; j < rhs.vert; j++) {
            lhs << std::setw(10) << rhs.mtx[i][j];
        }
        lhs << "]" << endl;
    }
    return lhs;
}

//inputs matrix from user
istream& operator>>(istream& lhs, Matrix& rhs)
{
    int v, h;
    float r, im;
    lhs >> h;
    lhs >> v;
    Matrix newMat(h, v);
    for (int i = 0; i < newMat.hor; i++) {
        for (int j = 0; j < newMat.vert; j++) {
            lhs >> r;
            lhs >> im;
            newMat.mtx[i][j] = Complex(r, im);
        }
    }
    rhs = newMat;
    return lhs;
}

//adds to matrix from complex on right
const Matrix Matrix::operator+(const Complex& in)
{
    for (int i = 0; i < hor; i++) {
        for (int j = 0; j < vert; j++) {
            mtx[i][j] = mtx[i][j] + in;
        }
    }
            return *this;
}

//adds to matrix from other matrix
const Matrix Matrix::operator+(const Matrix& rhs)
{
    //checks for errors
    if (hor != rhs.hor || vert != rhs.vert) {
        cerr << "The arrays etered are not of the same size, please try again." << endl;
        return *this;
    }
    
    else{
        Matrix result;
    
        for (int i = 0; i < rhs.hor; i++) {
            for (int j = 0; j < rhs.vert; j++) {
                result.mtx[i][j] = (mtx[i][j] + rhs.mtx[i][j]);
            }
        }
        return result;
    }
}

//adds to matrix from complex on left
const Matrix operator+(const Complex& lhs, const Matrix& rhs)
{
    Matrix temp;
    temp = rhs;
        for (int i = 0; i < temp.hor; i++) {
            for (int j = 0; j < temp.vert; j++) {
                temp.mtx[i][j] = temp.mtx[i][j] + lhs;
            }
        }
    return temp;
}

//sets all items in matrix equal to complex number
Matrix& Matrix::operator=(const Complex& in)
{
    
    //deletes rows
    for (int i = 0; i < hor; i++)
    {
        delete mtx[i];
    }
    //deletes colunms
    delete []mtx;
    
    mtx = new Complex *[1];
    
    //creates new matrix of the requested size
    for (int i = 0; i < 1; i++)
    {
        mtx[i] = new Complex [1];
    }
    
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 1; j++) {
            mtx[i][j] = in;
        }
    }
    return *this;
}

//sets all items in matrix equal to items in another  matrix
Matrix& Matrix::operator=(const Matrix& rhs)
{
    if (this == &rhs)
        return *this;
    
    else{

        //deletes rows
        for (int i = 0; i < hor; i++)
        {
            delete mtx[i];
        }
        //deletes colunms
        delete []mtx;
        
        hor = rhs.hor;
        vert = rhs.vert;
        
        mtx = new Complex *[hor];
        
        //creates new matrix of the requested size
        for (int i = 0; i < hor; i++)
        {
            mtx[i] = new Complex [vert];
        }
        
        for (int i = 0; i < rhs.hor; i++) {
            for (int j = 0; j < rhs.vert; j++) {
                mtx[i][j] = rhs.mtx[i][j];
            }
        }
        return *this;
    }
    
}

//multiplies two matricies
const Matrix Matrix::operator*(const Matrix& two) const
{
    //creates holder
    Matrix result(hor, two.vert);
    //checks for errors
    if (hor != two.hor)
        cerr<<"these two matricies cannot be multiplied"<<endl;
    else
    {
        for (int i = 0; i < hor; i++) {
            for (int j = 0; j < hor; j++) {
                Complex sum = 0;
                for (int k = 0; k < vert; k++){
                    sum = sum + (mtx[i][k]*two.mtx[k][j]);
                }
                result.mtx[i][j] = sum;
            }
        }
    }
    return result;
}

//multiplies matrix by constant Complex on right
const Matrix Matrix::operator*(const Complex& one)
{
    Matrix result(vert, hor);
    for (int i = 0; i < hor; i++) {
        for (int j = 0; j < hor; j++) {
            Complex sum = 0;
            for (int k = 0; k < vert; k++){
                sum = sum + (mtx[i][k]*one);
            }
            result.mtx[i][j] = sum;
        }
    }
    return result;
}

//multiplies matrix by constnt Complex on left
const Matrix operator*(const Complex& lhs, const Matrix& rhs)
{
    Matrix result(rhs.hor, rhs.vert);
    for (int i = 0; i < rhs.hor; i++) {
        for (int j = 0; j < rhs.hor; j++) {
            Complex sum = 0;
            for (int k = 0; k < rhs.vert; k++){
                sum = sum + (rhs.mtx[i][k]*lhs);
            }
            result.mtx[i][j] = sum;
        }
    }
    return result;
}
