#include "Complex.hpp"

// Default constructor - initialise to zero
Complex::Complex() : real(0), imag(0) {
}

// Value c'tor
Complex::Complex(float re, float im) : real(re), imag(im) {
}

float Complex::magnitude() const {
  return real*real + imag*imag;
}

Complex Complex::conj() const {
  return Complex{real, -imag};
}

Complex operator+(const Complex& a, const Complex& b) {
  return Complex{a.real + b.real, a.imag + b.imag};
}

Complex operator-(const Complex& a, const Complex& b) {
  return Complex{a.real - b.real, a.imag - b.imag};
}
Complex operator*(const Complex& a, const Complex& b) {
  return Complex{a.real*b.real - a.imag*b.imag, a.imag*b.real + a.real*b.imag};
}

// ans = a / b = a b* / (b b*)
Complex operator/(const Complex& a, const Complex& b) {
  Complex ans = a * b.conj();
  auto b_mag = b.magnitude();
  ans.real /= b_mag;
  ans.imag /= b_mag;
  return ans;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << c.real << " + " << c.imag;
  return os;
}

