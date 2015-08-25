
#include "Complex.hpp"

Complex::Complex(float initR, float initI): real(initR), imaginary(initI){}

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

Complex& Complex::operator+=(const Complex &right){
	real += right.real;
	imaginary += right.imaginary;
	return *this;
}
Complex& Complex::operator-=(const Complex &right){
	real -= right.real;
	imaginary -= right.imaginary;
	return *this;
}
Complex& Complex::operator*=(const Complex &right){
	float realConserved = real;
	real = (real * right.real) - (imaginary * right.imaginary);
	imaginary = (realConserved * right.imaginary) + (right.real * imaginary);
	return *this;
}
Complex& Complex::operator/=(const Complex &right){
	float realConserved = real;
	float divider = (right.real * right.real) + (right.imaginary * right.imaginary); 
	real 		= ((real * right.real) + (imaginary * right.imaginary)) / divider;
	imaginary 	= ((imaginary * right.real) - (realConserved * right.imaginary)) / divider;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex){
    os << complex.real << '+' << complex.imaginary << 'i';
    return os;
}