#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
  // Test case 1: Simple triangle with point inside
  std::cout << "=== Test Case 1: Point inside triangle ===" << std::endl;
  Point a1(0.0f, 0.0f);
  Point b1(10.0f, 0.0f);
  Point c1(5.0f, 10.0f);
  Point p1(5.0f, 5.0f);
  std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
  std::cout << "Point: P(5,5)" << std::endl;
  std::cout << "Result: " << (bsp(a1, b1, c1, p1) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  // Test case 2: Point outside triangle
  std::cout << "=== Test Case 2: Point outside triangle ===" << std::endl;
  Point a2(0.0f, 0.0f);
  Point b2(10.0f, 0.0f);
  Point c2(5.0f, 10.0f);
  Point p2(15.0f, 5.0f);
  std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
  std::cout << "Point: P(15,5)" << std::endl;
  std::cout << "Result: " << (bsp(a2, b2, c2, p2) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  // Test case 3: Point on vertex (should be OUTSIDE)
  std::cout << "=== Test Case 3: Point on vertex ===" << std::endl;
  Point a3(0.0f, 0.0f);
  Point b3(10.0f, 0.0f);
  Point c3(5.0f, 10.0f);
  Point p3(0.0f, 0.0f);
  std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
  std::cout << "Point: P(0,0) [on vertex A]" << std::endl;
  std::cout << "Result: " << (bsp(a3, b3, c3, p3) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  // Test case 4: Point on edge (should be OUTSIDE)
  std::cout << "=== Test Case 4: Point on edge ===" << std::endl;
  Point a4(0.0f, 0.0f);
  Point b4(10.0f, 0.0f);
  Point c4(5.0f, 10.0f);
  Point p4(5.0f, 0.0f);
  std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
  std::cout << "Point: P(5,0) [on edge AB]" << std::endl;
  std::cout << "Result: " << (bsp(a4, b4, c4, p4) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  // Test case 5: Point inside with different triangle orientation
  std::cout << "=== Test Case 5: Point inside (different orientation) ==="
            << std::endl;
  Point a5(0.0f, 0.0f);
  Point b5(5.0f, 10.0f);
  Point c5(10.0f, 0.0f);
  Point p5(5.0f, 3.0f);
  std::cout << "Triangle: A(0,0) B(5,10) C(10,0)" << std::endl;
  std::cout << "Point: P(5,3)" << std::endl;
  std::cout << "Result: " << (bsp(a5, b5, c5, p5) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  // Test case 6: Point outside but in bounding box
  std::cout << "=== Test Case 6: Point outside (in bounding box) ==="
            << std::endl;
  Point a6(0.0f, 0.0f);
  Point b6(10.0f, 0.0f);
  Point c6(5.0f, 10.0f);
  Point p6(1.0f, 8.0f);
  std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
  std::cout << "Point: P(1,8)" << std::endl;
  std::cout << "Result: " << (bsp(a6, b6, c6, p6) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  // Test case 7: Point inside with floating-point coordinates
  std::cout << "=== Test Case 7: Floating-point coordinates ===" << std::endl;
  Point a7(0.5f, 0.5f);
  Point b7(9.5f, 0.5f);
  Point c7(5.0f, 9.5f);
  Point p7(5.0f, 4.5f);
  std::cout << "Triangle: A(0.5,0.5) B(9.5,0.5) C(5,9.5)" << std::endl;
  std::cout << "Point: P(5,4.5)" << std::endl;
  std::cout << "Result: " << (bsp(a7, b7, c7, p7) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  // Test case 8: Point on edge with floating-point (should be OUTSIDE)
  std::cout << "=== Test Case 8: Point on edge (floating-point) ==="
            << std::endl;
  Point a8(0.0f, 0.0f);
  Point b8(10.0f, 0.0f);
  Point c8(5.0f, 10.0f);
  Point p8(7.5f, 5.0f);
  std::cout << "Triangle: A(0,0) B(10,0) C(5,10)" << std::endl;
  std::cout << "Point: P(7.5,5) [on edge BC]" << std::endl;
  std::cout << "Result: " << (bsp(a8, b8, c8, p8) ? "INSIDE" : "OUTSIDE")
            << std::endl
            << std::endl;

  return 0;
}