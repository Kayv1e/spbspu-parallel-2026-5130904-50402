#include "child.hpp"
#include "area.hpp"
#include "ellipse.hpp"

void novikov::child_process(DuplexChannel channel, size_t seed)
{
  while (true)
  {
    size_t size = 0;
    channel.read(&size, sizeof(size));

    ellipse_list ellipses(size);
    channel.read(ellipses.data(), static_cast< ssize_t >(size * sizeof(Ellipse)));

    size_t threads = 0, tries = 0;
    channel.read(&threads, sizeof(threads));
    channel.read(&tries, sizeof(tries));

    const double res = novikov::area(ellipses, threads, tries, seed).first;

    channel.write(&res, sizeof(res));
  }
}
