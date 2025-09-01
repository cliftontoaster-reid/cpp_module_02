#include "Fixed.hpp"
#include <iostream>

// Helper to print raw fixed-point internals
static void printRaw(const Fixed &obj, const char *name) {
  int raw = obj.getRawBits();
  unsigned int uraw = static_cast<unsigned int>(raw);
  int fb = Fixed::getFractionalBits();
  int frac_raw = raw & ((1 << fb) - 1);
  std::cout << name << " raw: " << raw << " (hex 0x" << std::hex << uraw
            << std::dec << ")";
  std::cout << ", fractional raw: " << frac_raw << " (binary ";
  for (int i = fb - 1; i >= 0; --i)
    std::cout << ((frac_raw >> i) & 1);
  std::cout << ") -> " << static_cast<float>(frac_raw) / (1 << fb) << std::endl
            << std::endl;
}

Fixed add(Fixed x, Fixed y) { return Fixed(x.toFloat() + y.toFloat()); }

int main() {
  std::cout << "=== Fixed Class Demo ===" << std::endl;

  // Default constructor
  Fixed a;
  std::cout << "a: " << a << std::endl;
  printRaw(a, "a");

  // Int constructor
  Fixed b(10);
  std::cout << "b: " << b << " (from int 10)" << std::endl;
  printRaw(b, "b");

  // Float constructor
  Fixed c(42.42f);
  std::cout << "c: " << c << " (from float 42.42)" << std::endl;
  printRaw(c, "c");

  // Copy constructor
  Fixed d = b;
  std::cout << "d: " << d << " (copy of b)" << std::endl;
  printRaw(d, "d");

  // Assignment operator
  a = c;
  std::cout << "a after assignment from c: " << a << std::endl;
  printRaw(a, "a (after assignment)");

  // Arithmetic demo using copy constructors
  Fixed result = add(b, c);
  std::cout << "b + c = " << result << std::endl;
  printRaw(result, "b + c");

  // Explicit toFloat conversion
  std::cout << "c as float: " << c.toFloat() << std::endl;
  printRaw(c, "c (final)");

  std::cout << "=== End of Demo ===" << std::endl;

  return 0;
}