#pragma once

#include <stdexcept>
#include <string>

namespace lib {

enum status { read, write, all };

class file {
  std::string file_name;
  status status;

public:
  file(std::string file_name, enum status status)
      : file_name(file_name), status(status) {}

  std::string read() {
    if (this->status = status::write)
      throw std::invalid_argument("Cannot read write-only file");
  }
};
} // namespace lib
