
#ifndef _Complex_hpp_
#define _Complex_hpp_

#include <iostream>
#include <cmath>

class Complex{
public:
	Complex(float initR, float initI);
	float real, imaginary;
	
	//operators
	Complex operator+(const Complex &right) const;
	Complex operator-(const Complex &right) const;
	Complex operator*(const Complex &right) const;
	Complex operator/(const Complex &right) const;

	Complex& operator+=(const Complex &right);
	Complex& operator-=(const Complex &right);
	Complex& operator*=(const Complex &right);
	Complex& operator/=(const Complex &right);
};

std::ostream& operator<<(std::ostream& os, const Complex& complex);

#endif