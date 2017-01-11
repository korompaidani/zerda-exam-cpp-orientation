#pragma once
#include "Arg_handler.hpp"
#include "File_handler.hpp"
#include "Commands.hpp"
#include <string>
#include <iostream>

class Handler {
private:
  std::string input_filename;
  std::string output_filename;
  std::string shift_num_in_str;
  int shift_num;
  std::string my_buffer;
  
  Arg_handler* argh;
  File_handler* filhandl;
  Commands* cmds;
public:
  Handler(int, char**);
  bool is_command_first_tag_valid(std::string);
  void run();
  ~Handler();
};

