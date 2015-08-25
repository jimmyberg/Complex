
#include "Complex.hpp"

Complex Complex::operator+(const Complex &right) const{
	Complex temp(*this);
	temp += right;
	return temp;
}
Complex Complex::operator-(const Complex &right) const{
	Complex temp(*this);
	temp -= right;
	return temp;
}
Complex Complex::operator*(const Complex &right) const{
	Complex temp(*this);
	temp *= right;
	return temp;
}
Complex Complex::operator/(const Complex &right) const{
	Complex temp(*this);
	temp /= right;
	return temp;
}

Complex& Complex::operator+=(const Complex &right){
	real += right.r;
	imaginary += right.imaginary;
	return *this;
}
Complex& Complex::operator-=(const Complex &right){
	real -= right.r;
	imaginary -= right.imaginary;
	return *this;
}
Complex& Complex::operator*=(const Complex &right){
	float realConserved = real;
	real = pow(real, 2) - pow(right.real, 2);
	imaginary = (realConserved * right.imaginary) + (right.real * imaginary);
	return *this;
}
Complex& Complex::operator/=(const Complex &right){
	real += right.r;
	imaginary += right.imaginary;
	return *this;
}
