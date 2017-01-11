#pragma once
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>

class Commands {
private:
  std::string buffer;
public:
  Commands();
  std::string decode_string_with_shift(std::string, int);
  std::string get_buffer();
  ~Commands();
};

