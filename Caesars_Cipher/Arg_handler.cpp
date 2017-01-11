#include "Arg_handler.hpp"



Arg_handler::Arg_handler(int argc, char** argv) {
  this->my_argvs.resize(argc);
  for (int i = 0; i < argc; i++) {
    my_argvs[i] = argv[i];
  }
}

std::vector<std::string> Arg_handler::get_my_argvs() {
  return this->my_argvs;
}


Arg_handler::~Arg_handler() {
}
