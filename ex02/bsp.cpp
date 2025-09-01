#include "Point.hpp"

// Static helper function for cross product
static Fixed crossProduct(Fixed qx, Fixed qy, Fixed rx, Fixed ry, Fixed sx,
                          Fixed sy) {
  // (r - q) x (s - q) = (rx - qx)*(sy - qy) - (ry - qy)*(sx - qx)
  return (rx - qx) * (sy - qy) - (ry - qy) * (sx - qx);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  // Use Fixed arithmetic and cross products to determine if the point is
  // strictly inside the triangle (not on edges). For points A,B,C and P,
  // compute signed areas via cross products:
  // sign1 = (P - A) x (B - A)
  // sign2 = (P - B) x (C - B)
  // sign3 = (P - C) x (A - C)
  // If all signs are > 0 or all < 0 then P is strictly inside. If any
  // sign == 0 the point is on an edge -> return false (strict inside only).

  Fixed ax = a.getX();
  Fixed ay = a.getY();
  Fixed bx = b.getX();
  Fixed by = b.getY();
  Fixed cx = c.getX();
  Fixed cy = c.getY();
  Fixed px = point.getX();
  Fixed py = point.getY();

  // Check triangle degeneracy: area = (B-A) x (C-A)
  Fixed area = crossProduct(ax, ay, bx, by, cx, cy);
  if (area == Fixed(0))
    return false; // Degenerate triangle

  Fixed s1 = crossProduct(ax, ay, bx, by, px, py); // (B-A) x (P-A)
  Fixed s2 = crossProduct(bx, by, cx, cy, px, py); // (C-B) x (P-B)
  Fixed s3 = crossProduct(cx, cy, ax, ay, px, py); // (A-C) x (P-C)

  // If any are zero -> on edge -> not strictly inside
  if (s1 == Fixed(0) || s2 == Fixed(0) || s3 == Fixed(0))
    return false;

  bool has_neg = (s1 < Fixed(0)) || (s2 < Fixed(0)) || (s3 < Fixed(0));
  bool has_pos = (s1 > Fixed(0)) || (s2 > Fixed(0)) || (s3 > Fixed(0));

  return !(has_neg && has_pos);
}