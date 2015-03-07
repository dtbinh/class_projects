#if!defined(COMPLEX_H)
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{

 private:
  float real;
  float imaginary;
 public: 
  Complex (float = 0.0, float = 0.0);
  void inputComplex();
  const Complex operator+(const Complex&) const;
    void setReal(float);
    void setImaginary(float);
    float getReal() const;
    float getImaginary() const;

  friend const Complex operator+(float, const Complex&);
  friend ostream& operator<<(ostream&, const Complex&);
  friend istream& operator>>(istream&, Complex&);

};

#endif
