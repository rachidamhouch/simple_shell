#include "shell.h"


/**
 * my_exit - built-in, that exits the shell
 * @line: Line buffer of user input
 * @args: Arguments from user
 * @cmd: Environment
 * Return: Void
 */

void my_exit(char **args ; char *line , char **cmd )
{
	free(args);
	free(line);
	(void)cmd;
	exit(0);
}
