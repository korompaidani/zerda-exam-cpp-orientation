#pragma once
#include <fstream>
#include <string>
#include <iostream>

class File_handler {
private:
  std::string buffer;
public:
  File_handler();
  bool read_file_to_buffer(std::string);
  bool write_buffer_to_file(std::string);
  std::string get_buffer();
  ~File_handler();
};

