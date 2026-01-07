#pragma once

#include <iostream>

class Fixed {
 private:
  int _value;
  static const int _fractionalBits = 8;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed(const int& other);
  Fixed(const float& other);

  // Define FIXED_DEBUG to enable constructor/destructor debug prints.
  // Example: add -DFIXED_DEBUG to CXXFLAGS in Makefile to enable.

  float toFloat() const;
  int toInt() const;

  // Accessors to extract the raw fixed-point integer and fractional bits
  int getRawBits() const;
  static int getFractionalBits();

  // Comparison operators
  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  // Arithmetic operators
  Fixed operator+(const Fixed& other) const;
  Fixed operator-(const Fixed& other) const;
  Fixed operator*(const Fixed& other) const;
  Fixed operator/(const Fixed& other) const;

  // Increment and decrement operators
  Fixed& operator++();    // Prefix increment
  Fixed operator++(int);  // Postfix increment
  Fixed& operator--();    // Prefix decrement
  Fixed operator--(int);  // Postfix decrement

  // Min and max functions
  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

  Fixed& operator=(const Fixed& other);
  ~Fixed();
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
