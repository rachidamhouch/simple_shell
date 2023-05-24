#include "shell.h"

/**
*exec_builtin - run built-in command.
*@args: arg 1.
*@global:arg 2.
* Return: 1 if the command is a built-in.
*/
int	exec_builtin(char **args, global_t *global)
{
	char	*cmd = args[0];

	if (!cmd)
		return (0);
	else if (!_strncmp("env", cmd, _strlen("env") + 1))
	{
		env(args, global);
		return (1);
	}
	else if (!_strncmp("cd", cmd, _strlen("cd") + 1))
	{
		cd(args, global);
		return (1);
	}
	else if (!_strncmp("exit", cmd, _strlen("exit") + 1))
	{
		my_exit(args, global);
		return (1);
	}
	else if (!_strncmp("setenv", cmd, _strlen("setenv") + 1))
	{
		_setenv(args, global);
		return (1);
	}
	else if (!_strncmp("unsetenv", cmd, _strlen("unsetenv") + 1))
	{
		_unsetenv(args, global);
		return (1);
	}
	else if (!_strncmp("alias", cmd, _strlen("alias") + 1))
	{
		_alias(args, global);
		return (1);
	}
	return (0);
}
