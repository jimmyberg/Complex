
#ifndef _Complex_hpp_
#define _Complex_hpp_

#include <iostream>
#include <cmath>

class Complex{
public:
	Complex();
	Complex(float initR);
	Complex(float initR, float initI);
	float real, imaginary;
	
	//operators
	template <typename T> Complex operator+(T right) const;
	template <typename T> Complex operator-(T right) const;
	template <typename T> Complex operator*(T right) const;
	template <typename T> Complex operator/(T right) const;

	Complex operator+(const Complex &right) const;
	Complex operator-(const Complex &right) const;
	Complex operator*(const Complex &right) const;
	Complex operator/(const Complex &right) const;

	template <typename T> Complex& operator+=(T right);
	template <typename T> Complex& operator-=(T right);
	template <typename T> Complex& operator*=(T right);
	template <typename T> Complex& operator/=(T right);

	Complex& operator+=(const Complex& right);
	Complex& operator-=(const Complex& right);
	Complex& operator*=(const Complex& right);
	Complex& operator/=(const Complex& right);

	//Functuions
	float absolute();
	float argument();
};

std::ostream& operator<<(std::ostream& os, const Complex& complex);


Complex::Complex(): real(0), imaginary(0){}
Complex::Complex(float initR): real(initR), imaginary(0){}
Complex::Complex(float initR, float initI): real(initR), imaginary(initI){}

template <typename T>
Complex Complex::operator+(T right) const{
	return Complex(real + right, imaginary);
}
template <typename T>
Complex Complex::operator-(T right) const{
	return Complex(real - right, imaginary);
}
template <typename T>
Complex Complex::operator*(T right) const{
	return Complex(real * right, imaginary * right);
}
template <typename T>
Complex Complex::operator/(T right) const{
	return Complex(real / right, imaginary / right);
}

Complex Complex::operator+(const Complex &right) const{
	return Complex(
		real + right.real,
		imaginary + right.imaginary
		);
}
Complex Complex::operator-(const Complex &right) const{
	return Complex(
		real - right.real,
		imaginary - right.imaginary
		);
}
Complex Complex::operator*(const Complex &right) const{
	return Complex(
		(real * right.real) - (imaginary * right.imaginary), 
		(real * right.imaginary) + (imaginary * right.real)
		);
}
Complex Complex::operator/(const Complex &right) const{
	//Calculate it once.
	float divider = (right.real * right.real) + (right.imaginary * right.imaginary); 
	return Complex(
		((real * right.real) + (imaginary * right.imaginary)) / divider,
		((imaginary * right.real) - (real * right.imaginary)) / divider
		);
}

template <typename T>
Complex& Complex::operator+=(T right){
	real += right.real;
	return *this;
}
template <typename T>
Complex& Complex::operator-=(T right){
	real -= right.real;
	return *this;
}
template <typename T>
Complex& Complex::operator*=(T right){
	real *= right;
	imaginary *= right;
	return *this;
}
template <typename T>
Complex& Complex::operator/=(T right){
	real /= right;
	imaginary /= right;
	return *this;
}

Complex& Complex::operator+=(const Complex& right){
	real += right.real;
	imaginary += right.imaginary;
	return *this;
}
Complex& Complex::operator-=(const Complex& right){
	real -= right.real;
	imaginary -= right.imaginary;
	return *this;
}
Complex& Complex::operator*=(const Complex& right){
	float realConserved = real;
	real = (real * right.real) - (imaginary * right.imaginary);
	imaginary = (realConserved * right.imaginary) + (right.real * imaginary);
	return *this;
}
Complex& Complex::operator/=(const Complex& right){
	float realConserved = real;
	float divider = (right.real * right.real) + (right.imaginary * right.imaginary); 
	real 		= ((real * right.real) + (imaginary * right.imaginary)) / divider;
	imaginary 	= ((imaginary * right.real) - (realConserved * right.imaginary)) / divider;
	return *this;
}

float Complex::absolute(){
	return sqrt((real*real) + (imaginary*imaginary));
}
float Complex::argument(){
	return std::atan2(imaginary, real);
}

std::ostream& operator<<(std::ostream& os, const Complex& complex){
    os << complex.real;
    if(complex.imaginary >= 0)
    	std::cout << '+';
    std::cout << complex.imaginary << 'i';
    return os;
}


#endif