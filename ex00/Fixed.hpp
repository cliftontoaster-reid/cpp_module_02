#include <iostream>

class Fixed {
private:
  int _value;
  static const int _fractionalBits = 8;

public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed(const int &other);
  Fixed(const float &other);

  friend std::ostream &operator<<(std::ostream &os, const Fixed &obj);
  float toFloat() const;

  // Accessors to extract the raw fixed-point integer and fractional bits
  int getRawBits() const;
  static int getFractionalBits();

  Fixed &operator=(const Fixed &other);
  ~Fixed();
};