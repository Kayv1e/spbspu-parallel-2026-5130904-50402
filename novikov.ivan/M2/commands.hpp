#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>

namespace novikov
{
  void circle(std::istream&, std::ostream&);
  void set(std::istream&, std::ostream&);
  void show(std::istream&, std::ostream&);
  void showset(std::istream&, std::ostream&);
  void frame(std::istream&, std::ostream&);
  void frameset(std::istream&, std::ostream&);
  void spawn(std::istream&, std::ostream&);
  void area_on(std::istream&, std::ostream&);
  void status(std::istream&, std::ostream&);
  void wait(std::istream&, std::ostream&);
}

#endif
