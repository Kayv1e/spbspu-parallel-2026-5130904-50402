#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include "commands.hpp"

int main()
{
  novikov::ellipse_map circles;
  novikov::set_map sets;

  using cmd_t = void (*)(std::istream&, std::ostream&, novikov::ellipse_map&, novikov::set_map&);
  std::unordered_map< std::string, cmd_t > cmds;

  cmds["circle"] = novikov::circle;
  cmds["ellipse"] = novikov::ellipse;
  cmds["set"] = novikov::set;
  cmds["show"] = novikov::show;
  cmds["showset"] = novikov::showset;
  // cmds["frame"] = novikov::frame;
  // cmds["frameset"] = novikov::frameset;
  // cmds["spawn"] = novikov::spawn;
  // cmds["area-on"] = novikov::area_on;
  // cmds["status"] = novikov::status;
  // cmds["wait"] = novikov::wait;

  std::string cmd;
  while (std::cin >> cmd)
  {
    try
    {
      cmds.at(cmd)(std::cin, std::cout, circles, sets);
    }
    catch (const std::out_of_range&)
    {
      std::cout << "<UNKNOWN COMMAND>\n";
      auto toIgnore = std::numeric_limits< std::streamsize >::max();
      std::cin.ignore(toIgnore, '\n');
    }
    catch (...)
    {
      std::cout << "<INVALID COMMAND>\n";
      auto toIgnore = std::numeric_limits< std::streamsize >::max();
      std::cin.ignore(toIgnore, '\n');
    }
  }
  if (!std::cin.eof())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }
}
