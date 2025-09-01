#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {
  // Default constructor
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _value(other._value) {
  std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int &other) : _value(other << _fractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &other) {
  // Use roundf to convert the float into the fixed-point representation
  // by multiplying by 2^_fractionalBits and rounding to nearest.
  _value = static_cast<int>(
      roundf(other * static_cast<float>(1 << _fractionalBits)));

  std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    _value = other._value;
  }
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
  os << obj.toFloat();
  return os;
}

bool Fixed::operator>(const Fixed &other) const {
  return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
  return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
  return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
  return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
  return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
  return _value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
  // We find wich of the two values has more fractional bits
  // and we align the other value to that before adding
  Fixed result;

  int selfFracBits = getFractionalBits();
  int otherFracBits = other.getFractionalBits();

  if (selfFracBits >= otherFracBits) {
    result._value = _value + (other._value << (selfFracBits - otherFracBits));
  } else {
    result._value = (_value << (otherFracBits - selfFracBits)) + other._value;
  }

  return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
  // We find wich of the two values has more fractional bits
  // and we align the other value to that before subtracting
  Fixed result;

  int selfFracBits = getFractionalBits();
  int otherFracBits = other.getFractionalBits();

  if (selfFracBits >= otherFracBits) {
    result._value = _value - (other._value << (selfFracBits - otherFracBits));
  } else {
    result._value = (_value << (otherFracBits - selfFracBits)) - other._value;
  }

  return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
  // Multiply two fixed-point values.
  // Use 64-bit intermediate to avoid overflow during multiplication,
  // then shift back by fractional bits. Add rounding for nearest.
  Fixed result;

  int fb = getFractionalBits();
  int64_t prod =
      static_cast<int64_t>(_value) * static_cast<int64_t>(other._value);

  // Rounding: add 0.5 in fixed-point (1 << (fb-1)) for positive values,
  // subtract for negative to round toward nearest.
  int64_t rounding =
      (prod >= 0) ? (int64_t(1) << (fb - 1)) : -(int64_t(1) << (fb - 1));

  prod = (prod + rounding) >> fb;

  result._value = static_cast<int>(prod);
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
  // Divide two fixed-point values.
  // Use 64-bit intermediate to avoid overflow during shifting,
  // then shift back by fractional bits. Add rounding for nearest.
  Fixed result;

  int fb = getFractionalBits();
  if (other._value == 0) {
    std::cerr << "Error: Division by zero in Fixed::operator/" << std::endl;
    result._value = 0;
    return result;
  }

  int64_t dividend = (static_cast<int64_t>(_value) << fb);
  int64_t divisor = static_cast<int64_t>(other._value);

  // Rounding: add half the divisor for positive values,
  // subtract for negative to round toward nearest.
  int64_t rounding = (dividend >= 0) ? (divisor / 2) : -(divisor / 2);

  dividend += rounding;

  int64_t quot = dividend / divisor;

  result._value = static_cast<int>(quot);
  return result;
}

Fixed &Fixed::operator++() {
  int new_value = _value + (1 << _fractionalBits);
  _value = new_value;
  return *this;
}

Fixed Fixed::operator++(int) {
  // Postfix increment
  Fixed temp = *this;
  _value += (1 << _fractionalBits);
  return temp;
}

Fixed &Fixed::operator--() {
  // Prefix decrement: subtract one unit in fixed-point (1 << fractional bits)
  _value -= (1 << _fractionalBits);
  return *this;
}

Fixed Fixed::operator--(int) {
  // Postfix decrement
  Fixed temp = *this;
  _value -= (1 << _fractionalBits);
  return temp;
}

float Fixed::toFloat() const {
  return static_cast<float>(_value) / (1 << _fractionalBits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}

int Fixed::getRawBits() const { return _value; }

int Fixed::getFractionalBits() { return _fractionalBits; }
