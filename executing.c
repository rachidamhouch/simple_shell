#include "shell.h"

void	exec_binary(command_t *command)
{
	write(1, command->args[0], _strlen(command->args[0]));
	write(1, ": ", 2);
	if (command->path)
		write(1, command->path, _strlen(command->path));
	else
		write(1, "command not found", _strlen("command not found"));
	write(1, "\n", 1);
}

void	executing(void)
{
	command_t *tmp = global.commands;

	while (tmp)
	{
		if (!exec_builtin(tmp->args))
			exec_binary(tmp);
		tmp = tmp->next;
	}
}
