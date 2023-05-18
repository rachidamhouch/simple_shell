#include "shell.h"

/**
*exec_builtin - Execute built-in command
*@args: Array of command arguments
*Description: Executes the built-in command specified by the arguments.
* Handles each built-in command separately and returns 1 if
* the command is a built-in, or 0 if it is not.
* Return: 1 if the command is a built-in or  0 
*/
int	exec_builtin(char **args)
{
	char	*cmd = args[0];

	if (!cmd)
		return (0);
	else if (!_strncmp("env", cmd, _strlen("env") + 1))
	{
		env(args);
		return (1);
	}
	else if (!_strncmp("cd", cmd, _strlen("cd") + 1))
	{
		cd(args);
		return (1);
	}
	else if (!_strncmp("exit", cmd, _strlen("exit") + 1))
	{
		my_exit(args);
		return (1);
	}
	else if (!_strncmp("setenv", cmd, _strlen("setenv") + 1))
	{
		write(1, "setenv: built in\n", _strlen("setenv: built in\n"));
		return (1);
	}
	else if (!_strncmp("unsetenv", cmd, _strlen("unsetenv") + 1))
	{
		write(1, "unsetenv: built in\n", _strlen("unsetenv: built in\n"));
		return (1);
	}
	else if (!_strncmp("alias", cmd, _strlen("alias") + 1))
	{
		write(1, "alias: built in\n", _strlen("alias: built in\n"));
		return (1);
	}
	return (0);
}
