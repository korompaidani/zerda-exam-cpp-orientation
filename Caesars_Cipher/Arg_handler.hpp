#pragma once
#include <vector>
#include <string>
#include <iostream>

class Arg_handler {
private:
  std::vector<std::string> my_argvs;
public:
  Arg_handler(int, char**);
  std::vector<std::string> get_my_argvs();
  ~Arg_handler();
};

