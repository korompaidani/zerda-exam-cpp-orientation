#include "Handler.hpp"

Handler::Handler(int argc, char** argv) {
  this->argh = new Arg_handler(argc, argv);
  this->filhandl = new File_handler;
  this->cmds = new Commands;
}

bool Handler::is_command_first_tag_valid(std::string command) {
  if (command.length() < 2) {
    return false;
  }
  else if (command[0] != '-') {
    return false;
  }
  else if (command[1] != 's') {
    return false;
  }
  return true;
}

void Handler::run() {
  this->input_filename = argh->get_my_argvs()[1];
  this->shift_num = int(argh->get_my_argvs()[3][0]);
  this->output_filename = argh->get_my_argvs()[5];
  
  if (argh->get_my_argvs()[2] == "-s" && argh->get_my_argvs()[4] == "-o") {
    filehandl->read_file_to_buffer(input_filename);
    cmds->decode_string_with_shift(filehandl->get_buffer(), this->shift_num);
    this->my_buffer = cmds->read_file_to_buffer(input_filename);
    this->cmds->write_buffer_to_file(this->my_buffer);
  }
  
  //input.txt -s 2 -o output.txt sorry time is out and this work with only this constellation

}

Handler::~Handler()
{
  delete argh;
  delete filhandl;
  delete cmds;
}
