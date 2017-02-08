#include "tsh.h"
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

void simple_shell::parse_command(char* cmd, char** cmdTokens) {
  // TODO: tokenize the command string into arguments
  // printf("Command I enter is %s\n",cmd);
  istringstream iss(cmd);
  string token;
  int index = 0;
  while(iss>>skipws>>token) {
    cmdTokens[index] = new char[token.length() + 1];
    strcpy(cmdTokens[index], token.c_str());
    index += 1;
  }
  // printf("%s\n",*cmdTokens);
}

void simple_shell::exec_command(char **argv)
{
  char **temp = argv;
  while(*temp != NULL) {
    printf("%s\n",*temp);
    temp++;
  }
  // TODO: fork a child process to execute the command.
  // parent process should wait for the child process to complete and reap it
}

bool simple_shell::isQuit(char *cmd){
  // TODO: check for the command "quit" that terminates the shell
  // std::cout << cmd << '\n';
  if (strcmp(cmd,"quit") == 0) {
    // std::cout << "Quit got!" << '\n';
    return true;
  } else {
    return false;
  }
}
