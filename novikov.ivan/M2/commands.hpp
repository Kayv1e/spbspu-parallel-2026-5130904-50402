#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <iostream>
#include <string>
#include <unordered_map>
#include "ellipse.hpp"

namespace novikov
{
  using ellipse_map = std::unordered_map< std::string, Ellipse >;

  void circle(std::istream& in, std::ostream&, ellipse_map& ellipses);
  void set(std::istream&, std::ostream&, ellipse_map&);
  void show(std::istream& in, std::ostream& out, ellipse_map& ellipses);
  void showset(std::istream&, std::ostream&, ellipse_map&);
  void frame(std::istream&, std::ostream&, ellipse_map&);
  void frameset(std::istream&, std::ostream&, ellipse_map&);
  void spawn(std::istream&, std::ostream&, ellipse_map&);
  void area_on(std::istream&, std::ostream&, ellipse_map&);
  void status(std::istream&, std::ostream&, ellipse_map&);
  void wait(std::istream&, std::ostream&, ellipse_map&);
}

#endif
