#include "shell.h"

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
		_exit(args);
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
