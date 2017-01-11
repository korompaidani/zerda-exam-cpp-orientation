#pragma once
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>

class Commands {
public:
  Commands();
  std::string decode_string_with_shift(std::string, int);
  ~Commands();
};

