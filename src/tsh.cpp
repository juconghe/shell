#include "tsh.h"
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

void cleanBuffer(char **buffer) {
  // std::cout << "Cleaning buffer" << '\n';
  for (unsigned int i = 0; i < 25; i++) {
    buffer[i] = NULL;
  }
}
void simple_shell::parse_command(char* cmd, char** cmdTokens) {
  // TODO: tokenize the command string into arguments
  // printf("Command I enter is %s\n",cmd);
  istringstream iss(cmd);
  string token;
  int index = 0;
  while(iss>>skipws>>token) {
    cmdTokens[index] = new char[token.length()];
    strcpy(cmdTokens[index], token.c_str());
    index += 1;
  }
  // printf("%s\n",*cmdTokens);
}

void simple_shell::exec_command(char **argv)
{
  // TODO: fork a child process to execute the command.
  // parent process should wait for the child process to complete and reap it
  if (fork() == 0) {
    if (execvp(*argv, argv) == -1) {
      // printf("can't execute command %s\n",*argv);
      cleanBuffer(argv);
    } else {
      execvp(*argv, argv);
    }
  } else {
    wait(NULL);
    cleanBuffer(argv);
  }
}

bool simple_shell::isQuit(char *cmd){
  // TODO: check for the command "quit" that terminates the shell
  // std::cout << "Checking quit" << '\n';
  if (strcmp(cmd,"quit") == 0) {
    // std::cout << "Quit got!" << '\n';
    return true;
  } else {
    return false;
  }
}
