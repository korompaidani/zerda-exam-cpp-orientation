#include "waste\stdafx.h"
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Arg_handler.hpp"
#include "File_handler.hpp"
#include "Commands.hpp"

using namespace std;

#ifdef CATCH_CONFIG_MAIN

int main(int argc, char* argv[]) {
  Commands cmds;
  cout << cmds.decode_string_with_shift("a Dd1", 1) << endl;
  return 0;
}

#endif

#ifndef CATCH_CONFIG_MAIN
#include "C:\Users\korom\OneDrive\Programming\TEST\catch.hpp"

TEST_CASE("arg handler constructor test char** to vector <string>") {
  int argc = 3;
  char* argv[3];

  argv[0] = "first";
  argv[1] = "second";
  argv[2] = "third";

  Arg_handler argh(argc, argv);
  
  CHECK(argh.get_my_argvs()[0] == "first");
}

TEST_CASE("file reading test") {
  File_handler fh;
  CHECK(fh.read_file_to_buffer("try.txt"));
}

TEST_CASE("get file buffer test without check, only print") {
  File_handler fh;
  fh.read_file_to_buffer("try.txt");
  std::cout << "buffer:" << std::endl << fh.get_buffer();
}

TEST_CASE("write to file") {
  File_handler fh;
  fh.read_file_to_buffer("try.txt");
  CHECK(fh.write_buffer_to_file("try_out.txt"));
}

TEST_CASE("Command decode test") {
  Commands cmds;
  cout << cmds.decode_string_with_shift("abcd", 1) << endl;
  //CHECK(fh.write_buffer_to_file("try_out.txt"));
}
#endif