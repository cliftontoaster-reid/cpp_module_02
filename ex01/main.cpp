#include <iostream>

#include "Fixed.hpp"

// Helper to print raw fixed-point internals
static void printRaw(const Fixed& obj, const char* name) {
  int raw = obj.getRawBits();
  unsigned int uraw = static_cast<unsigned int>(raw);
  int fb = Fixed::getFractionalBits();
  int frac_raw = raw & ((1 << fb) - 1);
  std::cout << name << " raw: " << raw << " (hex 0x" << std::hex << uraw
            << std::dec << ")";
  std::cout << ", fractional raw: " << frac_raw << " (binary ";
  for (int i = fb - 1; i >= 0; --i) std::cout << ((frac_raw >> i) & 1);
  std::cout << ") -> " << static_cast<float>(frac_raw) / (1 << fb) << std::endl
            << std::endl;
}

int main() {
  std::cout << "========================================" << std::endl;
  std::cout << "         Fixed Class Comprehensive Demo" << std::endl;
  std::cout << "========================================" << std::endl
            << std::endl;

  // Constructors
  Fixed defaultObj;
  Fixed fromInt(10);
  Fixed fromFloat(42.42f);
  Fixed copyOfInt = fromInt;

  std::cout << "Constructors:" << std::endl;
  std::cout << " defaultObj        : " << defaultObj << " (default)"
            << std::endl;
  printRaw(defaultObj, "defaultObj");

  std::cout << " fromInt (10)      : " << fromInt << std::endl;
  printRaw(fromInt, "fromInt");

  std::cout << " fromFloat (42.42) : " << fromFloat << std::endl;
  printRaw(fromFloat, "fromFloat");

  std::cout << " copyOfInt (copy)  : " << copyOfInt << std::endl;
  printRaw(copyOfInt, "copyOfInt");

  // Assignment
  defaultObj = fromFloat;
  std::cout << "After assignment defaultObj = fromFloat: " << defaultObj
            << std::endl;
  printRaw(defaultObj, "defaultObj (after assignment)");

  // Arithmetic
  std::cout << std::endl << "Arithmetic operations:" << std::endl;
  Fixed sum = fromInt + fromFloat;
  std::cout << " 10 + 42.42 = " << sum << std::endl;
  printRaw(sum, "10 + 42.42");

  Fixed diff = fromFloat - fromInt;
  std::cout << " 42.42 - 10 = " << diff << std::endl;
  printRaw(diff, "42.42 - 10");

  Fixed prod = fromInt * fromFloat;
  std::cout << " 10 * 42.42 = " << prod << std::endl;
  printRaw(prod, "10 * 42.42");

  Fixed half(0.5f);
  Fixed scaled = fromFloat * half;
  std::cout << " 42.42 * 0.5 = " << scaled << std::endl;
  printRaw(scaled, "42.42 * 0.5");

  Fixed quot = fromFloat / fromInt;
  std::cout << " 42.42 / 10 = " << quot << std::endl;
  printRaw(quot, "42.42 / 10");

  // toFloat and raw accessors
  std::cout << std::endl << "Conversions & accessors:" << std::endl;
  std::cout << " fromFloat.toFloat(): " << fromFloat.toFloat() << std::endl;
  std::cout << " getRawBits(fromFloat): " << fromFloat.getRawBits()
            << std::endl;
  std::cout << " getFractionalBits(): " << Fixed::getFractionalBits()
            << std::endl;

  // Comparisons
  std::cout << std::endl << "Comparisons:" << std::endl;
  std::cout << " fromInt < fromFloat : " << (fromInt < fromFloat) << std::endl;
  std::cout << " fromInt <= copyOfInt: " << (fromInt <= copyOfInt) << std::endl;
  std::cout << " fromInt == copyOfInt: " << (fromInt == copyOfInt) << std::endl;
  std::cout << " fromFloat != fromInt : " << (fromFloat != fromInt)
            << std::endl;

  // Increment / Decrement
  std::cout << std::endl << "Increment / Decrement:" << std::endl;
  Fixed incDemo(1.0f);
  std::cout << " start: " << incDemo << std::endl;
  std::cout << " prefix ++: " << ++incDemo << std::endl;
  std::cout << " after prefix: " << incDemo << std::endl;
  std::cout << " postfix ++: " << incDemo++ << std::endl;
  std::cout << " after postfix: " << incDemo << std::endl;
  std::cout << " prefix --: " << --incDemo << std::endl;
  std::cout << " postfix --: " << incDemo-- << std::endl;
  std::cout << " final: " << incDemo << std::endl;
  printRaw(incDemo, "incDemo (final)");

  // min / max
  std::cout << std::endl << "Min / Max helpers:" << std::endl;
  Fixed& rmin = Fixed::min(fromInt, fromFloat);
  const Fixed& cmin = Fixed::min(fromInt, fromFloat);
  Fixed& rmax = Fixed::max(fromInt, fromFloat);
  const Fixed& cmax = Fixed::max(fromInt, fromFloat);
  std::cout << " min (non-const ref) : " << rmin << std::endl;
  std::cout << " min (const ref)     : " << cmin << std::endl;
  std::cout << " max (non-const ref) : " << rmax << std::endl;
  std::cout << " max (const ref)     : " << cmax << std::endl;

  std::cout << std::endl
            << "========================================" << std::endl;
  std::cout << "                 End of Demo" << std::endl;
  std::cout << "========================================" << std::endl;

  return 0;
}
