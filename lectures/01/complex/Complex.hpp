#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <ostream>

class Complex {
public:
  Complex();
  Complex(float re, float im);
  Complex(const Complex&) = default;
  
  float magnitude() const;
  Complex conj() const;
private:
  
  friend Complex operator+(const Complex&, const Complex&);
  friend Complex operator-(const Complex&, const Complex&);
  friend Complex operator*(const Complex&, const Complex&);
  friend Complex operator/(const Complex&, const Complex&);

  friend std::ostream& operator<<(std::ostream&, const Complex&);
  float real;
  float imag;
};

#endif
