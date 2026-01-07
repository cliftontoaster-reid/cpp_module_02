#pragma once

#include "Fixed.hpp"

class Point {
 private:
  Fixed const x;
  Fixed const y;

 public:
  Point();
  Point(const float x, const float y);
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();

  Fixed getX() const { return x; }
  Fixed getY() const { return y; }
};
