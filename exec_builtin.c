#include "shell.h"

int	exec_builtin(char **args)
{
	char	*cmd = args[0];

	if (!cmd)
		return (0);
	else if (!_strncmp("env", cmd, _strlen("env") + 1))
	{
		write(1, "built in: env\n", _strlen("built in: env\n"));
		return (1);
	}
	else if (!_strncmp("cd", cmd, _strlen("cd") + 1))
	{
		write(1, "built in: cd\n", _strlen("built in: cd\n"));
		return (1);
	}
	else if (!_strncmp("exit", cmd, _strlen("exit") + 1))
	{
		write(1, "built in: exit\n", _strlen("built in: exit\n"));
		return (1);
	}
	else if (!_strncmp("setenv", cmd, _strlen("setenv") + 1))
	{
		write(1, "built in: setenv\n", _strlen("built in: setenv\n"));
		return (1);
	}
	else if (!_strncmp("unsetenv", cmd, _strlen("unsetenv") + 1))
	{
		write(1, "built in: unsetenv\n", _strlen("built in: unsetenv\n"));
		return (1);
	}
	else if (!_strncmp("alias", cmd, _strlen("alias") + 1))
	{
		write(1, "built in: alias\n", _strlen("built in: alias\n"));
		return (1);
	}
	return (0);
}
