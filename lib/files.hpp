#pragma once

#include <exception>
#include <fstream>
#include <stdexcept>
#include <string>

namespace lib {

enum status { read, write, all };
enum write_status { overwrite, normal };

class file {
  std::string file_name;
  status status;

public:
  file(std::string file_name, enum status status)
      : file_name(file_name), status(status) {}

  std::string read() {
    if (this->status == status::write)
      throw std::invalid_argument("Unable to read a write-only file");

    std::string buffer;
    std::string file_text;

    std::ifstream file(this->file_name);

    while (std::getline(file, buffer)) {
      file_text += buffer;
    }

    return file_text;
  }

  void write(std::string text, enum write_status status) {
    if (this->status == status::read)
      throw std::invalid_argument("Unable to write a read-only file");

    if (status == write_status::overwrite)
      std::ofstream(this->file_name).write(text.c_str(), text.size());
    else
      std::ofstream(this->file_name, std::ios::app)
          .write(text.c_str(), text.size());
  }
};
} // namespace lib
