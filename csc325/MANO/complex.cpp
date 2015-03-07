#include "complex.h"

Complex::Complex (float r, float i)
{
  real = r; 
  imaginary = i;
}

void Complex::setReal(float inR){
    real = inR;
}

void Complex::setImaginary(float inI){
    imaginary = inI;
}

float Complex::getReal() const{
    return real;
}

float Complex::getImaginary() const{
    return imaginary;
}

/*
void Complex::inputComplex()
{
  cin >> real;
  cin >> imaginary;
}
 */

ostream& operator<<(ostream& lhs, const Complex& rhs)
{
  lhs << rhs.real << " + " << rhs.imaginary << "i" << endl;
  return lhs;
}

istream& operator>>(istream& lhs, Complex& rhs)
{
  lhs >> rhs.real;
  lhs >> rhs.imaginary;
  return lhs;
}

const Complex Complex::operator+(const Complex& rhs) const
{
  Complex result;

  result.real = real + rhs.real;
  result.imaginary = imaginary + rhs.imaginary;
  
  return result;
}

const Complex operator+(float test, const Complex& rhs)
{
  Complex result;

  result.real = test + rhs.real;
  result.imaginary = rhs.imaginary;

  return result;
}
