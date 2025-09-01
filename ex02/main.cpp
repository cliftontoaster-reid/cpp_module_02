#include "Point.hpp"
#include <iostream>

// prototype for bsp
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
  std::cout << "==========================================" << std::endl;
  std::cout << "   Point-in-Triangle (BSP) Demo" << std::endl;
  std::cout << "==========================================" << std::endl;
  std::cout << std::endl;

  // Define the triangle
  Point a(0.0f, 0.0f);
  Point b(10.0f, 0.0f);
  Point c(0.0f, 10.0f);

  std::cout << "Triangle vertices:" << std::endl;
  std::cout << "  A: (" << a.getX().toFloat() << ", " << a.getY().toFloat()
            << ")" << std::endl;
  std::cout << "  B: (" << b.getX().toFloat() << ", " << b.getY().toFloat()
            << ")" << std::endl;
  std::cout << "  C: (" << c.getX().toFloat() << ", " << c.getY().toFloat()
            << ")" << std::endl;
  std::cout << std::endl;

  // Test points
  Point p1(1.0f, 1.0f);   // inside
  Point p2(5.0f, 0.0f);   // on edge
  Point p3(0.0f, 0.0f);   // vertex
  Point p4(10.0f, 10.0f); // outside

  // Test p1
  std::cout << "Testing point P1: (" << p1.getX().toFloat() << ", "
            << p1.getY().toFloat() << ") - should be INSIDE the triangle."
            << std::endl;
  bool result1 = bsp(a, b, c, p1);
  std::cout << "  Result: "
            << (result1 ? "YES, it's inside!" : "NO, it's not inside.")
            << std::endl;
  std::cout << std::endl;

  // Test p2
  std::cout << "Testing point P2: (" << p2.getX().toFloat() << ", "
            << p2.getY().toFloat() << ") - on the EDGE of the triangle."
            << std::endl;
  bool result2 = bsp(a, b, c, p2);
  std::cout << "  Result: "
            << (result2 ? "YES, it's inside!"
                        : "NO, it's not inside (on edge).")
            << std::endl;
  std::cout << std::endl;

  // Test p3
  std::cout << "Testing point P3: (" << p3.getX().toFloat() << ", "
            << p3.getY().toFloat() << ") - at a VERTEX of the triangle."
            << std::endl;
  bool result3 = bsp(a, b, c, p3);
  std::cout << "  Result: "
            << (result3 ? "YES, it's inside!"
                        : "NO, it's not inside (at vertex).")
            << std::endl;
  std::cout << std::endl;

  // Test p4
  std::cout << "Testing point P4: (" << p4.getX().toFloat() << ", "
            << p4.getY().toFloat() << ") - OUTSIDE the triangle." << std::endl;
  bool result4 = bsp(a, b, c, p4);
  std::cout << "  Result: "
            << (result4 ? "YES, it's inside!" : "NO, it's not inside.")
            << std::endl;
  std::cout << std::endl;

  std::cout << "==========================================" << std::endl;
  std::cout << "   Demo complete! BSP function tested." << std::endl;
  std::cout << "==========================================" << std::endl;

  return 0;
}