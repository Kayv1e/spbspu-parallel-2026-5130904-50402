#include "pipe.hpp"
#include <memory>
#include <unistd.h>
#include <utility>
#include <system_error>

novikov::UniqueFd::UniqueFd(int fd) noexcept:
  fd_(fd)
{}

novikov::UniqueFd::UniqueFd(UniqueFd&& other) noexcept:
  fd_(other.fd_)
{
  other.fd_ = -1;
}

novikov::UniqueFd& novikov::UniqueFd::operator=(UniqueFd&& other) noexcept
{
  if (this != std::addressof(other))
  {
    std::swap(fd_, other.fd_);
  }
  return *this;
}

novikov::UniqueFd::~UniqueFd()
{
  if (fd_ != -1)
  {
    ::close(fd_);
  }
}

int novikov::UniqueFd::get() const noexcept
{
  return fd_;
}

novikov::Pipe::Pipe()
{
  int pps[2] = {}, err = ::pipe(pps);

  if (err)
  {
    throw std::system_error(errno, std::generic_category(), "pipe error");
  }

  read = UniqueFd(pps[0]);
  write = UniqueFd(pps[1]);
}
