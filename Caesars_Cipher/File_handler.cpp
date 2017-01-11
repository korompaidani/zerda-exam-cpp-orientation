#include "File_handler.hpp"

File_handler::File_handler() {
}

bool File_handler::read_file_to_buffer(std::string filename) {
  std::ifstream my_file;
  std::string line;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
    return false;
  }
  else {
    while (getline(my_file, line)) {
      this->buffer += line + '\n';
    }
    my_file.close();
  }
  return true;
}

bool File_handler::write_buffer_to_file(std::string filename) {
  std::ofstream my_file;
  my_file.open(filename.c_str());
  if (!my_file.is_open()) {
    return false;
  }
  else {
    my_file << this->buffer;
    my_file.close();
    return true;
  }
}

std::string File_handler::get_buffer() {
  return this->buffer;
}


File_handler::~File_handler()
{
}
