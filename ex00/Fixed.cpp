#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _value(0) {
  // Default constructor
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int& other) : _value(other << _fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float& other) {
  _value = static_cast<int>(
      floor(static_cast<double>(other) * (1 << _fractionalBits) + 0.5));

  std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    _value = other._value;
  }
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
  os << obj.toFloat();
  return os;
}

float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::getRawBits() const { return _value; }

int Fixed::getFractionalBits() { return _fractionalBits; }

void Fixed::setRawBits(int const raw) { _value = raw; }
