#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << "----------- Subject main tests -----------" << std::endl;
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << "----------------------------------------" << std::endl;
  std::cout << std::endl;

  std::cout << "----------- My tests -----------" << std::endl;
  Fixed val1(10);
  Fixed val2(20);
  Fixed val3(10);

  // Comparison operators
  std::cout << "--- Comparison operators ---" << std::endl;
  std::cout << "val1(10) > val2(20): " << (val1 > val2) << std::endl;
  std::cout << "val1(10) < val2(20): " << (val1 < val2) << std::endl;
  std::cout << "val1(10) >= val3(10): " << (val1 >= val3) << std::endl;
  std::cout << "val1(10) <= val3(10): " << (val1 <= val3) << std::endl;
  std::cout << "val1(10) == val2(20): " << (val1 == val2) << std::endl;
  std::cout << "val1(10) == val3(10): " << (val1 == val3) << std::endl;
  std::cout << "val1(10) != val2(20): " << (val1 != val2) << std::endl;
  std::cout << "val1(10) != val3(10): " << (val1 != val3) << std::endl;
  std::cout << "----------------------------" << std::endl;
  std::cout << std::endl;

  // Arithmetic operators
  std::cout << "--- Arithmetic operators ---" << std::endl;
  Fixed res_add = val1 + val2;
  Fixed res_sub = val2 - val1;
  Fixed res_mul = Fixed(2.5f) * Fixed(2);
  Fixed res_div = Fixed(10.0f) / Fixed(2);
  std::cout << "val1(10) + val2(20) = " << res_add << std::endl;
  std::cout << "val2(20) - val1(10) = " << res_sub << std::endl;
  std::cout << "Fixed(2.5f) * Fixed(2) = " << res_mul << std::endl;
  std::cout << "Fixed(10.0f) / Fixed(2) = " << res_div << std::endl;
  std::cout << "----------------------------" << std::endl;
  std::cout << std::endl;

  // Increment/Decrement operators
  std::cout << "--- Increment/Decrement operators ---" << std::endl;
  Fixed c(5);
  std::cout << "c is " << c << std::endl;
  std::cout << "++c is " << ++c << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "c++ is " << c++ << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "--c is " << --c << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "c-- is " << c-- << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << std::endl;

  // Min/Max functions
  std::cout << "--- Min/Max functions ---" << std::endl;
  Fixed v1(10);
  Fixed v2(20);
  const Fixed cv1(10);
  const Fixed cv2(20);

  std::cout << "min(v1, v2): " << Fixed::min(v1, v2) << std::endl;
  std::cout << "max(v1, v2): " << Fixed::max(v1, v2) << std::endl;
  std::cout << "min(cv1, cv2): " << Fixed::min(cv1, cv2) << std::endl;
  std::cout << "max(cv1, cv2): " << Fixed::max(cv1, cv2) << std::endl;
  std::cout << "---------------------------" << std::endl;

  return 0;
}