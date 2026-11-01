#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <unordered_map>

int main()
{
  using cmd_t = void (*)(std::istream&, std::ostream&);
  std::unordered_map< std::string, cmd_t > cmds;

  std::string cmd;
  while (std::cin >> cmd)
  {
    try
    {
      cmds.at(cmd)(std::cin, std::cout);
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
