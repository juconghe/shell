#include "tsh.h"

using namespace std;

int main(){
	char cmd[81];
	char *cmdTokens[25];// array of string
	simple_shell *shell = new simple_shell();

	while (true){
		cout << "tsh> ";
		fgets(cmd, sizeof(cmd), stdin);
		// printf("input is %s\n",cmd);
		if (cmd[0] == '\n') continue;
		shell->parse_command(cmd, cmdTokens);
		if (shell->isQuit(*cmdTokens)){
			// std::cout << "Exiting " << '\n';
			exit(0);
		}
		else{
			shell->exec_command(cmdTokens);
		}

	}
	exit(1);
}
