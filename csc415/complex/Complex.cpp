#include "Complex.h"

//default constructor
Complex::Complex (float r, float i)
{
    real = r;
    imaginary = i;
}

//input from user
void Complex::inputComplex()
{
  cin >> real;
  cin >> imaginary;
}

//copy constructor
Complex::Complex(const Complex& r)
{
    real = r.real;
    imaginary = r.imaginary;
}

//outputs complex numbr
ostream& operator<<(ostream& lhs, const Complex& rhs)
{
  lhs << rhs.real << " + " << rhs.imaginary << "i";
  return lhs;
}

//inputs items into complex
istream& operator>>(istream& lhs, Complex& rhs)
{
  lhs >> rhs.real;
  lhs >> rhs.imaginary;
  return lhs;
}

//adds two complexes
const Complex Complex::operator+(const Complex& rhs) const
{
  Complex result;

  result.real = real + rhs.real;
  result.imaginary = imaginary + rhs.imaginary;
  
  return result;
}

//adds to complex from a float on left
const Complex operator+(float test, const Complex& rhs)
{
  Complex result;

    result.real = test + rhs.real;
    result.imaginary = rhs.imaginary;

  return result;
}

//adds to complex from a float on right
const Complex operator+(const Complex& rhs, float test)
{
    Complex result;
    
    result.real = test + rhs.real;
    result.imaginary = rhs.imaginary;
    
    return result;
}

//multiplies two complex numbers
const Complex Complex::operator*(const Complex& rhs) const
{
    Complex result;
    
    result.real = (real * rhs.real) - (imaginary * rhs.imaginary);
    
    result.imaginary = (real * rhs.imaginary) + (rhs.real * imaginary);
    
    return result;
}
