#ifndef AREA_HPP
#define AREA_HPP
#include <cstddef>
#include <utility>
#include <vector>
#include "shapes.hpp"

namespace novikov
{
  std::vector< Circle > readInput(Polygon &pg);
  std::pair< std::size_t, std::size_t > calculate(const std::vector< Circle > &figures, const Polygon &pg, std::size_t tries, int seed);
  std::size_t countInside(const std::vector< Circle > &figures, double x, double y);
  std::pair< double, double > area(const std::vector< Circle > &figures, const Polygon &pg, std::size_t threads, std::size_t tries, int seed);
}

#endif
