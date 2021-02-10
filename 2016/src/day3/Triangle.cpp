#include "day3/Triangle.hpp"


Triangle::Triangle(int na, int nb, int nc) : a(na), b(nb), c(nc)
{}

Triangle::operator bool() const{
  return a + b > c && a + c > b && b + c > a;
}