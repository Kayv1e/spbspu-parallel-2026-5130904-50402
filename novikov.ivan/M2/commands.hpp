#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "ellipse.hpp"

namespace novikov
{
  using ellipse_map = std::unordered_map< std::string, Ellipse >;
  using set_map = std::unordered_map< std::string, std::vector< Ellipse > >;

  void circle(std::istream& in, std::ostream&, ellipse_map& ellipses, set_map&);
  void ellipse(std::istream& in, std::ostream&, ellipse_map& ellipses, set_map&);
  void set(std::istream& in, std::ostream&, ellipse_map& ellipses, set_map& sets);
  void show(std::istream& in, std::ostream& out, ellipse_map& ellipses, set_map&);
  void showset(std::istream& in, std::ostream& out, ellipse_map&, set_map& sets);
  void frame(std::istream&, std::ostream&, ellipse_map&, set_map&);
  void frameset(std::istream&, std::ostream&, ellipse_map&, set_map&);
  void spawn(std::istream&, std::ostream&, ellipse_map&, set_map&);
  void area_on(std::istream&, std::ostream&, ellipse_map&, set_map&);
  void status(std::istream&, std::ostream&, ellipse_map&, set_map&);
  void wait(std::istream&, std::ostream&, ellipse_map&, set_map&);
}

#endif
