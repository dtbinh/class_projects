#if!defined(COMPLEX_H)
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{

 private:
    //real number for complex
    float real;
    //imaginary number for complex
    float imaginary;
 public:
    
    //
    //Pre:two floats
    //Post:none
    //Info:creates a complex object
    //
    Complex (float = 0.0, float = 0.0);
    //
    //Pre:none
    //Post:none
    //Info:inputs a complex
    //
    void inputComplex();
    //
    //Pre:two complexes
    //Post:none
    //Info:adds two complexes
    //
    const Complex operator+(const Complex&) const;
    //
    //Pre:two complexes
    //Post:none
    //Info:multiplies a complex and a complex
    //
    const Complex operator*(const Complex&) const;
    //
    //Pre:none
    //Post:none
    //Info:gets real
    //
    double getReal() const;
    //
    //Pre:float
    //Post:none
    //Info:sets real
    //
    void setReal(float);
    //
    //Pre:none
    //Post:none
    //Info:gets imaginary
    //
    double getImaginary() const;
    //
    //Pre:float
    //Post:none
    //Info:sets Imaginary
    //
    void setImaginary(float);
    //
    //Pre:a complex
    //Post:none
    //Info:copy constructor
    //
    Complex(const Complex&);

    //
    //Pre:float and Complex
    //Post:none
    //Info:adds two complexes
    //
    friend const Complex operator+(float, const Complex&);
    //
    //Pre:float and complex on right
    //Post:none
    //Info:adds a complex and a float
    //
    friend const Complex operator+(const Complex&, float);
    //
    //Pre:Complex
    //Post:none
    //Info:outputs Complex
    //
    friend ostream& operator<<(ostream&, const Complex&);
    //
    //Pre:Complex
    //Post:none
    //Info:inputs complex data
    //
    friend istream& operator>>(istream&, Complex&);

};

#endif
