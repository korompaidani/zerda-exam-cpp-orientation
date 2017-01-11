#include "Commands.hpp"

unsigned int only_alpha_u(unsigned int number) {
  unsigned int min = 65;
  unsigned int max = 90;
  if (number > max) {
    number = number - max + min;
  }
  if (number < min) {
    number = max - (min - number);
  }
  return number;
}

unsigned int only_alpha_d(unsigned int number) {
  unsigned int min = 97;
  unsigned int max = 122;
  if (number > max) {
    number = number - max + min;
  }
  if (number < min) {
    number = max - (min - number);
  }
  return number;
}

Commands::Commands() {
}

std::string Commands::decode_string_with_shift(std::string input, int shift) {
  std::string temp_str = input;
  unsigned short int temp_num = 0;
  int length = temp_str.length();
  for (int i = 0; i < length; i++) {
    char temp_char = temp_str[i];
    if (!isalpha(temp_char)) {
      temp_num = (int)temp_char;
      std::cout << "not_alpha temp_num = " << temp_num << std::endl;
      temp_str[i] = (char)temp_num;
      continue;
    }
    else if (isupper(temp_char)) {
      temp_num = only_alpha_u((int)temp_char + shift);
      std::cout << "isupper temp_num = " << temp_num << std::endl;
      temp_str[i] = (char)temp_num;
      continue;
    }
    else if (!isupper(temp_char)) {
      temp_num = only_alpha_d((int)temp_char + shift);
      std::cout << "NOTupper temp_num = " << temp_num << std::endl;
      temp_str[i] = (char)temp_num;
      continue;
    }
    //temp_str[i] = (char)temp_num;
  }
  return temp_str;
}

std::string Commands::get_buffer() {
  return this->buffer;
}


Commands::~Commands()
{
}
